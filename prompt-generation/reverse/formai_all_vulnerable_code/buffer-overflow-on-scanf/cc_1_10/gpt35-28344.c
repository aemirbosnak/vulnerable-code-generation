//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure of the inventory item
typedef struct {
    char item_name[30];
    int item_id;
    int available_quantity;
    float item_price;
} inventory_item;

// Function to add a new item to the inventory
void add_item(inventory_item *items, int *count) {
    printf("Enter the name of the item: ");
    scanf("%s", items[*count].item_name);
    printf("Enter the item ID: ");
    scanf("%d", &items[*count].item_id);
    printf("Enter the available quantity: ");
    scanf("%d", &items[*count].available_quantity);
    printf("Enter the price of the item: ");
    scanf("%f", &items[*count].item_price);
    (*count)++;
}

// Function to display all the items in the inventory
void display_items(inventory_item *items, int count) {
    printf("\nItem ID\tItem Name\t\tAvailable Quantity\tItem Price\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t\t\t%d\t\t\t%.2f\n", items[i].item_id, items[i].item_name, items[i].available_quantity, items[i].item_price);
    }
}

// Function to update the quantity of an item in the inventory
void update_item_quantity(inventory_item *items, int count, int item_id, int quantity) {
    for(int i = 0; i < count; i++) {
        if(items[i].item_id == item_id) {
            items[i].available_quantity += quantity;
            printf("Item quantity updated successfully!\n");
            return;
        }
    }
    printf("Item does not exist in inventory!\n");    
}

// Main function
int main() {
    inventory_item items[100];
    int choice, count = 0;
    do {
        printf("\n\n***** C PRODUCT INVENTORY SYSTEM *****\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
        printf("3. Update Item Quantity\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(items, &count);
                break;
            case 2:
                display_items(items, count);
                break;
            case 3:
                {
                    int item_id, quantity;
                    printf("Enter the item ID: ");
                    scanf("%d", &item_id);
                    printf("Enter the quantity to add/subtract: ");
                    scanf("%d", &quantity);
                    update_item_quantity(items, count, item_id, quantity);
                    break;
                }
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 4);
    return 0;
}