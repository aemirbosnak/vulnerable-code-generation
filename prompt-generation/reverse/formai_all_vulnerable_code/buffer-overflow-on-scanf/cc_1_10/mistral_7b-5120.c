//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50
#define INPUT_BUFFER_SIZE 100

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
} Item;

void print_menu() {
    printf("\n-------------------\n");
    printf("| Product Inventory | \n");
    printf("|    System v0.1    |\n");
    printf("-------------------|\n");
    printf("| 1. Add Item      |\n");
    printf("| 2. Remove Item   |\n");
    printf("| 3. Display Inventory |\n");
    printf("| 4. Quit          |\n");
    printf("-------------------|\n");
}

void add_item(Item inventory[MAX_ITEMS], int *num_items) {
    if (*num_items >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[*num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &inventory[*num_items].quantity);

    (*num_items)++;
}

void remove_item(Item inventory[MAX_ITEMS], int *num_items) {
    char name[ITEM_NAME_LENGTH];
    int i;

    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (i = 0; i < *num_items; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            for (int j = i; j < *num_items - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*num_items)--;
            break;
        }
    }

    if (i == *num_items) {
        printf("Item not found!\n");
    }
}

void display_inventory(Item inventory[MAX_ITEMS], int num_items) {
    printf("------------------------\n");
    printf("|  Product Inventory   |\n");
    printf("|       v0.1         |\n");
    printf("------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("| %-30s | %-5d |\n", inventory[i].name, inventory[i].quantity);
    }

    printf("------------------------\n");
}

int main() {
    Item inventory[MAX_ITEMS] = {0};
    int num_items = 0;
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                remove_item(inventory, &num_items);
                break;
            case 3:
                display_inventory(inventory, num_items);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }

    return 0;
}