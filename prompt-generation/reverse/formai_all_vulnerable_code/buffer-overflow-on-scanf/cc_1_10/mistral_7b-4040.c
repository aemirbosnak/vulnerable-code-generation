//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

typedef struct {
    char name[50];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    if (num_items >= MAX_ITEMS) {
        printf("Warehouse is full.\n");
        return;
    }

    printf("Enter item name: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[num_items].quantity);

    num_items++;
}

void remove_item() {
    char name[50];
    int index = -1;

    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    for (int i = index; i < num_items - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    num_items--;
}

void check_inventory() {
    printf("\nCurrent inventory:\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. Check inventory\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                check_inventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}