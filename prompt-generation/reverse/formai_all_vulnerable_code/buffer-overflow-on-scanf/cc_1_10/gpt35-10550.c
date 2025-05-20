//FormAI DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_CATEGORY_LENGTH 20

// Struct to hold a product's information
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float price;
    int stock;
} product;

// Function prototypes
void add_product(product products[], int *num_products);
void remove_product(product products[], int *num_products);
void search_product(product products[], int num_products);
void print_products(product products[], int num_products);

int main() {
    // Initialize array of products
    product products[MAX_PRODUCTS];
    int num_products = 0;

    // Show menu until user chooses to exit
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Search product\n");
        printf("4. Print all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                remove_product(products, &num_products);
                break;
            case 3:
                search_product(products, num_products);
                break;
            case 4:
                print_products(products, num_products);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_product(product products[], int *num_products) {
    // Check if max number of products has been reached
    if (*num_products >= MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
        return;
    }

    // Get user input for new product's information
    product new_product;
    new_product.id = (*num_products) + 1;
    printf("Enter name of product: ");
    scanf("%s", new_product.name);
    printf("Enter description of product: ");
    scanf("%s", new_product.description);
    printf("Enter category of product: ");
    scanf("%s", new_product.category);
    printf("Enter price of product: ");
    scanf("%f", &new_product.price);
    printf("Enter stock of product: ");
    scanf("%d", &new_product.stock);

    // Add product to array and increment num_products
    products[*num_products] = new_product;
    (*num_products)++;
    printf("Product added successfully.\n");
}

void remove_product(product products[], int *num_products) {
    // Get user input for product ID to remove
    int id;
    printf("Enter ID of product to remove: ");
    scanf("%d", &id);

    // Find index of product with given ID
    int index = -1;
    for (int i = 0; i < *num_products; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    // If product is not found, exit function
    if (index == -1) {
        printf("Error: Product not found.\n");
        return;
    }

    // Overwrite the product with the last product in the array and decrement num_products
    products[index] = products[*num_products - 1];
    (*num_products)--;
    printf("Product removed successfully.\n");
}

void search_product(product products[], int num_products) {
    // Get user input for search string
    char search_string[MAX_NAME_LENGTH];
    printf("Enter search string: ");
    scanf("%s", search_string);

    // Loop through each product and print any product that contains the search string in its name
    int num_results = 0;
    printf("Search Results:\n");
    for (int i = 0; i < num_products; i++) {
        if (strstr(products[i].name, search_string) != NULL) {
            printf("ID: %d, Name: %s, Description: %s, Category: %s, Price: %.2f, Stock: %d\n",
                    products[i].id, products[i].name, products[i].description, products[i].category,
                    products[i].price, products[i].stock);
            num_results++;
        }
    }

    // If no results are found, print message
    if (num_results == 0) {
        printf("No products found.\n");
    }
}

void print_products(product products[], int num_products) {
    // Loop through each product and print its information
    printf("All Products:\n");
    for (int i = 0; i < num_products; i++) {
        printf("ID: %d, Name: %s, Description: %s, Category: %s, Price: %.2f, Stock: %d\n",
                products[i].id, products[i].name, products[i].description, products[i].category,
                products[i].price, products[i].stock);
    }
}