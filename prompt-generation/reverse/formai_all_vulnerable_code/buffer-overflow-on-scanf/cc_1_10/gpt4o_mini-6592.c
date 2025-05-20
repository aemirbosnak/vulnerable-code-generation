//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
    char name[30];
    char manufacturer[30];
    float price;
    int stock;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Inventory full! Cannot add more medicines.\n");
        return;
    }
    Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter manufacturer: ");
    scanf("%s", m.manufacturer);
    printf("Enter price: ");
    scanf("%f", &m.price);
    printf("Enter stock quantity: ");
    scanf("%d", &m.stock);
    
    inventory[count++] = m;
    printf("Medicine added successfully!\n");
}

void updateStock() {
    char name[30];
    printf("Enter medicine name to update stock: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            int newStock;
            printf("Current stock is %d. Enter new stock quantity: ", inventory[i].stock);
            scanf("%d", &newStock);
            inventory[i].stock = newStock;
            printf("Stock updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found in the inventory.\n");
}

void searchMedicine() {
    char name[30];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine: %s\n", inventory[i].name);
            printf("Manufacturer: %s\n", inventory[i].manufacturer);
            printf("Price: %.2f\n", inventory[i].price);
            printf("Stock: %d\n", inventory[i].stock);
            return;
        }
    }
    printf("Medicine not found in the inventory.\n");
}

void displayInventory() {
    if (count == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\nInventory List:\n");
    printf("---------------------------------------------------\n");
    printf("| %-30s | %-30s | %-10s | %-10s |\n", "Medicine Name", "Manufacturer", "Price", "Stock");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-30s | %-30s | %-10.2f | %-10d |\n", inventory[i].name, inventory[i].manufacturer, inventory[i].price, inventory[i].stock);
    }
    printf("---------------------------------------------------\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Update Stock\n");
        printf("3. Search Medicine\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}