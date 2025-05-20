//FormAI DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// define struct for product information
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// declare function to add a new product
void addProduct(Product *inventory, int *count) {
    Product product;
    printf("Enter Product ID: ");
    scanf("%d", &product.id);
    printf("Enter Product Name: ");
    scanf("%s", product.name);
    printf("Enter Product Quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter Product Price: ");
    scanf("%f", &product.price);
    // add product to inventory
    inventory[*count] = product;
    *count += 1;
    printf("Product added successfully!\n");
}

// declare function to print all products in inventory
void printProducts(Product *inventory, int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
    } else {
        printf("Product ID\tProduct Name\tProduct Quantity\tProduct Price\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

// declare function to search for a product by ID
void searchProduct(Product *inventory, int count) {
    int id, found = 0;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Product ID\tProduct Name\tProduct Quantity\tProduct Price\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

// declare function to update product information by ID
void updateProduct(Product *inventory, int count) {
    int id, found = 0;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Enter New Product Name: ");
            scanf("%s", inventory[i].name);
            printf("Enter New Product Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter New Product Price: ");
            scanf("%f", &inventory[i].price);
            found = 1;
            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

// declare function to delete a product by ID
void deleteProduct(Product *inventory, int *count) {
    int id, found = 0;
    printf("Enter Product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            *count -= 1;
            found = 1;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product not found.\n");
    }
}

int main() {
    Product inventory[50];
    int count = 0, choice;
    printf("Welcome to the Product Inventory System!\n");
    while (1) {
        // print main menu
        printf("\nMain Menu:\n");
        printf("1. Add Product\n");
        printf("2. Print All Products\n");
        printf("3. Search for a Product\n");
        printf("4. Update Product Information\n");
        printf("5. Delete Product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // perform action based on user choice
        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                printProducts(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                updateProduct(inventory, count);
                break;
            case 5:
                deleteProduct(inventory, &count);
                break;
            case 6:
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}