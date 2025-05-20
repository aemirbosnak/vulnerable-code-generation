//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 100
#define ITEM_SIZE 20

typedef struct {
    char name[10];
    int quantity;
} Item;

Item warehouse[MAX_CAPACITY];
int current_capacity = 0;

void add_item(char *name, int quantity) {
    if (current_capacity < MAX_CAPACITY) {
        strcpy(warehouse[current_capacity].name, name);
        warehouse[current_capacity].quantity = quantity;
        current_capacity++;
    } else {
        printf("Warehouse is full.\n");
    }
}

void remove_item(char *name, int *quantity_removed) {
    for (int i = 0; i < current_capacity; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            if (warehouse[i].quantity >= 1) {
                *quantity_removed = 1;
                warehouse[i].quantity--;
                break;
            } else {
                printf("Not enough items to remove.\n");
                return;
            }
        }
    }

    *quantity_removed = 0;
}

void print_inventory() {
    for (int i = 0; i < current_capacity; i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    char name[ITEM_SIZE];
    int quantity, quantity_removed;
    int choice;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Print inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(name, quantity);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                remove_item(name, &quantity_removed);
                if (quantity_removed) {
                    printf("Item removed successfully.\n");
                }
                break;
            case 3:
                print_inventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}