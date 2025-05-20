//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>

struct item {
    int id;
    char name[50];
    int quantity;
};

struct warehouse {
    struct item inventory[100];
    int num_items;
};

struct warehouse w;

void print_inventory() {
    printf("\nInventory:\n");
    printf("---------------------------------\n");
    printf("| ID |      Item      | Quantity |\n");
    printf("|----|----------------|----------|\n");
    for (int i = 0; i < w.num_items; i++) {
        printf("| %2d | %14s | %8d |\n", w.inventory[i].id, w.inventory[i].name, w.inventory[i].quantity);
    }
    printf("---------------------------------\n");
}

void add_item(int id, char name[], int quantity) {
    if (w.num_items == 100) {
        printf("\nWarehouse is full. Cannot add item.\n");
        return;
    }
    struct item new_item;
    new_item.id = id;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    w.inventory[w.num_items] = new_item;
    w.num_items++;
    printf("\nItem added successfully.\n");
}

void remove_item(int id) {
    int index = -1;
    for (int i = 0; i < w.num_items; i++) {
        if (w.inventory[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("\nItem not found.\n");
        return;
    }
    for (int i = index; i < w.num_items-1; i++) {
        w.inventory[i] = w.inventory[i+1];
    }
    w.num_items--;
    printf("\nItem removed successfully.\n");
}

int main() {
    w.num_items = 0;
    int choice, id, quantity;
    char name[50];

    do {
        printf("\n1. Print inventory");
        printf("\n2. Add item");
        printf("\n3. Remove item");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_inventory();
                break;
            case 2:
                printf("\nEnter item ID: ");
                scanf("%d", &id);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(id, name, quantity);
                break;
            case 3:
                printf("\nEnter item ID: ");
                scanf("%d", &id);
                remove_item(id);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}