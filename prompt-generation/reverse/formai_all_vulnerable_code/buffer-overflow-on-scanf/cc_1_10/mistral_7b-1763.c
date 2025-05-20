//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LEN + 1];
    int quantity;
} Item;

void print_menu() {
    printf("\nWarehouse Management System\n");
    printf("-----------------------------\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Inventory\n");
    printf("4. Exit\n");
}

void add_item(Item items[MAX_ITEMS]) {
    char name[MAX_NAME_LEN + 1];
    int quantity;
    int index = -1;

    printf("Enter item name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        if (strcmp(name, items[i].name) == 0) {
            printf("Item already exists!\n");
            return;
        }
        if (items[i].quantity == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Maximum number of items reached!\n");
        return;
    }

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    strcpy(items[index].name, name);
    items[index].quantity = quantity;

    printf("Item added successfully!\n");
}

void remove_item(Item items[MAX_ITEMS]) {
    char name[MAX_NAME_LEN + 1];
    int index = -1;

    printf("Enter item name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        if (strcmp(name, items[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found!\n");
        return;
    }

    items[index].quantity = 0;

    printf("Item removed successfully!\n");
}

void view_inventory(Item items[MAX_ITEMS]) {
    printf("\nCurrent Inventory:\n");

    for (int i = 0; i < MAX_ITEMS && items[i].name[0] != '\0'; i++) {
        if (items[i].quantity > 0) {
            printf("%-20s %d\n", items[i].name, items[i].quantity);
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items);
                break;
            case 2:
                remove_item(items);
                break;
            case 3:
                view_inventory(items);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}