//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
/******************************************************************************
 ** Program name: Medical Store Management System
 ** Author: Claude Shannon
 ** Date: June 25, 2021
 ** Description: This program allows a medical store to manage their inventory and sales.
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure for an Item in Inventory
typedef struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

// Structure of an individual Sale Transaction
typedef struct Sale {
    int id;
    int item_id;
    int quantity;
    float total_price;
} Sale;

// Function to display menu options
void display_menu() {
    printf("\nWelcome to Medical Store Management System!\n");
    printf("Select an option: \n");
    printf("1. Add item to inventory\n");
    printf("2. Remove item from inventory\n");
    printf("3. Display inventory\n");
    printf("4. Make a sale\n");
    printf("5. Display sales\n");
    printf("6. Exit\n");
}

int main() {
    // Initialize inventory with 0 items
    Item inventory[MAX_ITEMS];
    int num_items = 0;

    // Initialize sales with 0 transactions
    Sale sales[MAX_ITEMS];
    int num_sales = 0;

    // Loop through menu options until user chooses to exit
    int choice = 0;
    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Item to Inventory
                printf("Enter name of Item: ");
                char name[50];
                scanf("%s", name);

                printf("Enter quantity of Item: ");
                int quantity;
                scanf("%d", &quantity);

                printf("Enter price of Item: ");
                float price;
                scanf("%f", &price);

                Item item;
                item.id = num_items + 1;
                strcpy(item.name, name);
                item.quantity = quantity;
                item.price = price;
                inventory[num_items] = item;
                num_items++;

                printf("Item added successfully!\n");
                break;

            case 2:
                // Remove Item from Inventory
                printf("Enter ID of Item to remove: ");
                int item_id;
                scanf("%d", &item_id);

                // Find Item in Inventory
                for (int i = 0; i < num_items; i++) {
                    if (inventory[i].id == item_id) {
                        // Remove Item
                        for (int j = i; j < num_items - 1; j++) {
                            inventory[j] = inventory[j + 1];
                        }
                        num_items--;
                        printf("Item removed successfully!\n");
                        break;
                    }
                }
                break;

            case 3:
                // Display Inventory
                printf("\nInventory:\n");
                printf("ID   Name\t\tQuantity\tPrice\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%-4d %-16s %-8d\t$%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;

            case 4:
                // Make a Sale
                printf("Enter ID of Item sold: ");
                scanf("%d", &item_id);

                // Find Item in Inventory
                int item_index = -1;
                for (int i = 0; i < num_items; i++) {
                    if (inventory[i].id == item_id) {
                        item_index = i;
                        break;
                    }
                }

                if (item_index == -1) {
                    printf("Item not found in inventory. Sale failed.\n");
                    break;
                }

                printf("Enter quantity of Item sold: ");
                scanf("%d", &quantity);

                if (inventory[item_index].quantity < quantity) {
                    printf("Not enough stock. Sale failed.\n");
                    break;
                }

                // Record Sale Transaction
                Sale sale;
                sale.id = num_sales + 1;
                sale.item_id = item_id;
                sale.quantity = quantity;
                sale.total_price = inventory[item_index].price * quantity;
                sales[num_sales] = sale;
                num_sales++;

                // Update Inventory
                inventory[item_index].quantity -= quantity;

                printf("Sale completed successfully!\n");
                break;

            case 5:
                // Display Sales
                printf("\nSales Transactions:\n");
                printf("ID   Item ID\t\tQuantity\tTotal Price\n");
                for (int i = 0; i < num_sales; i++) {
                    printf("%-4d %-16d %-8d\t$%.2f\n", sales[i].id, sales[i].item_id, sales[i].quantity, sales[i].total_price);
                }
                break;

            case 6:
                // Exit Program
                printf("\nGoodbye!\n");
                break;

            default:
                printf("\nInvalid Choice. Please try again!\n");
                break;
        }
    } while (choice != 6);

    return 0;
}