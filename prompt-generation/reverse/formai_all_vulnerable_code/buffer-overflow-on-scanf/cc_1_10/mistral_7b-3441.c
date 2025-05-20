//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEM_NAME_LENGTH 50
#define MAX_WAREHOUSE_SIZE 10

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH + 1];
    int quantity;
} Item;

Item warehouse[MAX_WAREHOUSE_SIZE];
int current_item_index = 0;

void add_item(char *name, int quantity) {
    if (current_item_index >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full.\n");
        return;
    }

    strcpy(warehouse[current_item_index].name, name);
    warehouse[current_item_index].quantity = quantity;
    current_item_index++;
}

void remove_item(char *name) {
    for (int i = 0; i < current_item_index; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            for (int j = i; j < current_item_index - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            current_item_index--;
            break;
        }
    }
}

void display_inventory() {
    printf("Current inventory:\n");
    for (int i = 0; i < current_item_index; i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity, choice;

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. Display inventory\n4. Exit\n");
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
                printf("Enter item name to remove: ");
                scanf("%s", name);
                remove_item(name);
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}