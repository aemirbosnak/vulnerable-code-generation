//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, int quantity) {
    if (num_items >= MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }
    strcpy(warehouse[num_items].name, name);
    warehouse[num_items].quantity = quantity;
    num_items++;
}

void remove_item(char *name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            if (warehouse[i].quantity > 0) {
                warehouse[i].quantity--;
            } else {
                printf("Item not found or out of stock.\n");
                return;
            }
            break;
        }
    }
    if (i == num_items) {
        printf("Item not found.\n");
    }
}

void view_inventory() {
    int i;
    printf("\nCurrent inventory:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    int quantity, choice;

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. View inventory\n4. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}