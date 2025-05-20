//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Inventory;

void add_item(Inventory *inv, Item item) {
    if (inv->num_items >= MAX_ITEMS) {
        printf("No more space in inventory!\n");
        return;
    }
    inv->items[inv->num_items] = item;
    inv->num_items++;
}

Item *find_item(Inventory *inv, int id) {
    for (int i = 0; i < inv->num_items; i++) {
        if (inv->items[i].id == id) {
            return &inv->items[i];
        }
    }
    return NULL;
}

void remove_item(Inventory *inv, int id) {
    for (int i = 0; i < inv->num_items; i++) {
        if (inv->items[i].id == id) {
            for (int j = i; j < inv->num_items - 1; j++) {
                inv->items[j] = inv->items[j+1];
            }
            inv->num_items--;
            return;
        }
    }
}

void print_item(Item *item) {
    printf("ID: %d\n", item->id);
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: $%.2f\n", item->price);
}

void print_inventory(Inventory *inv) {
    for (int i = 0; i < inv->num_items; i++) {
        print_item(&inv->items[i]);
        printf("-----------------------\n");
    }
}

int main() {
    Inventory inv = {0};
    int choice;
    do {
        printf("------- Warehouse Management System -------\n");
        printf("1. Add item\n");
        printf("2. Find item\n");
        printf("3. Remove item\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                Item item;
                printf("Enter item ID: ");
                scanf("%d", &item.id);
                printf("Enter item name: ");
                scanf("%s", item.name);
                printf("Enter item quantity: ");
                scanf("%d", &item.quantity);
                printf("Enter item price: ");
                scanf("%f", &item.price);
                add_item(&inv, item);
                printf("Item added successfully!\n");
                break;
            }
            case 2: {
                int id;
                printf("Enter item ID: ");
                scanf("%d", &id);
                Item *item = find_item(&inv, id);
                if (item != NULL) {
                    print_item(item);
                } else {
                    printf("Item not found!\n");
                }
                break;
            }
            case 3: {
                int id;
                printf("Enter item ID: ");
                scanf("%d", &id);
                remove_item(&inv, id);
                printf("Item removed successfully!\n");
                break;
            }
            case 4: {
                print_inventory(&inv);
                break;
            }
            case 5: {
                printf("Exiting program...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
                break;
            }
        }
    } while (1);
    
    return 0;
}