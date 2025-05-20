//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine();
void viewMedicines();
void searchMedicine();
void deleteMedicine();
void displayMenu();

void addMedicineRecursively(int index) {
    if (index >= medicineCount) return;
    printf("Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n", 
            medicines[index].name, medicines[index].manufacturer, 
            medicines[index].price, medicines[index].quantity);
    addMedicineRecursively(index + 1);
}

void displayMenu() {
    printf("\n--- Medical Store Management System ---\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void addMedicine() {
    if (medicineCount < MAX_MEDICINES) {
        printf("Enter medicine name: ");
        scanf("%s", medicines[medicineCount].name);
        printf("Enter manufacturer name: ");
        scanf("%s", medicines[medicineCount].manufacturer);
        printf("Enter price: ");
        scanf("%f", &medicines[medicineCount].price);
        printf("Enter quantity: ");
        scanf("%d", &medicines[medicineCount].quantity);
        medicineCount++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Cannot add more medicines!\n");
    }
}

void viewMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available!\n");
    } else {
        printf("List of Medicines:\n");
        addMedicineRecursively(0);
    }
}

void searchMedicine() {
    char name[50];
    printf("Enter the medicine name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found: Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n", 
                   medicines[i].name, medicines[i].manufacturer, 
                   medicines[i].price, medicines[i].quantity);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicineRecursively(int index) {
    if (index >= medicineCount) return;
    if (index < medicineCount - 1) {
        medicines[index] = medicines[index + 1];
    }
    deleteMedicineRecursively(index + 1);
}

void deleteMedicine() {
    char name[50];
    printf("Enter the medicine name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            medicineCount--;
            deleteMedicineRecursively(i);
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
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
                searchMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}