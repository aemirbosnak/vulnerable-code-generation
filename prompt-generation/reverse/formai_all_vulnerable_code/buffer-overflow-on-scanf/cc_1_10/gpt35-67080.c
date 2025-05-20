//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constant values
#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_LOCATION_LENGTH 10

// define struct item
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    char location[MAX_LOCATION_LENGTH];
} item;

// define global array of items and number of items
item items[MAX_ITEMS];
int num_items = 0;

// function to add a new item to the warehouse
void add_item(char* name, int quantity, char* location) {
    // create new item
    item new_item;
    strcpy(new_item.name, name);
    new_item.quantity = quantity;
    strcpy(new_item.location, location);

    // add item to items array
    items[num_items] = new_item;
    num_items++;

    printf("Item added successfully.\n");
}

// function to remove an item from the warehouse
void remove_item(char* name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            // remove item by shifting array elements
            int j;
            for (j = i; j < num_items-1; j++) {
                items[j] = items[j+1];
            }
            num_items--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

// function to display all items in the warehouse
void display_items() {
    printf("Name\tQuantity\tLocation\n");
    int i;
    for (i = 0; i < num_items; i++) {
        printf("%s\t%d\t\t%s\n", items[i].name, items[i].quantity, items[i].location);
    }
}

int main() {
    // initial welcome message
    printf("Welcome to the Warehouse Management System.\n");

    // main loop
    while (1) {
        // display menu options
        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display all items\n");
        printf("4. Exit\n");

        // get user choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // process user choice
        switch (choice) {
            case 1: {
                // get input for new item
                char name[MAX_NAME_LENGTH];
                int quantity;
                char location[MAX_LOCATION_LENGTH];

                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter location: ");
                scanf("%s", location);

                // call add_item function
                add_item(name, quantity, location);

                break;
            }
            case 2: {
                // get input for item to be removed
                char name[MAX_NAME_LENGTH];
                printf("Enter name of item to remove: ");
                scanf("%s", name);

                // call remove_item function
                remove_item(name);

                break;
            }
            case 3: {
                // call display_items function
                display_items();

                break;
            }
            case 4: {
                // exit program
                printf("Thank you for using the Warehouse Management System.\n");
                return 0;
            }
            default: {
                // error message for invalid input
                printf("Invalid input. Please try again.\n");

                break;
            }
        }
    }
}