//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// define a struct to hold product data
struct Product {
    int id;
    char name[30];
    int quantity;
    float price;
};

// an array to hold all products in inventory
struct Product inventory[MAX_PRODUCTS];

// keep track of how many products are currently in the inventory
int num_products = 0;

// add a new product to the inventory
void add_product() {
    if(num_products >= MAX_PRODUCTS) {
        printf("Cannot add more products, inventory is full.\n");
        return;
    }
    struct Product new_product;
    printf("Enter product name: ");
    scanf("%s", new_product.name);
    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);
    printf("Enter product price: ");
    scanf("%f", &new_product.price);
    new_product.id = num_products + 1; // automatically assign ID based on order added
    inventory[num_products] = new_product;
    num_products++;
    printf("Product added.\n");
}

// update the quantity of an existing product in the inventory
void update_quantity() {
    int product_id, new_quantity;
    printf("Enter product ID: ");
    scanf("%d", &product_id);
    if(product_id < 1 || product_id > num_products) {
        printf("Invalid product ID.\n");
        return;
    }
    printf("Enter new quantity: ");
    scanf("%d", &new_quantity);
    inventory[product_id-1].quantity = new_quantity;
    printf("Quantity updated.\n");
}

// display all products in the inventory
void display_inventory() {
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add new product\n");
        printf("2. Update quantity of existing product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                update_quantity();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}