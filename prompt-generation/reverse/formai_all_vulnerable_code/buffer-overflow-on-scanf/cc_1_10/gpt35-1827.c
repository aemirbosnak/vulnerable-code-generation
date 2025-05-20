//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PROD_NUM 100

typedef struct {
    int prod_id;
    char prod_name[MAX_NAME_LEN];
    float prod_price;
} Product;

Product inventory[MAX_PROD_NUM]; // Initialize inventory array to hold products
int num_products = 0; // Initialize number of products in inventory

void addProduct() {
    // Adds a new product to inventory with user-inputted details
    
    Product new_product;
    printf("Enter product name: ");
    fgets(new_product.prod_name, MAX_NAME_LEN, stdin);
    printf("Enter product ID: ");
    scanf("%d", &new_product.prod_id);
    printf("Enter product price: ");
    scanf("%f", &new_product.prod_price);
    
    // add product to inventory
    inventory[num_products] = new_product;
    num_products++;
    printf("Product added successfully!\n");
}

void listProducts() {
    // Lists all products in inventory
    
    printf("Product ID\tProduct Name\tProduct Price\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d\t\t%s\t\t%.2f\n", inventory[i].prod_id, inventory[i].prod_name, inventory[i].prod_price);
    }
}

void searchProduct() {
    // Finds a product in inventory based on ID
    
    int search_id;
    printf("Enter product ID to search: ");
    scanf("%d", &search_id);
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].prod_id == search_id) {
            printf("Product ID\tProduct Name\tProduct Price\n");
            printf("%d\t\t%s\t\t%.2f\n", inventory[i].prod_id, inventory[i].prod_name, inventory[i].prod_price);
            return;
        }
    }
    printf("Product not found!\n");
}

int main() {
    int choice;
    do {
        printf("1. Add product\n");
        printf("2. List products\n");
        printf("3. Search for product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character from input buffer
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                listProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }
    } while (choice != 4);
    return 0;
}