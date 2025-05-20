//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Inventory full.\n");
        return;
    }

    Medicine newMedicine;
    newMedicine.id = medicineCount + 1; // Simple ID allocation
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);

    medicines[medicineCount++] = newMedicine;
    printf("Medicine added successfully.\n");
}

void updateMedicine() {
    int id, found = 0;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicines[i].id == id) {
            found = 1;
            printf("Updating medicine %s...\n", medicines[i].name);
            printf("Enter new name: ");
            scanf("%s", medicines[i].name);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Medicine updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Medicine ID not found.\n");
    }
}

void deleteMedicine() {
    int id, found = 0;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicines[i].id == id) {
            found = 1;
            for (int j = i; j < medicineCount - 1; j++) {
                medicines[j] = medicines[j + 1]; // Shift medicines left
            }
            medicineCount--;
            printf("Medicine deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Medicine ID not found.\n");
    }
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\nAvailable Medicines:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
    printf("----------------------------------------\n");
}

void displayMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. View Medicines\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                updateMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                viewMedicines();
                break;
            case 5:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}