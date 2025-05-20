//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

struct Medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

struct Medicine inventory[MAX_MEDICINES];
int medicine_count = 0;

// Function prototypes
void addMedicine();
void viewMedicines();
void updateStock();
void menu();

int main() {
    printf("====================================\n");
    printf(" Welcome to the Medical Store System \n");
    printf("====================================\n");
    menu();
    return 0;
}

void menu() {
    int choice;

    do {
        printf("\n======== Menu ========\n");
        printf("1. Add Medicine\n");
        printf("2. View Medicines\n");
        printf("3. Update Stock\n");
        printf("4. Exit\n");
        printf("=======================\n");
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
                updateStock();
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

void addMedicine() {
    if (medicine_count < MAX_MEDICINES) {
        struct Medicine newMedicine;

        printf("Enter the name of the medicine: ");
        scanf("%s", newMedicine.name);
        printf("Enter the manufacturer: ");
        scanf("%s", newMedicine.manufacturer);
        printf("Enter the quantity: ");
        scanf("%d", &newMedicine.quantity);
        printf("Enter the price: ");
        scanf("%f", &newMedicine.price);

        inventory[medicine_count] = newMedicine;
        medicine_count++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Cannot add more medicines. Inventory full!\n");
    }
}

void viewMedicines() {
    printf("\n===== List of Medicines =====\n");
    if (medicine_count == 0) {
        printf("No medicines in inventory!\n");
    } else {
        for (int i = 0; i < medicine_count; i++) {
            printf("Medicine %d:\n", i + 1);
            printf(" Name: %s\n", inventory[i].name);
            printf(" Manufacturer: %s\n", inventory[i].manufacturer);
            printf(" Quantity: %d\n", inventory[i].quantity);
            printf(" Price: %.2f\n", inventory[i].price);
            printf("===========================\n");
        }
    }
}

void updateStock() {
    char medicineName[50];
    int found = 0;

    printf("Enter the name of the medicine to update stock: ");
    scanf("%s", medicineName);

    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(inventory[i].name, medicineName) == 0) {
            found = 1;
            int newQuantity;
            printf("Current quantity: %d. Enter new quantity: ", inventory[i].quantity);
            scanf("%d", &newQuantity);
            inventory[i].quantity = newQuantity;
            printf("Stock updated successfully for %s!\n", inventory[i].name);
            break;
        }
    }

    if (!found) {
        printf("Medicine %s not found in inventory!\n", medicineName);
    }
}