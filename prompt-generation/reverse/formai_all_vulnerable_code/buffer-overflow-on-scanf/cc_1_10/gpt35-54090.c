//FormAI DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100 // Maximum number of products the inventory can hold

// Structure for storing product details
typedef struct _product {
    char name[20];
    int id;
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS]; // Global variable to hold the inventory

int n_products = 0; // Global variable to track the number of products in the inventory

// Function to add a product to the inventory
void add_product(char name[], int id, int quantity, float price) {
    if (n_products >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }
    Product p;
    strcpy(p.name, name);
    p.id = id;
    p.quantity = quantity;
    p.price = price;
    inventory[n_products++] = p;
    printf("Added product '%s' with ID %d to the inventory.\n", name, id);
};

// Function to display the details of a product
void display_product(Product p) {
    printf("Name: %s\n", p.name);
    printf("ID: %d\n", p.id);
    printf("Quantity: %d\n", p.quantity);
    printf("Price: %.2f\n", p.price);
};

// Function to search for a product by its ID
void search_by_id(int id) {
    int found = 0;
    for (int i = 0; i < n_products; i++) {
        if (inventory[i].id == id) {
            display_product(inventory[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
};

// Function to remove a product from the inventory
void remove_product(int id) {
    int found = 0;
    for (int i = 0; i < n_products; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < n_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            n_products--;
            printf("Removed product with ID %d from the inventory.\n", id);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product with ID %d not found.\n", id);
    }
};

// Function to display the entire inventory
void display_inventory() {
    printf("Inventory:\n");
    for (int i = 0; i < n_products; i++) {
        display_product(inventory[i]);
        printf("\n");
    }
};

int main() {
    int choice, id, quantity;
    char name[20];
    float price;
    while (1) {
        printf("Enter choice:\n");
        printf("1. Add product\n");
        printf("2. Search by ID\n");
        printf("3. Remove product\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                add_product(name, id, quantity, price);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                search_by_id(id);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                remove_product(id);
                break;
            case 4:
                display_inventory();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}