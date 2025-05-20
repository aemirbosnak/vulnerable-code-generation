//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>

// Define struct for inventory item
typedef struct {
    int item_number;
    char item_name[20];
    int qty_in_stock;
    int min_qty;
    float price;
} inventory_item;

// Function to display menu options
void display_menu() {
    printf("\nWarehouse Management System\n");
    printf("---------------------------\n");
    printf("1. Add new item\n");
    printf("2. Update item quantity\n");
    printf("3. Update minimum quantity\n");
    printf("4. Update item price\n");
    printf("5. View item details\n");
    printf("6. Display all items\n");
    printf("7. Exit\n");
}

// Function to add new item to inventory
void add_item(inventory_item inventory[], int *num_items) {
    int item_num = *num_items;
    printf("\nEnter the following details for the new item:\n");
    printf("Item name: ");
    scanf("%s", inventory[item_num].item_name);
    printf("Quantity in stock: ");
    scanf("%d", &inventory[item_num].qty_in_stock);
    printf("Minimum quantity for reorder: ");
    scanf("%d", &inventory[item_num].min_qty);
    printf("Price per unit: ");
    scanf("%f", &inventory[item_num].price);
    // Assign a unique item number for the new item
    inventory[item_num].item_number = item_num + 1;
    *num_items += 1;
    printf("\nNew item added successfully!\n");
}

// Function to update quantity of existing item
void update_qty(inventory_item inventory[], int num_items) {
    int item_num;
    printf("\nEnter item number to update: ");
    scanf("%d", &item_num);
    if(item_num > num_items || item_num < 1) {
        printf("Invalid item number entered.\n");
    }
    else {
        printf("Current quantity in stock: %d\n", inventory[item_num-1].qty_in_stock);
        printf("Enter new quantity: ");
        scanf("%d", &inventory[item_num-1].qty_in_stock);
        printf("\nQuantity updated successfully!\n");
    }
}

// Function to update minimum quantity for reorder of existing item
void update_min_qty(inventory_item inventory[], int num_items) {
    int item_num;
    printf("\nEnter item number to update: ");
    scanf("%d", &item_num);
    if(item_num > num_items || item_num < 1) {
        printf("Invalid item number entered.\n");
    }
    else {
        printf("Current minimum quantity for reorder: %d\n", inventory[item_num-1].min_qty);
        printf("Enter new minimum quantity: ");
        scanf("%d", &inventory[item_num-1].min_qty);
        printf("\nMinimum quantity updated successfully!\n");
    }
}

// Function to update price per unit of existing item
void update_price(inventory_item inventory[], int num_items) {
    int item_num;
    printf("\nEnter item number to update: ");
    scanf("%d", &item_num);
    if(item_num > num_items || item_num < 1) {
        printf("Invalid item number entered.\n");
    }
    else {
        printf("Current price per unit: %.2f\n", inventory[item_num-1].price);
        printf("Enter new price per unit: ");
        scanf("%f", &inventory[item_num-1].price);
        printf("\nPrice updated successfully!\n");
    }
}

// Function to view details of existing item
void view_item(inventory_item inventory[], int num_items) {
    int item_num;
    printf("\nEnter item number to view: ");
    scanf("%d", &item_num);
    if(item_num > num_items || item_num < 1) {
        printf("Invalid item number entered.\n");
    }
    else {
        printf("Item Number: %d\n", inventory[item_num-1].item_number);
        printf("Item Name: %s\n", inventory[item_num-1].item_name);
        printf("Quantity in Stock: %d\n", inventory[item_num-1].qty_in_stock);
        printf("Minimum Quantity for Reorder: %d\n", inventory[item_num-1].min_qty);
        printf("Price per Unit: %.2f\n", inventory[item_num-1].price);
    }
}

// Function to display all items in inventory
void display_all_items(inventory_item inventory[], int num_items) {
    printf("\n----------------------------------\n");
    printf("| Item No. | Item Name | Quantity |");
    printf(" Min Qty | Price/Unit |\n");
    printf("----------------------------------\n");
    for(int i=0; i<num_items; i++) {
        printf("|%10d|%11s|%9d|%9d|%12.2f|\n", inventory[i].item_number, inventory[i].item_name, inventory[i].qty_in_stock, inventory[i].min_qty, inventory[i].price);
        printf("----------------------------------\n");
    }
}

int main() {
    int num_items = 0;
    inventory_item inventory[50];
    int choice;
    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_item(inventory, &num_items);
                break;
            case 2:
                update_qty(inventory, num_items);
                break;
            case 3:
                update_min_qty(inventory, num_items);
                break;
            case 4:
                update_price(inventory, num_items);
                break;
            case 5:
                view_item(inventory, num_items);
                break;
            case 6:
                display_all_items(inventory, num_items);
                break;
            case 7:
                printf("\nGoodbye!\n");
                return 0;
            default:
                printf("Invalid choice entered.\n");
        }
    }
    return 0;
}