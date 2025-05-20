//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of medicines
#define MAX_MEDICINES 100

// Structure to represent a medicine
typedef struct {
    int id;
    char name[50];
    char category[30];
    float price;
    int quantity;
} Medicine;

// Function prototypes
void displayMenu();
void addMedicine(Medicine medicines[], int *count);
void displayMedicines(Medicine medicines[], int count);
void searchMedicine(Medicine medicines[], int count);
void sellMedicine(Medicine medicines[], int count);

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    do {
        displayMenu();
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
                searchMedicine(medicines, count);
                break;
            case 4:
                sellMedicine(medicines, count);
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Sell Medicine\n");
    printf("5. Exit\n");
    printf(" ==========================================\n");
}

void addMedicine(Medicine medicines[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Storage full!\n");
        return;
    }

    Medicine newMed;
    newMed.id = *count + 1;

    printf("Enter medicine name: ");
    scanf("%s", newMed.name);
    printf("Enter category: ");
    scanf("%s", newMed.category);
    printf("Enter price: ");
    scanf("%f", &newMed.price);
    printf("Enter quantity: ");
    scanf("%d", &newMed.quantity);

    medicines[*count] = newMed;
    (*count)++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(Medicine medicines[], int count) {
    if (count == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\nList of Medicines:\n");
    printf("ID\tName\t\tCategory\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].category, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine(Medicine medicines[], int count) {
    char searchName[50];
    int found = 0;

    printf("Enter medicine name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("Medicine found: ID: %d, Name: %s, Category: %s, Price: %.2f, Quantity: %d\n",
                    medicines[i].id, medicines[i].name, medicines[i].category, medicines[i].price, medicines[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void sellMedicine(Medicine medicines[], int count) {
    char sellName[50];
    int quantity, found = 0;

    printf("Enter medicine name to sell: ");
    scanf("%s", sellName);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, sellName) == 0) {
            printf("Current quantity: %d\n", medicines[i].quantity);
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if(quantity > medicines[i].quantity) {
                printf("Not enough quantity available to sell.\n");
            } else {
                medicines[i].quantity -= quantity;
                printf("Sold %d of %s. Remaining quantity: %d\n", quantity, medicines[i].name, medicines[i].quantity);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}