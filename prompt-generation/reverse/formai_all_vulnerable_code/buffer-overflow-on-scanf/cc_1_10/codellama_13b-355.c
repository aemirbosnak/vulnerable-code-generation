//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

void print_menu() {
    printf("Welcome to the Medical Store Management System\n");
    printf("Please select an option by entering its number:\n");
    printf("1. Add new item\n");
    printf("2. Remove item\n");
    printf("3. Update item quantity\n");
    printf("4. Print inventory\n");
    printf("5. Exit\n");
}

void add_item(Item items[], int* num_items) {
    if (*num_items >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    printf("Enter the name of the item: ");
    scanf("%s", items[*num_items].name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &items[*num_items].quantity);

    printf("Enter the price of the item: ");
    scanf("%f", &items[*num_items].price);

    (*num_items)++;
}

void remove_item(Item items[], int* num_items) {
    if (*num_items <= 0) {
        printf("Inventory is empty. Cannot remove any more items.\n");
        return;
    }

    int index;
    printf("Enter the index of the item to remove: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_items) {
        printf("Invalid index. Cannot remove item.\n");
        return;
    }

    for (int i = index; i < *num_items - 1; i++) {
        items[i] = items[i + 1];
    }

    (*num_items)--;
}

void update_item_quantity(Item items[], int* num_items) {
    if (*num_items <= 0) {
        printf("Inventory is empty. Cannot update any items.\n");
        return;
    }

    int index;
    printf("Enter the index of the item to update: ");
    scanf("%d", &index);

    if (index < 0 || index >= *num_items) {
        printf("Invalid index. Cannot update item.\n");
        return;
    }

    printf("Enter the new quantity of the item: ");
    scanf("%d", &items[index].quantity);
}

void print_inventory(Item items[], int num_items) {
    printf("Inventory:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                update_item_quantity(items, &num_items);
                break;
            case 4:
                print_inventory(items, num_items);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}