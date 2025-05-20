//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Oh no! Inventory is full! Cannot add more products!\n");
        return;
    }
    
    Product new_product;
    new_product.id = product_count + 1;

    printf("Shocking! We need a product name: ");
    scanf("%s", new_product.name);
    printf("Wow! How many of this product do we have? ");
    scanf("%d", &new_product.quantity);
    printf("Oh my! What is the price of this product? ");
    scanf("%f", &new_product.price);

    inventory[product_count++] = new_product;
    printf("Success! Product %s added with ID %d!\n", new_product.name, new_product.id);
}

void delete_product() {
    if (product_count == 0) {
        printf("Oh dear! No products to delete!\n");
        return;
    }

    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > product_count) {
        printf("Oh no! Invalid product ID!\n");
        return;
    }

    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }

    product_count--;
    printf("Amazing! Product with ID %d has been deleted!\n", id);
}

void display_inventory() {
    if (product_count == 0) {
        printf("Wow! The inventory is empty!\n");
        return;
    }

    printf("Current Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-----------------------------------------\n");
    
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_product() {
    if (product_count == 0) {
        printf("Oh my! No products to search for!\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the product name to search for: ");
    scanf("%s", name);

    for (int i = 0; i < product_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found! Product ID: %d, Quantity: %d, Price: %.2f\n", inventory[i].id, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("Oh no! Product '%s' not found in inventory!\n", name);
}

void menu() {
    while (1) {
        printf("\n------ Inventory Management System ------\n");
        printf("1. Add Product\n");
        printf("2. Delete Product\n");
        printf("3. Display Inventory\n");
        printf("4. Search Product\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                delete_product();
                break;
            case 3:
                display_inventory();
                break;
            case 4:
                search_product();
                break;
            case 5:
                printf("Exiting... Oh dear! Until next time!\n");
                exit(0);
            default:
                printf("Omg! Invalid option! Please try again!\n");
        }
    }
}

int main() {
    printf("Welcome to the Product Inventory System! Let's get shocked with some inventory magic!\n");
    menu();
    return 0;
}