//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ada Lovelace
/* Warehouse Management System in the style of Ada Lovelace */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20

struct Item {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
};

int num_items = 0;
struct Item items[MAX_ITEMS];

bool is_item_available(int id) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            return true;
        }
    }
    return false;
}

void add_item(int id, char name[], int quantity) {
    if (num_items < MAX_ITEMS) {
        struct Item item = {id, name, quantity};
        items[num_items++] = item;
        printf("Item added successfully.\n");
    } else {
        printf("Warehouse is full, cannot add more items.\n");
    }
}

void remove_item(int id) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            memmove(&items[i], &items[i+1], (num_items-i-1) * sizeof(struct Item));
            num_items--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found in the warehouse.\n");
}

void update_item_quantity(int id, int quantity) {
    for (int i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            items[i].quantity = quantity;
            printf("Item quantity updated successfully.\n");
            return;
        }
    }
    printf("Item not found in the warehouse.\n");
}

void print_item_list() {
    printf("Item List:\n");
    printf("ID\tName\t\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t\t%d\n", items[i].id, items[i].name, items[i].quantity);
    }
}

int main() {
    printf("Welcome to the Warehouse Management System.\n");
    
    while (true) {
        printf("Please select an option:\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Item Quantity\n");
        printf("4. Print Item List\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int id, quantity;
            char name[MAX_NAME_LENGTH];
            printf("Enter item ID: ");
            scanf("%d", &id);
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter item quantity: ");
            scanf("%d", &quantity);
            if (!is_item_available(id)) {
                add_item(id, name, quantity);
            } else {
                printf("Item with the same ID already exists in the warehouse.\n");
            }
        } else if (choice == 2) {
            int id;
            printf("Enter item ID: ");
            scanf("%d", &id);
            remove_item(id);
        } else if (choice == 3) {
            int id, quantity;
            printf("Enter item ID: ");
            scanf("%d", &id);
            printf("Enter new item quantity: ");
            scanf("%d", &quantity);
            update_item_quantity(id, quantity);
        } else if (choice == 4) {
            print_item_list();
        } else if (choice == 5) {
            printf("Thank you for using the Warehouse Management System.\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}