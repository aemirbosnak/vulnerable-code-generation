//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: surprised
// Medical Store Management System
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function declarations
void menu();
void addMedicine();
void viewMedicine();
void deleteMedicine();
void updateMedicine();

// Global variables
struct medicine {
    char name[50];
    char type[50];
    int quantity;
    float price;
};

struct medicine medicineList[100];
int medicineCount = 0;

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    printf("1. Add Medicine\n");
    printf("2. View Medicine\n");
    printf("3. Delete Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            addMedicine();
            break;
        case 2:
            viewMedicine();
            break;
        case 3:
            deleteMedicine();
            break;
        case 4:
            updateMedicine();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid choice. Try again.");
            menu();
    }
}

void addMedicine() {
    struct medicine medicine;
    printf("Enter medicine name: ");
    scanf("%s", medicine.name);
    printf("Enter medicine type: ");
    scanf("%s", medicine.type);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    medicineList[medicineCount++] = medicine;
    printf("Medicine added successfully.");
    menu();
}

void viewMedicine() {
    for (int i = 0; i < medicineCount; i++) {
        printf("%d. %s\n", i + 1, medicineList[i].name);
    }
    menu();
}

void deleteMedicine() {
    int index;
    printf("Enter index of medicine to delete: ");
    scanf("%d", &index);
    for (int i = index - 1; i < medicineCount - 1; i++) {
        medicineList[i] = medicineList[i + 1];
    }
    medicineCount--;
    printf("Medicine deleted successfully.");
    menu();
}

void updateMedicine() {
    int index;
    printf("Enter index of medicine to update: ");
    scanf("%d", &index);
    printf("Enter new medicine name: ");
    scanf("%s", medicineList[index].name);
    printf("Enter new medicine type: ");
    scanf("%s", medicineList[index].type);
    printf("Enter new medicine quantity: ");
    scanf("%d", &medicineList[index].quantity);
    printf("Enter new medicine price: ");
    scanf("%f", &medicineList[index].price);
    printf("Medicine updated successfully.");
    menu();
}