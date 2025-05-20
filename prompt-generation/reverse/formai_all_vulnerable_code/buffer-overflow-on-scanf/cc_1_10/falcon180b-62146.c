//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    double price;
} Item;

void add_item(Item* inventory, int num_items) {
    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);
    printf("Enter item price: $");
    scanf("%lf", &inventory[num_items].price);
    printf("\n");
}

void display_inventory(Item* inventory, int num_items) {
    printf("\nInventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t$%.2lf\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_quantity(Item* inventory, int num_items) {
    printf("\nEnter item name to update quantity: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter new quantity: ");
    scanf("%d", &inventory[num_items].quantity);
    printf("\n");
}

void main() {
    Item inventory[MAX_ITEMS];
    int num_items = 0;

    while (num_items < MAX_ITEMS) {
        printf("\nAdd item? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y') {
            add_item(inventory, num_items);
            num_items++;
        } else if (choice == 'n') {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    while (1) {
        printf("\nSelect an option:\n1. Display inventory\n2. Update quantity\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_inventory(inventory, num_items);
                break;
            case 2:
                update_quantity(inventory, num_items);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}