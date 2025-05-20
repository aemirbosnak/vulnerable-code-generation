//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product structure
struct Product {
    char name[100];
    int id;
    float price;
    int quantity;
};

// Global variables
struct Product inventory[100];
int num_products = 0;

// Function prototypes
void add_product();
void display_inventory();
void sell_product();

int main() {
    int choice;
    // Menu
    while (1) {
        printf("PRODUCT INVENTORY SYSTEM MENU\n");
        printf("1. Add Product to Inventory\n");
        printf("2. Display Inventory\n");
        printf("3. Sell Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                sell_product();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}

// Add product to inventory function
void add_product() {
    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);
    printf("Enter product id: ");
    scanf("%d", &inventory[num_products].id);
    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);
    printf("Enter quantity of product: ");
    scanf("%d", &inventory[num_products].quantity);
    num_products++;
    printf("Product successfully added!\n");
}

// Display inventory function
void display_inventory() {
    if (num_products == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("PRODUCT INVENTORY\n");
    printf("--------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "Product Name", "Product ID", "Price", "Quantity");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("| %-20s | %-10d | %-10.2f | %-10d |\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
    }
    printf("--------------------------------------------------------\n");
}

// Sell product function
void sell_product() {
    int sell_id, sell_quantity, found = 0;
    printf("Enter product id to sell: ");
    scanf("%d", &sell_id);
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == sell_id) {
            printf("Enter quantity to sell: ");
            scanf("%d", &sell_quantity);
            if (sell_quantity <= inventory[i].quantity) {
                inventory[i].quantity -= sell_quantity;
                printf("%d %s sold successfully for %.2f each!\n", sell_quantity, inventory[i].name, inventory[i].price);
                found = 1;
                break;
            } else {
                printf("Not enough quantity in inventory!\n");
                found = 1;
                break;
            }
        }
    }
    if (found == 0) {
        printf("Product not found!\n");
    }
}