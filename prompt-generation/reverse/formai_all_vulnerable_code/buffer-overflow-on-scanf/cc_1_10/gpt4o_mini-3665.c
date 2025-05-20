//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int *numProducts) {
    if (*numProducts >= MAX_PRODUCTS) {
        printf("Product inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    printf("Enter product ID: ");
    scanf("%d", &newProduct.id);
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    products[*numProducts] = newProduct;
    (*numProducts)++;

    printf("Product added successfully!\n");
}

void displayProducts(const Product products[], int numProducts) {
    printf("\nProduct Inventory:\n");
    printf("------------------------------------------------\n");
    printf("| ID  | Name               | Quantity | Price   |\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < numProducts; i++) {
        printf("| %-3d | %-18s | %-8d | $%-6.2f |\n", 
                products[i].id, 
                products[i].name, 
                products[i].quantity, 
                products[i].price);
    }

    printf("------------------------------------------------\n");
}

void updateProduct(Product products[], int numProducts) {
    int id;
    printf("Enter product ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("Updating product: %s\n", products[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &products[i].price);
            printf("Product updated successfully!\n");
            return;
        }
    }

    printf("Product ID not found!\n");
}

void deleteProduct(Product products[], int *numProducts) {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *numProducts; i++) {
        if (products[i].id == id) {
            for (int j = i; j < *numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            (*numProducts)--;
            printf("Product deleted successfully!\n");
            return;
        }
    }

    printf("Product ID not found!\n");
}

int main() {
    Product products[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;

    while (1) {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                displayProducts(products, numProducts);
                break;
            case 3:
                updateProduct(products, numProducts);
                break;
            case 4:
                deleteProduct(products, &numProducts);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}