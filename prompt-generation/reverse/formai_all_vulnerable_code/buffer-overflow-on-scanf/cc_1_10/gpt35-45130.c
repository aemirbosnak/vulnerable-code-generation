//FormAI DATASET v1.0 Category: Product Inventory System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100    // maximum number of products in inventory
#define MAX_NAME_LEN 50     // maximum length of product name
#define MAX_DESC_LEN 100    // maximum length of product description
#define MAX_PRICE_LEN 10    // maximum length of product price

// structure to hold product information
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    double price;
    int quantity;
} Product;

// function to display the main menu and read user input
int get_menu_choice() {
    int choice;
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. List Products\n");
    printf("3. Search Products\n");
    printf("4. Update Product Quantity\n");
    printf("5. Delete Product\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// function to display a product
void print_product(Product product) {
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Description: %s\n", product.description);
    printf("Price: $%.2lf\n", product.price);
    printf("Quantity: %d\n", product.quantity);
    printf("---------------------------\n");
}

// function to add a product to the inventory
void add_product(Product *inventory, int *num_products) {
    if (*num_products == MAX_PRODUCTS) {
        printf("Error: Inventory is full\n");
        return;
    }
    printf("Enter product name: ");
    scanf("%s", inventory[*num_products].name);
    printf("Enter product description: ");
    scanf("%s", inventory[*num_products].description);
    printf("Enter product price: ");
    scanf("%lf", &inventory[*num_products].price);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[*num_products].quantity);
    inventory[*num_products].id = (*num_products) + 1;
    (*num_products)++;
    printf("Product added successfully\n");
}

// function to list all products in the inventory
void list_products(Product *inventory, int num_products) {
    if (num_products == 0) {
        printf("Inventory is empty\n");
        return;
    }
    printf("Products in Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        print_product(inventory[i]);
    }
}

// function to search for a product by name in the inventory
Product* search_products(Product *inventory, int num_products, char *search_term) {
    for (int i = 0; i < num_products; i++) {
        if (strstr(inventory[i].name, search_term) != NULL) {
            return &inventory[i];
        }
    }
    return NULL;
}

// function to update the quantity of a product in the inventory
void update_quantity(Product *inventory, int num_products, int product_id, int quantity) {
    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == product_id) {
            inventory[i].quantity += quantity;
            printf("Quantity updated successfully\n");
            return;
        }
    }
    printf("Error: Product not found\n");
}

// function to delete a product from the inventory
void delete_product(Product *inventory, int *num_products, int product_id) {
    for (int i = 0; i < *num_products; i++) {
        if (inventory[i].id == product_id) {
            for (int j = i; j < (*num_products) - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*num_products)--;
            printf("Product deleted successfully\n");
            return;
        }
    }
    printf("Error: Product not found\n");
}

int main() {
    Product inventory[MAX_PRODUCTS];   // array to hold products in inventory
    int num_products = 0;              // number of products in inventory
    char search_term[MAX_NAME_LEN];    // search term for product search
    int product_id, quantity;          // parameters for product update and delete

    int choice;
    do {
        choice = get_menu_choice();
        switch (choice) {
            case 1:
                add_product(inventory, &num_products);
                break;
            case 2:
                list_products(inventory, num_products);
                break;
            case 3:
                printf("Enter search term: ");
                scanf("%s", search_term);
                Product *product = search_products(inventory, num_products, search_term);
                if (product != NULL) {
                    print_product(*product);
                } else {
                    printf("Product not found\n");
                }
                break;
            case 4:
                printf("Enter product ID: ");
                scanf("%d", &product_id);
                printf("Enter quantity to add/remove (negative value to remove): ");
                scanf("%d", &quantity);
                update_quantity(inventory, num_products, product_id, quantity);
                break;
            case 5:
                printf("Enter product ID: ");
                scanf("%d", &product_id);
                delete_product(inventory, &num_products, product_id);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Error: Invalid choice\n");
                break;
        }
    } while (choice != 6);

    return 0;
}