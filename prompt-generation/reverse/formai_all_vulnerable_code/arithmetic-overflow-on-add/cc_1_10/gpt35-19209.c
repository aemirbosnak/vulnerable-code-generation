//FormAI DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Struct for each item in inventory
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

// Declaration of functions
void add_item(Item[], int*);
void remove_item(Item[], int*);
void update_item(Item[], int);
void display_inventory(Item[], int);
void write_to_file(Item[], int);
void read_from_file(Item[], int*);

int main() {
    int num_items = 0;
    Item inventory[MAX_ITEMS];

    // Read inventory from file (if it exists)
    read_from_file(inventory, &num_items);

    int choice;
    do {
        // Display menu options
        printf("\n\nInventory System Menu\n");
        printf("-----------------------\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update item\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add item to inventory
                add_item(inventory, &num_items);
                break;

            case 2:
                // Remove item from inventory
                remove_item(inventory, &num_items);
                break;

            case 3:
                // Update item in inventory
                update_item(inventory, num_items);
                break;

            case 4:
                // Display current inventory
                display_inventory(inventory, num_items);
                break;

            case 5:
                // Write inventory to file and exit program
                write_to_file(inventory, num_items);
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while(choice != 5);

    return 0;
}

void add_item(Item inventory[], int *num_items) {
    if(*num_items == MAX_ITEMS) {
        printf("\nInventory is full. Cannot add item.\n");
        return;
    }

    Item new_item;

    // Get item data from user
    printf("\nEnter item name: ");
    scanf("%s", new_item.name);
    printf("Enter item price: $");
    scanf("%f", &new_item.price);
    printf("Enter item quantity: ");
    scanf("%d", &new_item.quantity);

    // Assign item ID (incremented from previous item)
    if(*num_items == 0) {
        new_item.id = 1;
    }
    else {
        new_item.id = inventory[*num_items-1].id + 1;
    }

    // Add new item to inventory array
    inventory[*num_items] = new_item;
    (*num_items)++;

    printf("\nItem added to inventory.\n");
}

void remove_item(Item inventory[], int *num_items) {
    if(*num_items == 0) {
        printf("\nInventory is empty. Cannot remove item.\n");
        return;
    }

    int id_to_remove;
    printf("\nEnter item ID to remove: ");
    scanf("%d", &id_to_remove);

    int remove_index = -1;
    for(int i=0; i<*num_items; i++) {
        if(inventory[i].id == id_to_remove) {
            remove_index = i;
        }
    }

    if(remove_index == -1) {
        printf("\nItem with ID %d not found in inventory.\n", id_to_remove);
    }
    else {
        // Shift items after removed item to fill gap
        for(int i=remove_index; i<*num_items-1; i++) {
            inventory[i] = inventory[i+1];
        }
        (*num_items)--;
        printf("\nItem removed from inventory.\n");
    }
}

void update_item(Item inventory[], int num_items) {
    if(num_items == 0) {
        printf("\nInventory is empty. Cannot update item.\n");
        return;
    }

    int id_to_update;
    printf("\nEnter item ID to update: ");
    scanf("%d", &id_to_update);

    int update_index = -1;
    for(int i=0; i<num_items; i++) {
        if(inventory[i].id == id_to_update) {
            update_index = i;
        }
    }

    if(update_index == -1) {
        printf("\nItem with ID %d not found in inventory.\n", id_to_update);
    }
    else {
        // Get new data for selected item
        printf("\nEnter new name (hit enter to keep previous name): ");
        getchar(); // Clears input buffer
        fgets(inventory[update_index].name, 50, stdin);
        inventory[update_index].name[strcspn(inventory[update_index].name, "\n")] = '\0';
        printf("Enter new price (hit enter to keep previous price): $");
        char input[10];
        fgets(input, 10, stdin);
        if(strcmp(input, "\n") != 0) {
            inventory[update_index].price = atof(input);
        }
        printf("Enter new quantity (hit enter to keep previous quantity): ");
        fgets(input, 10, stdin);
        if(strcmp(input, "\n") != 0) {
            inventory[update_index].quantity = atoi(input);
        }

        printf("\nItem updated in inventory.\n");
    }
}

void display_inventory(Item inventory[], int num_items) {
    if(num_items == 0) {
        printf("\nInventory is empty.\n");
        return;
    }

    printf("\n%-5s%-20s%-10s%s\n", "ID", "Name", "Price ($)", "Quantity");
    printf("------------------------------------------------\n");

    for(int i=0; i<num_items; i++) {
        printf("%-5d%-20s$%-9.2f%-d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void write_to_file(Item inventory[], int num_items) {
    FILE *fp = fopen("inventory.txt", "w");

    if(fp != NULL) {
        fprintf(fp, "%d\n", num_items);
        for(int i=0; i<num_items; i++) {
            fprintf(fp, "%d %s %.2f %d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
        }

        fclose(fp);
        printf("\nInventory written to file.\n");
    }
    else {
        printf("\nError writing to file.\n");
    }
}

void read_from_file(Item inventory[], int *num_items) {
    FILE *fp = fopen("inventory.txt", "r");

    if(fp != NULL) {
        fscanf(fp, "%d", num_items);
        for(int i=0; i<*num_items; i++) {
            fscanf(fp, "%d %[^\n] %f %d", &inventory[i].id, inventory[i].name, &inventory[i].price, &inventory[i].quantity);
        }

        fclose(fp);
        printf("\nInventory loaded from file.\n");
    }
    else {
        printf("\nFile not found. Starting with empty inventory.\n");
        *num_items = 0;
    }
}