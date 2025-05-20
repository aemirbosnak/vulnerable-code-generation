//FormAI DATASET v1.0 Category: Product Inventory System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum items in inventory

struct Item {
    char name[50];
    int quantity;
    float price;
};

void print_menu() {
    printf("\n");
    printf("========== INVENTORY SYSTEM ==========\n");
    printf("1. Add new item\n");
    printf("2. View inventory\n");
    printf("3. Edit item price\n");
    printf("4. Edit item quantity\n");
    printf("5. Exit\n");
    printf("\n");
}

void add_item(struct Item inventory[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("ERROR: Maximum items reached!\n");
        return;
    }
    
    struct Item item;
    printf("Enter item name (max 50 characters): ");
    scanf("%s", item.name);
    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);
    printf("Enter item price: ");
    scanf("%f", &item.price);
    
    inventory[*count] = item;
    (*count)++;
    
    printf("Item added successfully!\n");
}

void view_inventory(struct Item inventory[], int count) {
    printf("\n");
    printf("========== INVENTORY LIST ==========\n");
    printf("%-20s %-10s %-10s\n", "ITEM NAME", "QUANTITY", "PRICE");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

void edit_price(struct Item inventory[], int count) {
    printf("Enter item name: ");
    char name[50];
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Price updated successfully!\n");
            return;
        }
    }
    
    printf("ERROR: Item not found!\n");
}

void edit_quantity(struct Item inventory[], int count) {
    printf("Enter item name: ");
    char name[50];
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    
    printf("ERROR: Item not found!\n");
}

int main() {
    struct Item inventory[MAX_ITEMS];
    int count = 0;
    int choice;
    
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_item(inventory, &count);
                break;
            case 2:
                view_inventory(inventory, count);
                break;
            case 3:
                edit_price(inventory, count);
                break;
            case 4:
                edit_quantity(inventory, count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    
    return 0;
}