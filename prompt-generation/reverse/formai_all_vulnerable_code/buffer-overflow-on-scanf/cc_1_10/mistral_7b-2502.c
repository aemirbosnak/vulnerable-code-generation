//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    char location[10];
} InventoryItem;

#define MAX_ITEMS 1000

InventoryItem inventory[MAX_ITEMS];
int num_items = 0;

void add_item(int id, const char* name, int qty, const char* location) {
    if (num_items >= MAX_ITEMS) {
        printf("Oh noes! Warehouse is full!\n");
        return;
    }

    strcpy(inventory[num_items].name, name);
    inventory[num_items].id = id;
    inventory[num_items].quantity = qty;
    strcpy(inventory[num_items].location, location);
    num_items++;
}

void remove_item(int id) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            memmove(&inventory[i], &inventory[i + 1], sizeof(InventoryItem) * (num_items - i - 1));
            num_items--;
            printf("Item %d removed.\n", id);
            return;
        }
    }

    printf("Item %d not found.\n", id);
}

void display_inventory() {
    int i;

    printf("\nCurrent inventory:\n");
    for (i = 0; i < num_items; i++) {
        printf("%d. %s (%s) - %d units - %s\n", i + 1, inventory[i].name, inventory[i].location, inventory[i].quantity, inventory[i].location);
    }
}

int main() {
    int choice, id;
    char name[50], location[10];
    int qty;

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. Display inventory\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &qty);
                printf("Enter item location: ");
                scanf("%s", location);
                add_item(id, name, qty, location);
                break;

            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                remove_item(id);
                break;

            case 3:
                display_inventory();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}