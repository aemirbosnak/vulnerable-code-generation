//FormAI DATASET v1.0 Category: Product Inventory System ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Define max size of products array and product name string
#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Define Product struct
struct Product {
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;
};

int num_products = 0; // Global variable to keep track of number of products in inventory
struct Product products[MAX_PRODUCTS]; // Global array of products

/* Define functions to add, remove, and update products */

void addProduct() {
    // Prompt user for product name, price, and quantity
    char name[MAX_NAME_LENGTH];
    double price;
    int quantity;
    printf("Enter product name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline
    printf("Enter product price: ");
    scanf("%lf", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    getchar(); // Consume trailing newline from scanf

    // Create new Product struct with user input and add to global array
    struct Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.price = price;
    newProduct.quantity = quantity;
    products[num_products] = newProduct;
    num_products++;

    printf("Added product to inventory!\n");
}

void removeProduct() {
    // Prompt user for product name to remove
    char name[MAX_NAME_LENGTH];
    printf("Enter name of product to remove: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    // Search for product with matching name and remove from global array
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Removed product from inventory!\n");
            int j;
            for (j = i; j < num_products - 1; j++) { // Shift remaining products down in array to fill empty slot
                products[j] = products[j+1];
            }
            num_products--;
            return;
        }
    }
    printf("Product not found in inventory.\n");
}

void updateProduct() {
    // Prompt user for product name to update
    char name[MAX_NAME_LENGTH];
    printf("Enter name of product to update: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline

    // Search for product with matching name and prompt user for new values
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("Enter new price: ");
            scanf("%lf", &products[i].price);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            getchar(); // Consume trailing newline from scanf

            printf("Updated product in inventory!\n");
            return;
        }
    }
    printf("Product not found in inventory.\n");
}

/* Define function to print entire inventory */

void printInventory() {
    printf("Name\tPrice\tQuantity\n");
    int i;
    for (i = 0; i < num_products; i++) {
        printf("%s\t%.2lf\t%d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

/* Main function to prompt user for actions */

int main() {
    int choice = 0;
    while (choice != 5) { // Loop until user selects option to exit
        printf("\n1. Add product\n2. Remove product\n3. Update product\n4. Print inventory\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume trailing newline from scanf

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                printInventory();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}