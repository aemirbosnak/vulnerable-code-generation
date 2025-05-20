//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store information about medicines
struct Medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function prototypes
void addMedicine(struct Medicine* meds, int* count);
void displayMedicines(struct Medicine* meds, int count);
void sellMedicine(struct Medicine* meds, int count);
void searchMedicine(struct Medicine* meds, int count);
void updateMedicine(struct Medicine* meds, int count);

int main() {
    struct Medicine medicines[100];
    int count = 0;
    int choice;

    do {
        printf("\n*** Welcome to the Medical Store Management System ***\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Sell Medicine\n");
        printf("4. Search Medicine\n");
        printf("5. Update Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                displayMedicines(medicines, count);
                break;
            case 3:
                sellMedicine(medicines, count);
                break;
            case 4:
                searchMedicine(medicines, count);
                break;
            case 5:
                updateMedicine(medicines, count);
                break;
            case 6:
                printf("Thank you for using the system! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void addMedicine(struct Medicine* meds, int* count) {
    if (*count < 100) {
        printf("Enter ID: ");
        scanf("%d", &meds[*count].id);
        printf("Enter Medicine Name: ");
        scanf("%s", meds[*count].name);
        printf("Enter Price: ");
        scanf("%f", &meds[*count].price);
        printf("Enter Quantity: ");
        scanf("%d", &meds[*count].quantity);
        (*count)++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Medicine list is full!\n");
    }
}

void displayMedicines(struct Medicine* meds, int count) {
    if (count == 0) {
        printf("No medicines available!\n");
        return;
    }
    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("--------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", meds[i].id, meds[i].name, meds[i].price, meds[i].quantity);
    }
}

void sellMedicine(struct Medicine* meds, int count) {
    int id, quantity;
    printf("Enter Medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter Quantity to sell: ");
    scanf("%d", &quantity);

    for (int i = 0; i < count; i++) {
        if (meds[i].id == id) {
            if (meds[i].quantity >= quantity) {
                meds[i].quantity -= quantity;
                printf("Sold %d of %s.\n", quantity, meds[i].name);
                printf("Remaining quantity: %d\n", meds[i].quantity);
            } else {
                printf("Insufficient quantity!\n");
            }
            return;
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine(struct Medicine* meds, int count) {
    char name[50];
    printf("Enter Medicine Name to search: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", meds[i].id, meds[i].name, meds[i].price, meds[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void updateMedicine(struct Medicine* meds, int count) {
    int id;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (meds[i].id == id) {
            printf("Updating details for %s:\n", meds[i].name);
            printf("Enter new Price: ");
            scanf("%f", &meds[i].price);
            printf("Enter new Quantity: ");
            scanf("%d", &meds[i].quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}