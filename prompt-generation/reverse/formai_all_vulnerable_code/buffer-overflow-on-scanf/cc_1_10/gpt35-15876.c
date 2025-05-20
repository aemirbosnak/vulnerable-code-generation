//FormAI DATASET v1.0 Category: Product Inventory System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the product name
#define MAX_NAME_LENGTH 50

// Define the maximum number of products
#define MAX_PRODUCTS 100

// Define the product struct
struct product {
    int code; // The product code
    char name[MAX_NAME_LENGTH]; // The product name
    float price; // The product price
    int quantity; // The product quantity
};

// Define the array of products
struct product products[MAX_PRODUCTS];

// Define the number of products currently in the inventory
int num_products = 0;

// Function to add a product to the inventory
void add_product() {
    struct product p;
    printf("Enter product code: ");
    scanf("%d", &p.code);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    
    // Add the product to the array of products
    products[num_products] = p;
    num_products++;
}

// Function to display all the products in the inventory
void display_all_products() {
    printf("Product Code\tProduct Name\tProduct Price\tProduct Quantity\n");
    for(int i=0; i<num_products; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t%d\n", products[i].code, products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to search for a product by its name
void search_product() {
    char name[MAX_NAME_LENGTH];
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Product Code\tProduct Name\tProduct Price\tProduct Quantity\n");
    for(int i=0; i<num_products; i++) {
        if(strcmp(products[i].name, name) == 0) {
            printf("%d\t\t%s\t\t%.2f\t\t%d\n", products[i].code, products[i].name, products[i].price, products[i].quantity);
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to update the quantity of a product in the inventory
void update_product_quantity() {
    int code;
    printf("Enter product code: ");
    scanf("%d", &code);
    for(int i=0; i<num_products; i++) {
        if(products[i].code == code) {
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Product quantity updated.\n");
            return;
        }
    }
    printf("Product not found.\n");    
}

// Main function
int main() {
    int option;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search for a product\n");
        printf("4. Update product quantity\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_product();
                break;
            case 2:
                display_all_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                update_product_quantity();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    } while(option != 5);
    return 0;
}