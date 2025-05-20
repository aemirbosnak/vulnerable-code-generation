//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    int quantity;
    float price;
};

void add_item(struct item inventory[], int *num_items) {
    if (*num_items >= MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[*num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &inventory[*num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &inventory[*num_items].price);

    (*num_items)++;
}

void remove_item(struct item inventory[], int *num_items) {
    char name[50];
    int i, index = -1;

    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (i = 0; i < *num_items; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found in inventory!\n");
        return;
    }

    // shift items after the one to be removed
    for (i = index + 1; i < *num_items; i++) {
        inventory[i - 1] = inventory[i];
    }

    (*num_items)--;
}

void display_inventory(struct item inventory[], int num_items) {
    int i;

    printf("%-20s %-10s %-10s\n", "Item", "Quantity", "Price");

    for (i = 0; i < num_items; i++) {
        printf("%-20s %-10d %-10.2f\n",
            inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    struct item inventory[MAX_ITEMS];
    int num_items = 0;
    int choice;

    do {
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                remove_item(inventory, &num_items);
                break;
            case 3:
                display_inventory(inventory, num_items);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}