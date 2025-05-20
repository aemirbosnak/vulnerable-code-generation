//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// define the maximum length of each item name
#define MAX_NAME_LENGTH 50

// create a struct to represent each item in the warehouse
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} item;

// define a global array of items to represent the warehouse
item warehouse[MAX_ITEMS];

// keep track of how many items are in the warehouse
int num_items = 0;

// define a function to add a new item to the warehouse
void add_item() {
    // check if the warehouse is already full
    if (num_items >= MAX_ITEMS) {
        printf("Sorry, the warehouse is full and cannot hold any more items.\n");
        return;
    }
    
    // prompt the user for the name and quantity of the new item
    char name[MAX_NAME_LENGTH];
    int quantity;
    printf("Enter the name of the new item: ");
    scanf("%s", name);
    printf("Enter the quantity of the new item: ");
    scanf("%d", &quantity);
    
    // create a new item struct and add it to the warehouse
    item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    warehouse[num_items] = new_item;
    num_items++;
    
    printf("The item has been successfully added to the warehouse.\n");
}

// define a function to remove an item from the warehouse
void remove_item() {
    // prompt the user for the name of the item to remove
    char name[MAX_NAME_LENGTH];
    printf("Enter the name of the item to remove: ");
    scanf("%s", name);
    
    // find the item in the warehouse and remove it
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(warehouse[i].name, name) == 0) {
            index = i;
        }
    }
    if (index == -1) {
        printf("Sorry, the item \"%s\" was not found in the warehouse.\n", name);
    } else {
        for (int i = index; i < num_items-1; i++) {
            warehouse[i] = warehouse[i+1];
        }
        num_items--;
        printf("The item \"%s\" has been removed from the warehouse.\n", name);
    }
}

// define a function to display the contents of the warehouse
void display_items() {
    printf("Warehouse inventory:\n");
    printf("Name\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

// the main function
int main() {
    // initialize the warehouse with some test data
    item item1 = {"Hammer", 10};
    item item2 = {"Nails", 500};
    item item3 = {"Saw", 5};
    warehouse[0] = item1;
    warehouse[1] = item2;
    warehouse[2] = item3;
    num_items = 3;
    
    // display a menu and prompt the user for input until they choose to quit
    int choice = 0;
    while (choice != 4) {
        printf("\nWarehouse management system\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Quit\n");
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
                display_items();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}