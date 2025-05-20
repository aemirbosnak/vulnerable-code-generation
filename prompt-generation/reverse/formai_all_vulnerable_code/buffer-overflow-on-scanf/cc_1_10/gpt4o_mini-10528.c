//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void addMedicine() {
    if (medicine_count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. The inventory is full.\n");
        return;
    }
    Medicine new_medicine;
    new_medicine.id = medicine_count + 1;

    printf("Enter medicine name: ");
    scanf("%s", new_medicine.name);
    printf("Enter quantity: ");
    scanf("%d", &new_medicine.quantity);
    printf("Enter price: ");
    scanf("%f", &new_medicine.price);

    medicines[medicine_count] = new_medicine;
    medicine_count++;
    printf("Medicine added successfully!\n");
}

void viewMedicines() {
    printf("\n--- Medicine Inventory ---\n");
    if (medicine_count == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void updateMedicine() {
    int id;
    printf("Enter medicine ID to update: ");
    scanf("%d", &id);

    if (id <= 0 || id > medicine_count) {
        printf("Invalid ID.\n");
        return;
    }

    Medicine *med = &medicines[id - 1];

    printf("Updating medicine %s...\n", med->name);
    printf("Enter new quantity (current: %d): ", med->quantity);
    scanf("%d", &med->quantity);
    printf("Enter new price (current: %.2f): ", med->price);
    scanf("%f", &med->price);
    printf("Medicine updated successfully!\n");
}

void deleteMedicine() {
    int id;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > medicine_count) {
        printf("Invalid ID.\n");
        return;
    }

    for (int i = id - 1; i < medicine_count - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    medicine_count--;
    printf("Medicine deleted successfully!\n");
}

void statistics() {
    if (medicine_count == 0) {
        printf("No medicines available for statistics.\n");
        return;
    }

    float total_value = 0.0;
    int total_quantity = 0;
    for (int i = 0; i < medicine_count; i++) {
        total_value += medicines[i].price * medicines[i].quantity;
        total_quantity += medicines[i].quantity;
    }

    printf("\n--- Statistics ---\n");
    printf("Total number of medicines: %d\n", medicine_count);
    printf("Total quantity of all medicines: %d\n", total_quantity);
    printf("Total value of inventory: %.2f\n", total_value);
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. View Statistics\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
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
                statistics();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}