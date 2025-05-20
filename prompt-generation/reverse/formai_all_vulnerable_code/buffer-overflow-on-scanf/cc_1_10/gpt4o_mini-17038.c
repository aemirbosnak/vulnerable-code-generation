//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

// Function to add a new medicine
void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    medicines[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

// Function to display all medicines
void displayMedicines() {
    printf("\n--- Medicine Inventory ---\n");
    if (medicineCount == 0) {
        printf("No medicines in inventory.\n");
        return;
    }

    for (int i = 0; i < medicineCount; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: %.2f\n", 
                i + 1, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to search for a medicine by name
void searchMedicine() {
    char searchName[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("Medicine found! Name: %s, Quantity: %d, Price: %.2f\n", 
                    medicines[i].name, medicines[i].quantity, medicines[i].price);
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

// Function to delete a medicine
void deleteMedicine() {
    char deleteName[NAME_LENGTH];
    printf("Enter medicine name to delete: ");
    scanf("%s", deleteName);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, deleteName) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicines[j] = medicines[j + 1]; // Shift left
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found in inventory. Cannot delete.\n");
}

// Main function to run the program
int main() {
    int choice;

    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                deleteMedicine();
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