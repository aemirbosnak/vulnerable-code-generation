//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the warehouse
#define MAX_ITEMS 1000

// Define the maximum length of item and supplier names
#define MAX_NAME_LENGTH 50

// Define a structure to store information about each item in the warehouse
typedef struct {
    int id;                     // Item ID
    char name[MAX_NAME_LENGTH]; // Item name
    int quantity;               // Item quantity in stock
    char supplier[MAX_NAME_LENGTH]; // Name of the supplier of the item
} Item;

// Define a function to display the main menu of the warehouse management system
void display_menu() {
    printf("\nWarehouse Management System\n\n");
    printf("1. Add item to warehouse\n");
    printf("2. Remove item from warehouse\n");
    printf("3. Edit item in warehouse\n");
    printf("4. View items in warehouse\n");
    printf("5. Exit\n\n");
    printf("Enter your choice (1-5): ");
}

// Define a function to add a new item to the warehouse
void add_item(Item *items, int *num_items) {
    if (*num_items == MAX_ITEMS) {
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    Item item;
    printf("Enter item ID: ");
    scanf("%d", &item.id);
    getchar(); // consume the newline character
    printf("Enter item name: ");
    fgets(item.name, MAX_NAME_LENGTH, stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; // remove the newline character
    printf("Enter quantity: ");
    scanf("%d", &item.quantity);
    getchar(); // consume the newline character
    printf("Enter supplier name: ");
    fgets(item.supplier, MAX_NAME_LENGTH, stdin);
    item.supplier[strcspn(item.supplier, "\n")] = '\0'; // remove the newline character
    items[*num_items] = item;
    (*num_items)++;
    printf("Item added to warehouse.\n");
}

// Define a function to remove an item from the warehouse
void remove_item(Item *items, int *num_items) {
    if (*num_items == 0) {
        printf("Warehouse is empty. Cannot remove items.\n");
        return;
    }
    int id, i, j, found = 0;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    for (i = 0; i < *num_items; i++) {
        if (items[i].id == id) {
            found = 1;
            for (j = i; j < *num_items - 1; j++) {
                items[j] = items[j + 1];
            }
            (*num_items)--;
            printf("Item removed from warehouse.\n");
            break;
        }
    }
    if (!found) {
        printf("Item not found in warehouse.\n");
    }
}

// Define a function to edit an existing item in the warehouse
void edit_item(Item *items, int num_items) {
    if (num_items == 0) {
        printf("Warehouse is empty. Cannot edit items.\n");
        return;
    }
    int id, i, found = 0;
    printf("Enter item ID to edit: ");
    scanf("%d", &id);
    for (i = 0; i < num_items; i++) {
        if (items[i].id == id) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            getchar(); // consume the newline character
            printf("Enter new supplier name: ");
            fgets(items[i].supplier, MAX_NAME_LENGTH, stdin);
            items[i].supplier[strcspn(items[i].supplier, "\n")] = '\0'; // remove the newline character
            printf("Item edited successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Item not found in warehouse.\n");
    }
}

// Define a function to display all items in the warehouse
void view_items(Item *items, int num_items) {
    if (num_items == 0) {
        printf("Warehouse is empty. No items to display.\n");
        return;
    }
    int i;
    printf("ID\tName\t\tQuantity\tSupplier\n");
    for (i = 0; i < num_items; i++) {
        printf("%d\t%s\t%d\t\t%s\n", items[i].id, items[i].name, items[i].quantity, items[i].supplier);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0, choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                remove_item(items, &num_items);
                break;
            case 3:
                edit_item(items, num_items);
                break;
            case 4:
                view_items(items, num_items);
                break;
            case 5:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}