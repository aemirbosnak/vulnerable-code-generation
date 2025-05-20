//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char manufacturer[NAME_LENGTH];
    float price;
    int quantity;
} Medicine;

Medicine medicineList[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Unable to add more medicines! Maximum limit reached.\n");
        return;
    }

    Medicine newMedicine;
    newMedicine.id = medicineCount + 1;  // Assign an ID based on current count

    printf("Enter medicine name: ");
    scanf(" %[^\n]s", newMedicine.name); // Reads string with spaces

    printf("Enter manufacturer name: ");
    scanf(" %[^\n]s", newMedicine.manufacturer);

    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);

    medicineList[medicineCount] = newMedicine;
    medicineCount++;

    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\n--- Medicine List ---\n");
    printf("ID\tName\t\tManufacturer\tPrice\tQuantity\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%-15s\t%-15s\t%.2f\t%d\n", 
               medicineList[i].id, 
               medicineList[i].name, 
               medicineList[i].manufacturer, 
               medicineList[i].price, 
               medicineList[i].quantity);
    }
    printf("-------------------------------------------------------\n");
}

void searchMedicine() {
    char searchName[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf(" %[^\n]s", searchName);

    int found = 0;

    for (int i = 0; i < medicineCount; i++) {
        if (strcasecmp(medicineList[i].name, searchName) == 0) {
            printf("\n--- Medicine Details ---\n");
            printf("ID: %d\n", medicineList[i].id);
            printf("Name: %s\n", medicineList[i].name);
            printf("Manufacturer: %s\n", medicineList[i].manufacturer);
            printf("Price: %.2f\n", medicineList[i].price);
            printf("Quantity: %d\n", medicineList[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void deleteMedicine() {
    int id;
    printf("Enter the ID of the medicine to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > medicineCount) {
        printf("Invalid ID! Please try again.\n");
        return;
    }

    for (int i = id - 1; i < medicineCount - 1; i++) {
        medicineList[i] = medicineList[i + 1];
    }
    medicineCount--;
    printf("Medicine deleted successfully!\n");
}

void displayMenu() {
    printf("\n--- Medicine Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("-----------------------------------------\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}