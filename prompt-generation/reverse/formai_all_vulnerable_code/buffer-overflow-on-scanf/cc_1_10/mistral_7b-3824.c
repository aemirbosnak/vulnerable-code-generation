//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }

    strcpy(inventory[num_items].name, name);
    inventory[num_items].quantity = quantity;
    num_items++;
}

void remove_item(char *name) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            memmove(&inventory[i], &inventory[i+1], sizeof(Item) * (num_items - i - 1));
            num_items--;
            break;
        }
    }

    if (i == num_items) {
        printf("Item not found in inventory.\n");
    }
}

void view_inventory() {
    int i;

    printf("\nCurrent Inventory:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

void search_item(char *name) {
    int i;

    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
            return;
        }
    }

    printf("%s not found in inventory.\n", name);
}

int main() {
    char command[10], name[50];
    int quantity, choice;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Inventory\n");
        printf("4. Search Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                add_item(name, quantity);
                break;

            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                remove_item(name);
                break;

            case 3:
                view_inventory();
                break;

            case 4:
                printf("Enter item name: ");
                scanf("%s", name);
                search_item(name);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}