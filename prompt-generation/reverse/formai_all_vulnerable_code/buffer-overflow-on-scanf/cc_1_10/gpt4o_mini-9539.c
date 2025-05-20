//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

// Function declarations
void addItem(Warehouse *warehouse, char *name, int quantity, float price);
void displayInventory(Warehouse *warehouse);
void searchItem(Warehouse *warehouse, char *name);
void introduction();

int main() {
    Warehouse warehouse = { .count = 0 };
    introduction();

    char choice;
    do {
        printf("\nChoose an action: (A)dd item, (S)earch item, (D)isplay inventory, (E)xit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'A':
            case 'a': {
                char name[ITEM_NAME_LENGTH];
                int quantity;
                float price;

                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);

                addItem(&warehouse, name, quantity, price);
                break;
            }
            case 'S':
            case 's': {
                char name[ITEM_NAME_LENGTH];
                printf("Enter item name to search: ");
                scanf("%s", name);
                searchItem(&warehouse, name);
                break;
            }
            case 'D':
            case 'd':
                displayInventory(&warehouse);
                break;
            case 'E':
            case 'e':
                printf("Thank you for using the warehouse management system! Farewell!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'E' && choice != 'e');

    return 0;
}

void introduction() {
    printf("Welcome to the Sherlock Holmes Warehouse Management System!\n");
    printf("A curious mind may find hidden treasures within the inventory...\n");
}

void addItem(Warehouse *warehouse, char *name, int quantity, float price) {
    if (warehouse->count < MAX_ITEMS) {
        strncpy(warehouse->items[warehouse->count].name, name, ITEM_NAME_LENGTH);
        warehouse->items[warehouse->count].quantity = quantity;
        warehouse->items[warehouse->count].price = price;
        warehouse->count++;
        printf("Item '%s' added to the warehouse with quantity %d at a price of %.2f!\n", name, quantity, price);
    } else {
        printf("The warehouse is full, cannot add more items!\n");
    }
}

void displayInventory(Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("The warehouse is empty. No items to display.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("Item %d: %s | Quantity: %d | Price: %.2f\n", i + 1, warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void searchItem(Warehouse *warehouse, char *name) {
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Found Item: %s | Quantity: %d | Price: %.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
            return;
        }
    }
    printf("Alas, the item '%s' is not found in the warehouse. A true mystery!\n", name);
}