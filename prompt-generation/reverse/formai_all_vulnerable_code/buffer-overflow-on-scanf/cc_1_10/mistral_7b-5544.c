//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#define WAREHOUSE_SIZE 50

typedef struct {
    int id;
    char name[50];
    int quantity;
} Item;

Item warehouse[WAREHOUSE_SIZE];
int count = 0;

void add_item(int id, const char *name, int quantity) {
    if (count >= WAREHOUSE_SIZE) {
        printf("Warehouse is full.\n");
        return;
    }

    warehouse[count].id = id;
    strcpy(warehouse[count].name, name);
    warehouse[count].quantity = quantity;

    count++;
}

void remove_item(int id) {
    int i;

    for (i = 0; i < count; i++) {
        if (warehouse[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            count--;
            break;
        }
    }

    if (i == count) {
        printf("Item not found in the warehouse.\n");
    }
}

void display_warehouse() {
    int i;

    printf("\nWAREHOUSE INVENTORY\n");
    printf("----------------------\n");
    for (i = 0; i < count; i++) {
        printf("| ID   | Name    | Quantity |\n");
        printf("|-------|---------|----------|\n");
        printf("| %-5d | %-20s | %-10d |\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

int main() {
    int choice, id;
    char name[50];
    int quantity;

    while (1) {
        printf("\n1. Add Item\n2. Remove Item\n3. Display Warehouse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                add_item(id, name, quantity);
                break;
            case 2:
                printf("Enter item ID to remove: ");
                scanf("%d", &id);
                remove_item(id);
                break;
            case 3:
                display_warehouse();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}