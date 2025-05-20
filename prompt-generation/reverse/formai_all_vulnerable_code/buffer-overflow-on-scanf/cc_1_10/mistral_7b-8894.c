//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", warehouse[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &warehouse[num_items].quantity);

    num_items++;
}

void delete_item() {
    char name[50];
    int i;

    printf("Enter item name to delete: ");
    scanf("%s", name);

    for (i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            for (int j = i; j < num_items - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            num_items--;
            printf("Item deleted successfully.\n");
            return;
        }
    }

    printf("Item not found in warehouse.\n");
}

void display_inventory() {
    int i;

    printf("\nCurrent inventory:\n");

    for (i = 0; i < num_items; i++) {
        printf("%d. %s - %d\n", i + 1, warehouse[i].name, warehouse[i].quantity);
    }
}

void modify_item() {
    char name[50];
    int choice, quantity;

    printf("Enter item name to modify: ");
    scanf("%s", name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            warehouse[i].quantity = quantity;
            printf("Item quantity modified successfully.\n");
            return;
        }
    }

    printf("Item not found in warehouse.\n");
}

void main_menu() {
    int choice;

    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Delete Item\n");
        printf("3. Display Inventory\n");
        printf("4. Modify Item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                delete_item();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                modify_item();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    main_menu();
    return 0;
}