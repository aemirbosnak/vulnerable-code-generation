//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int stock;
} Medicine;

Medicine medicineList[MAX_MEDICINES];
int medicineCount = 0;

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Medicine list is full. Cannot add more medicines.\n");
        return;
    }

    Medicine m;
    printf("Enter Medicine ID: ");
    scanf("%d", &m.id);
    printf("Enter Medicine Name: ");
    scanf("%s", m.name);
    printf("Enter Manufacturer: ");
    scanf("%s", m.manufacturer);
    printf("Enter Price: ");
    scanf("%f", &m.price);
    printf("Enter Stock: ");
    scanf("%d", &m.stock);

    medicineList[medicineCount++] = m;
    printf("Medicine added successfully.\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines available.\n");
        return;
    }

    printf("\nList of Medicines:\n");
    printf("ID\tName\t\tManufacturer\tPrice\tStock\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d\t%s\t\t%s\t%.2f\t%d\n", medicineList[i].id,
               medicineList[i].name, medicineList[i].manufacturer,
               medicineList[i].price, medicineList[i].stock);
    }
}

void searchMedicine() {
    int id;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicineList[i].id == id) {
            printf("Medicine found:\n");
            printf("ID: %d\n", medicineList[i].id);
            printf("Name: %s\n", medicineList[i].name);
            printf("Manufacturer: %s\n", medicineList[i].manufacturer);
            printf("Price: %.2f\n", medicineList[i].price);
            printf("Stock: %d\n", medicineList[i].stock);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void updateStock() {
    int id, newStock;
    printf("Enter Medicine ID to update stock: ");
    scanf("%d", &id);

    for (int i = 0; i < medicineCount; i++) {
        if (medicineList[i].id == id) {
            printf("Current stock: %d\n", medicineList[i].stock);
            printf("Enter new stock: ");
            scanf("%d", &newStock);
            medicineList[i].stock = newStock;
            printf("Stock updated successfully.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Stock\n");
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
                updateStock();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}