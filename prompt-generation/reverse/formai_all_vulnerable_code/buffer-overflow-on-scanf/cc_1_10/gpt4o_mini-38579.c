//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Cannot add more medicines, storage full!\n");
        return;
    }
    
    Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter manufacturer: ");
    scanf("%s", m.manufacturer);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    printf("Enter price: ");
    scanf("%f", &m.price);
    
    medicines[medicineCount] = m;
    medicineCount++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available!\n");
        return;
    }

    printf("List of Medicines:\n");
    printf("---------------------------------------------------\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Manufacturer", "Quantity", "Price");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%-20s %-20s %-10d %-10.2f\n", medicines[i].name, medicines[i].manufacturer,
               medicines[i].quantity, medicines[i].price);
    }
    printf("---------------------------------------------------\n");
}

void updateMedicine() {
    char name[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Update details for %s\n", name);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine details updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < medicineCount - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMenu() {
    printf("===== Medical Store Management System =====\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("=============================================\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewMedicines();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting... Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}