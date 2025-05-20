//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 999

typedef struct {
    char name[MAX_NAME_LEN];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);

    num_items++;
}

void check_stock(char name[]) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Current stock of %s: %d\n", name, inventory[i].quantity);
            return;
        }
    }

    printf("Item not found in stock!\n");
}

void update_stock(char name[], int quantity_change) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += quantity_change;
            printf("Stock updated for %s\n", name);
            return;
        }
    }

    printf("Item not found in stock!\n");
}

int main() {
    int choice;
    char name[MAX_NAME_LEN];
    int quantity;

    while (1) {
        printf("\n1. Add item\n2. Check stock\n3. Update stock\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                check_stock(name);
                break;
            case 3:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity change: ");
                scanf("%d", &quantity);
                update_stock(name, quantity);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}