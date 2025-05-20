//FormAI DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_SIZE 50

typedef struct {
    int product_id;
    char product_name[MAX_NAME_SIZE];
    int quantity;
    float price;
} Product;

Product product_inventory[MAX_PRODUCTS];

int num_products = 0;

void addProduct() {
    if (num_products == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached.\n");
    } else {
        Product newProduct;
        newProduct.product_id = num_products + 1;
        
        printf("Enter the name of the product: ");
        fgets(newProduct.product_name, MAX_NAME_SIZE, stdin);
        newProduct.product_name[strcspn(newProduct.product_name, "\n")] = 0;
        
        printf("Enter the quantity of the product: ");
        scanf("%d", &newProduct.quantity);
        
        printf("Enter the price of the product: ");
        scanf("%f", &newProduct.price);
        
        product_inventory[num_products] = newProduct;
        num_products++;
        printf("Product added successfully.\n");
    }
}

void listProducts() {
    if (num_products == 0) {
        printf("No products in inventory.\n");
    } else {
        printf("Product ID | Name | Quantity | Price\n");
        for (int i = 0; i < num_products; i++) {
            printf("%d | %s | %d | $%.2f\n", product_inventory[i].product_id, product_inventory[i].product_name, product_inventory[i].quantity, product_inventory[i].price);
        }
    }
}

void removeProduct() {
    int product_id;
    printf("Enter the ID of the product to remove: ");
    scanf("%d", &product_id);

    int index_to_remove = -1;
    for (int i = 0; i < num_products; i++) {
        if (product_inventory[i].product_id == product_id) {
            index_to_remove = i;
            break;
        }
    }

    if (index_to_remove == -1) {
        printf("Product ID not found.\n");
    } else {
        for (int i = index_to_remove; i < num_products - 1; i++) {
            product_inventory[i] = product_inventory[i + 1];
        }
        num_products--;
        printf("Product removed successfully.\n");
    }
}

int main() {
    int choice = 0;
    while (1) {
        printf("Choose an option:\n");
        printf("[1] Add product\n");
        printf("[2] List products\n");
        printf("[3] Remove product\n");
        printf("[4] Exit\n");
        printf(">>> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                listProducts();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
        getchar(); // clear stdin buffer
        printf("\n");
    }
    return 0;
}