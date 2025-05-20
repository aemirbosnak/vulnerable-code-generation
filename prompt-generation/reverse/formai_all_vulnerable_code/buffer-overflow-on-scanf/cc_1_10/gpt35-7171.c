//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Item {
    char name[20];
    int quantity;
};

struct Inventory {
    struct Item items[100];
    int num_items;
};

void display_inventory(struct Inventory inv) {
    printf("Inventory:\n");
    printf("%-20s %-10s\n", "Item Name", "Quantity");
    for(int i=0; i<inv.num_items; i++) {
        printf("%-20s %-10d\n", inv.items[i].name, inv.items[i].quantity);
    }
}

void add_item(struct Inventory *inv, char *name, int quantity) {
    if(inv->num_items >= 100) {
        printf("ERROR: Inventory is full!\n");
        return;
    }
    for(int i=0; i<inv->num_items; i++) {
        if(strcmp(inv->items[i].name, name) == 0) {
            inv->items[i].quantity += quantity;
            return;
        }
    }
    // Item not found, add new item
    strcpy(inv->items[inv->num_items].name, name);
    inv->items[inv->num_items].quantity = quantity;
    inv->num_items++;
}

void remove_item(struct Inventory *inv, char *name, int quantity) {
    for(int i=0; i<inv->num_items; i++) {
        if(strcmp(inv->items[i].name, name) == 0) {
            inv->items[i].quantity -= quantity;
            if(inv->items[i].quantity <= 0) {
                // Remove item from inventory
                for(int j=i; j<inv->num_items-1; j++) {
                    inv->items[j] = inv->items[j+1];
                }
                inv->num_items--;
            }
            return;
        }
    }
    printf("ERROR: Item not found in inventory!\n");
}

int main() {
    struct Inventory inv;
    inv.num_items = 0;
    char item_name[20];
    int item_quantity;
    int choice = -1;
    printf("Welcome to the Post-Apocalyptic Product Inventory System!\n");
    while(choice != 0) {
        printf("\nPlease choose an option:\n");
        printf("1. Display Inventory\n");
        printf("2. Add Item\n");
        printf("3. Remove Item\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                display_inventory(inv);
                break;
            case 2:
                printf("\nEnter item name and quantity separated by a space:\n");
                scanf("%s %d", item_name, &item_quantity);
                add_item(&inv, item_name, item_quantity);
                printf("\n%s added to inventory!\n", item_name);
                break;
            case 3:
                printf("\nEnter item name and quantity separated by a space:\n");
                scanf("%s %d", item_name, &item_quantity);
                remove_item(&inv, item_name, item_quantity);
                printf("\n%s removed from inventory!\n", item_name);
                break;
            case 0:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    }
    return 0;
}