//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Structure for storing product details
struct product {
    char name[50];
    int id;
    int price;
    int quantity;
};

// Array to store products
struct product products[MAX_PRODUCTS];

// Function to add a new product to inventory
void add_product() {
    // Check if there is space in array
    int i, flag = 0;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(products[i].id == 0) {
            flag = 1;
            break;
        }
    }
    if(!flag) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }
    // Get product details from user
    struct product p;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product price: ");
    scanf("%d", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    // Check if product already exists
    for(i = 0; i < MAX_PRODUCTS; i++)
        if(products[i].id == p.id) {
            printf("Product with ID %d already exists.\n", p.id);
            return;
        }
    // Add new product to array
    products[i] = p;
    printf("Product added to inventory.\n");
}

// Function to remove product from inventory
void remove_product() {
    int id, i, flag = 0;
    printf("Enter product ID: ");
    scanf("%d", &id);
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(products[i].id == id) {
            flag = 1;
            products[i].id = 0;
            products[i].price = 0;
            products[i].quantity = 0;
            memset(products[i].name, 0, sizeof(products[i].name));
            break;
        }
    }
    if(flag)
        printf("Product removed from inventory.\n");
    else
        printf("Product with ID %d not found in inventory.\n", id);
}

// Function to update product details
void update_product() {
    int id, i, flag = 0;
    printf("Enter product ID: ");
    scanf("%d", &id);
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(products[i].id == id) {
            flag = 1;
            printf("Current details of product with ID %d:\n", id);
            printf("Name: %s\n", products[i].name);
            printf("Price: %d\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);
            printf("Enter new details:\n");
            printf("Name: ");
            scanf("%s", products[i].name);
            printf("Price: ");
            scanf("%d", &products[i].price);
            printf("Quantity: ");
            scanf("%d", &products[i].quantity);
            break;
        }
    }
    if(flag)
        printf("Product details updated.\n");
    else
        printf("Product with ID %d not found in inventory.\n", id);
}

// Function to display inventory
void display_inventory() {
    printf("ID\tName\tPrice\tQuantity\n");
    int i;
    for(i = 0; i < MAX_PRODUCTS; i++) {
        if(products[i].id != 0)
            printf("%d\t%s\t%d\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    int choice;
    printf("Welcome to Product Inventory System\n");
    while(1) {
        printf("\nMenu:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product details\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                display_inventory();
                break;
            case 5:
                printf("Thank you for using Product Inventory System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}