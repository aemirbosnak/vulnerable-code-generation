//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    char category[50];
    int quantity;
    float price;
};

// Function prototypes
void addMedicine(struct Medicine[], int*);
void updateMedicine(struct Medicine[], int);
void searchMedicine(struct Medicine[], int);

int main() {
    struct Medicine inventory[50];
    int numMedicines = 0; // Number of medicines currently in the inventory
    int choice; // User's menu choice

    do {
        printf("------ MEDICAL STORE MANAGEMENT SYSTEM ------\n");
        printf("1. Add new medicine\n");
        printf("2. Update medicine details\n");
        printf("3. Search for medicine\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(inventory, &numMedicines);
                break;
            case 2:
                updateMedicine(inventory, numMedicines);
                break;
            case 3:
                searchMedicine(inventory, numMedicines);
                break;
            case 4:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addMedicine(struct Medicine inventory[], int* numMedicines) {
    // Prompt user to enter medicine details
    printf("Enter medicine name: ");
    scanf("%s", inventory[*numMedicines].name);
    printf("Enter medicine category: ");
    scanf("%s", inventory[*numMedicines].category);
    printf("Enter quantity available: ");
    scanf("%d", &inventory[*numMedicines].quantity);
    printf("Enter price per unit: ");
    scanf("%f", &inventory[*numMedicines].price);

    (*numMedicines)++;
    printf("Medicine added successfully.\n");
}

void updateMedicine(struct Medicine inventory[], int numMedicines) {
    char searchName[50];
    int i, option;

    printf("Enter medicine name to update: ");
    scanf("%s", searchName);

    // Search for medicine by name
    for (i = 0; i < numMedicines; i++) {
        if (strcmp(searchName, inventory[i].name) == 0) {
            // Prompt user to choose field to update
            printf("Select field to update:\n");
            printf("1. Category\n");
            printf("2. Quantity\n");
            printf("3. Price\n");
            printf("Enter choice: ");
            scanf("%d", &option);

            switch (option) {
                case 1:
                    printf("Enter new category: ");
                    scanf("%s", inventory[i].category);
                    break;
                case 2:
                    printf("Enter new quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    break;
                case 3:
                    printf("Enter new price: ");
                    scanf("%f", &inventory[i].price);
                    break;
                default:
                    printf("Invalid choice. No fields were updated.\n");
            }

            printf("Medicine details updated successfully.\n");
            return; // Exit function once medicine is found and updated
        }
    }

    printf("Medicine not found. No fields were updated.\n");
}

void searchMedicine(struct Medicine inventory[], int numMedicines) {
    char searchName[50];
    char searchCategory[50];
    int i, option;

    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. Category\n");
    printf("Enter choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter medicine name: ");
            scanf("%s", searchName);

            for (i = 0; i < numMedicines; i++) {
                if (strcmp(searchName, inventory[i].name) == 0) {
                    printf("Medicine found!\n");
                    printf("Name: %s\n", inventory[i].name);
                    printf("Category: %s\n", inventory[i].category);
                    printf("Quantity: %d\n", inventory[i].quantity);
                    printf("Price: %.2f\n", inventory[i].price);
                    return; // Exit function once medicine is found and displayed
                }
            }

            printf("Medicine not found.\n");
            break;
        case 2:
            printf("Enter medicine category: ");
            scanf("%s", searchCategory);

            for (i = 0; i < numMedicines; i++) {
                if (strcmp(searchCategory, inventory[i].category) == 0) {
                    printf("Medicine found!\n");
                    printf("Name: %s\n", inventory[i].name);
                    printf("Category: %s\n", inventory[i].category);
                    printf("Quantity: %d\n", inventory[i].quantity);
                    printf("Price: %.2f\n", inventory[i].price);
                    // Continue searching in case there are more medicines with the same category
                }
            }

            printf("Search complete.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}