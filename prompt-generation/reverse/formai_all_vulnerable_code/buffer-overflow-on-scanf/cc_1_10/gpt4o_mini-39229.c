//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Error: Cannot add more medicines.\n");
        return;
    }
    Medicine med;
    printf("Enter medicine ID: ");
    scanf("%d", &med.id);
    printf("Enter medicine name: ");
    scanf("%s", med.name);
    printf("Enter manufacturer: ");
    scanf("%s", med.manufacturer);
    printf("Enter price: ");
    scanf("%f", &med.price);
    printf("Enter quantity: ");
    scanf("%d", &med.quantity);

    medicines[medicineCount++] = med;
    printf("Medicine added successfully.\n");
}

void updateMedicine() {
    int id, found = 0;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < medicineCount; i++) {
        if (medicines[i].id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf("%s", medicines[i].name);
            printf("Enter new manufacturer: ");
            scanf("%s", medicines[i].manufacturer);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Medicine updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Error: Medicine with ID %d not found.\n", id);
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
                medicines[j] = medicines[j + 1];
            }
            medicineCount--;
            printf("Medicine deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Error: Medicine with ID %d not found.\n", id);
    }
}

void listMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("List of Medicines:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tQuantity\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t\t%s\t%.2f\t%d\n", medicines[i].id, medicines[i].name, medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
    }
}

void menu() {
    int choice;
    do {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Update Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. List Medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: updateMedicine(); break;
            case 3: deleteMedicine(); break;
            case 4: listMedicines(); break;
            case 5: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}