//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char brand[50];
    float price;
    int quantity;
} Medicine;

void addMedicine(Medicine medicines[], int *count) {
    Medicine newMedicine;

    printf("Enter name of medicine: ");
    scanf("%s", newMedicine.name);

    printf("Enter brand of medicine: ");
    scanf("%s", newMedicine.brand);

    printf("Enter price of medicine: ");
    scanf("%f", &newMedicine.price);

    printf("Enter quantity of medicine: ");
    scanf("%d", &newMedicine.quantity);

    medicines[*count] = newMedicine;
    *count += 1;

    printf("\nMedicine added successfully!\n");
}

void displayMedicines(Medicine medicines[], int count) {
    printf("%-50s %-50s %-15s %s\n", "Name", "Brand", "Price", "Quantity");
    for (int i = 0; i < count; i++) {
        printf("%-50s %-50s %-15.2f %d\n", medicines[i].name, medicines[i].brand, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine(Medicine medicines[], int count) {
    char name[50];

    printf("Enter name of medicine: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("\nMedicine found:\n");
            printf("%-50s %-50s %-15s %s\n", "Name", "Brand", "Price", "Quantity");
            printf("%-50s %-50s %-15.2f %d\n", medicines[i].name, medicines[i].brand, medicines[i].price, medicines[i].quantity);
            return;
        }
    }

    printf("\nMedicine not found\n");
}

void updateMedicine(Medicine medicines[], int count) {
    char name[50];

    printf("Enter name of medicine: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("\nEnter new details of medicine:\n");

            printf("Enter brand of medicine: ");
            scanf("%s", medicines[i].brand);

            printf("Enter price of medicine: ");
            scanf("%f", &medicines[i].price);

            printf("Enter quantity of medicine: ");
            scanf("%d", &medicines[i].quantity);

            printf("\nMedicine updated successfully!\n");
            return;
        }
    }

    printf("\nMedicine not found\n");
}

void deleteMedicine(Medicine medicines[], int *count) {
    char name[50];

    printf("Enter name of medicine: ");
    scanf("%s", name);

    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j+1];
            }
            *count -= 1;
            printf("\nMedicine deleted successfully!\n");
            return;
        }
    }

    printf("\nMedicine not found\n");
}

int main() {
    Medicine medicines[100];
    int choice, count = 0;

    while(1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                updateMedicine(medicines, count);
                break;
            case 5:
                deleteMedicine(medicines, &count);
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }

    return 0;
}