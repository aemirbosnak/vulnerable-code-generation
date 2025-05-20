//Code Llama-13B DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
// Warehouse Management System

#include <stdio.h>
#include <stdlib.h>

// Declare constants
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20
#define MAX_DESCRIPTION_LENGTH 50

// Declare struct for warehouse item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    double price;
} Item;

// Declare struct for warehouse inventory
typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

// Declare functions
void print_menu();
void add_item(Inventory* inventory);
void remove_item(Inventory* inventory);
void list_items(Inventory* inventory);

// Implement functions
void print_menu() {
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. List items\n");
    printf("4. Quit\n");
}

void add_item(Inventory* inventory) {
    printf("Enter item name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    printf("Enter item description: ");
    char description[MAX_DESCRIPTION_LENGTH];
    scanf("%s", description);

    printf("Enter item quantity: ");
    int quantity;
    scanf("%d", &quantity);

    printf("Enter item price: ");
    double price;
    scanf("%lf", &price);

    Item item = { name, description, quantity, price };
    inventory->items[inventory->num_items] = item;
    inventory->num_items++;
}

void remove_item(Inventory* inventory) {
    printf("Enter item name to remove: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int i;
    for (i = 0; i < inventory->num_items; i++) {
        if (strcmp(inventory->items[i].name, name) == 0) {
            break;
        }
    }

    if (i == inventory->num_items) {
        printf("Item not found.\n");
        return;
    }

    for (int j = i; j < inventory->num_items - 1; j++) {
        inventory->items[j] = inventory->items[j + 1];
    }

    inventory->num_items--;
}

void list_items(Inventory* inventory) {
    for (int i = 0; i < inventory->num_items; i++) {
        printf("%s - %s (%d @ $%.2f)\n", inventory->items[i].name, inventory->items[i].description, inventory->items[i].quantity, inventory->items[i].price);
    }
}

int main() {
    Inventory inventory = { .items = { 0 }, .num_items = 0 };

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&inventory);
                break;
            case 2:
                remove_item(&inventory);
                break;
            case 3:
                list_items(&inventory);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}