//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    char name[50];
    int quantity;
    float price;
};

void add_item(struct Item inventory[], int *num_items);
void remove_item(struct Item inventory[], int *num_items);
void display_inventory(struct Item inventory[], int num_items);

int main() {
    struct Item inventory[MAX_ITEMS];
    int num_items = 0;
    char choice;

    printf("Welcome to the Inventory System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_item(inventory, &num_items);
                break;
            case '2':
                remove_item(inventory, &num_items);
                break;
            case '3':
                display_inventory(inventory, num_items);
                break;
            case '4':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != '4');

    return 0;
}

void add_item(struct Item inventory[], int *num_items) {
    if (*num_items >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf(" %s", inventory[*num_items].name);

    printf("Enter quantity: ");
    scanf("%d", &inventory[*num_items].quantity);

    printf("Enter price: ");
    scanf("%f", &inventory[*num_items].price);

    (*num_items)++;
    printf("Item added to inventory.\n");
}

void remove_item(struct Item inventory[], int *num_items) {
    char name[50];
    int i, found = 0;

    printf("\nEnter item name: ");
    scanf(" %s", name);

    for (i = 0; i < *num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < *num_items - 1; i++) {
            inventory[i] = inventory[i+1];
        }

        (*num_items)--;
        printf("Item removed from inventory.\n");
    } else {
        printf("Item not found!\n");
    }
}

void display_inventory(struct Item inventory[], int num_items) {
    int i;

    printf("\nInventory:\n");
    printf("%-20s %-10s %-10s\n", "Item", "Quantity", "Price");

    for (i = 0; i < num_items; i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}