//FormAI DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <string.h>

// define constants for inventory management
#define MAX_ITEMS 10
#define MAX_ITEM_NAME_LEN 20

// define data structures for managing items
typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    int quantity;
    float cost;
} Item;

// define global array to hold items
Item inventory[MAX_ITEMS];
int num_items = 0;

// function to print the inventory to the console
void print_inventory() {
    printf("### INVENTORY ###\n");
    printf("Name\tQuantity\tCost\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].cost);
    }
    printf("#################\n");
}

int main() {

    // add some items to the inventory
    strcpy(inventory[0].name, "Apples");
    inventory[0].quantity = 10;
    inventory[0].cost = 1.50;
    num_items++;

    strcpy(inventory[1].name, "Bananas");
    inventory[1].quantity = 5;
    inventory[1].cost = 0.75;
    num_items++;

    strcpy(inventory[2].name, "Oranges");
    inventory[2].quantity = 7;
    inventory[2].cost = 1.00;
    num_items++;

    // print the initial inventory
    print_inventory();

    // prompt the user for input and perform appropriate action
    printf("Enter 'add' to add an item to the inventory or 'remove' to remove an item from the inventory.\n");
    char input[10];
    scanf("%s", input);

    if (strcmp(input, "add") == 0) {
        if (num_items == MAX_ITEMS) {
            printf("Inventory is full. Cannot add any more items.\n");
        } else {
            // prompt the user for the name, quantity, and cost of the new item
            printf("Enter the name of the item (up to 20 characters): ");
            char name_input[MAX_ITEM_NAME_LEN];
            scanf("%s", name_input);
            strcpy(inventory[num_items].name, name_input);

            printf("Enter the quantity of the item: ");
            int quantity_input;
            scanf("%d", &quantity_input);
            inventory[num_items].quantity = quantity_input;

            printf("Enter the cost of the item: ");
            float cost_input;
            scanf("%f", &cost_input);
            inventory[num_items].cost = cost_input;

            // increment the number of items in the inventory
            num_items++;

            printf("Item added to inventory.\n");

            // reprint the updated inventory
            print_inventory();
        }

    } else if (strcmp(input, "remove") == 0) {
        // prompt the user for the name of the item to be removed
        printf("Enter the name of the item to be removed: ");
        char remove_input[MAX_ITEM_NAME_LEN];
        scanf("%s", remove_input);

        // search for the item by name
        int found = 0;
        for (int i = 0; i < num_items; i++) {
            if (strcmp(inventory[i].name, remove_input) == 0) {
                // remove the item by shifting all following items back by 1 index
                found = 1;
                for (int j = i; j < num_items - 1; j++) {
                    inventory[j] = inventory[j+1];
                }
                // clear the last inventory item and decrement the number of items
                memset(&(inventory[num_items-1]), 0, sizeof(Item));
                num_items--;
                break;
            }
        }

        if (found) {
            printf("Item removed from inventory.\n");
            // reprint the updated inventory
            print_inventory();
        } else {
            printf("Item '%s' not found in inventory.\n", remove_input);
        }
    } else {
        printf("Unknown command '%s'.\n", input);
    }

    return 0;
}