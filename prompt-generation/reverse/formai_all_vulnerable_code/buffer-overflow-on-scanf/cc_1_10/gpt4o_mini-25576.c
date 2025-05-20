//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
} Medicine;

Medicine stock[MAX_MEDICINES];
int medicineCount = 0;

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Update Medicine Quantity\n");
    printf("4. Remove Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
    printf("========================================\n");
    printf("Select an option: ");
}

void addMedicine() {
    if (medicineCount >= MAX_MEDICINES) {
        printf("Medicines stock is full!\n");
        return;
    }
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);
    stock[medicineCount++] = newMedicine;
    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    if (medicineCount == 0) {
        printf("No medicines in stock!\n");
        return;
    }
    printf("\n=== Medicines in Stock ===\n");
    for (int i = 0; i < medicineCount; i++) {
        printf("%d. %s | Quantity: %d | Price: %.2f\n", 
            i+1, stock[i].name, stock[i].quantity, stock[i].price);
    }
    printf("===========================\n");
}

void updateQuantity() {
    char name[MAX_NAME_LEN];
    int found = 0;
    printf("Enter medicine name to update quantity: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            found = 1;
            int newQuantity;
            printf("Current quantity: %d\n", stock[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            stock[i].quantity = newQuantity;
            printf("Quantity updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void removeMedicine() {
    char name[MAX_NAME_LEN];
    int found = 0;
    printf("Enter medicine name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < medicineCount - 1; j++) {
                stock[j] = stock[j + 1];
            }
            medicineCount--;
            printf("Medicine removed successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
}

void searchMedicine() {
    char name[MAX_NAME_LEN];
    int found = 0;
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (int i = 0; i < medicineCount; i++) {
        if (strcmp(stock[i].name, name) == 0) {
            found = 1;
            printf("Medicine found!\n");
            printf("Name: %s | Quantity: %d | Price: %.2f\n", 
                stock[i].name, stock[i].quantity, stock[i].price);
            break;
        }
    }

    if (!found) {
        printf("Medicine not found!\n");
    }
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
                displayMedicines();
                break;
            case 3:
                updateQuantity();
                break;
            case 4:
                removeMedicine();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}