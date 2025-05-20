//FormAI DATASET v1.0 Category: Product Inventory System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    char name[100];
    int id, quantity;
    float price;
} Product;

int num_products = 0;
Product products[MAX_PRODUCTS];

// Function prototypes
void addProduct();
void displayProducts();
void searchProduct();
void updateProduct();
void deleteProduct();

int main() {
    int choice;
    char ch;

    do {
        printf("\n\nProduct Inventory System");
        printf("\n------------------------");
        printf("\n1. Add Product");
        printf("\n2. Display All Products");
        printf("\n3. Search Product");
        printf("\n4. Update Product");
        printf("\n5. Delete Product");
        printf("\n6. Exit");

        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                updateProduct();
                break;

            case 5:
                deleteProduct();
                break;

            case 6:
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    return 0;
}

void addProduct() {
    Product product;
    printf("\nEnter Product Details");

    printf("\nEnter Product Name: ");
    scanf(" %[^\n]s", product.name);

    printf("\nEnter Product ID: ");
    scanf("%d", &product.id);

    printf("\nEnter Product Quantity: ");
    scanf("%d", &product.quantity);

    printf("\nEnter Product Price: ");
    scanf("%f", &product.price);

    products[num_products++] = product;

    printf("\nProduct Added Successfully!");
}

void displayProducts() {
    printf("\nList of Products");

    printf("\n%-15s %-15s %-15s %-15s", "Name", "ID", "Quantity", "Price");

    printf("\n----------------------------------------------------");

    for (int i = 0; i < num_products; ++i) {
        printf("\n%-15s %-15d %-15d %-15.2f",
            products[i].name, products[i].id, products[i].quantity, products[i].price);
    }
}

void searchProduct() {
    int id, index = -1;

    printf("\nEnter Product ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; ++i) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nProduct with ID %d not found!", id);
    } else {
        printf("\nProduct Found!");
        printf("\nProduct Details:");

        printf("\nName: %s", products[index].name);
        printf("\nID: %d", products[index].id);
        printf("\nQuantity: %d", products[index].quantity);
        printf("\nPrice: %.2f", products[index].price);
    }
}

void updateProduct() {
    int id, index = -1;

    printf("\nEnter Product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; ++i) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nProduct with ID %d not found!", id);
    } else {
        Product product;
        printf("\nEnter new Product Details");

        printf("\nEnter new Product Name: ");
        scanf(" %[^\n]s", product.name);

        printf("\nEnter new Product ID: ");
        scanf("%d", &product.id);

        printf("\nEnter new Product Quantity: ");
        scanf("%d", &product.quantity);

        printf("\nEnter new Product Price: ");
        scanf("%f", &product.price);

        products[index] = product;

        printf("\nProduct Updated Successfully!");
    }
}

void deleteProduct() {
    int id, index = -1;

    printf("\nEnter Product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < num_products; ++i) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nProduct with ID %d not found!", id);
    } else {
        for (int i = index; i < num_products - 1; ++i) {
            products[i] = products[i + 1];
        }

        num_products--;

        printf("\nProduct Deleted Successfully!");
    }
}