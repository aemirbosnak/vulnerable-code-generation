//FormAI DATASET v1.0 Category: Product Inventory System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// struct to hold product information
struct Product {
    int id;
    char name[50];
    int quantity;
    double price;
};

// function to display menu and get user choice
int getMenuChoice() {
    printf("Product Inventory System\n");
    printf("------------------------\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Update Product Quantity\n");
    printf("4. Delete Product\n");
    printf("5. Quit\n\n");
    printf("Please enter your choice (1-5): ");

    int choice;
    scanf("%d", &choice);
    getchar(); // consume newline character

    return choice;
}

// function to add a new product
void addProduct(struct Product* products, int numProducts) {
    printf("\nAdding Product\n");
    printf("--------------\n");
    
    struct Product newProduct;
    newProduct.id = numProducts + 1;

    printf("Product Name: ");
    fgets(newProduct.name, 50, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // remove newline character

    printf("Quantity: ");
    scanf("%d", &newProduct.quantity);

    printf("Price: ");
    scanf("%lf", &newProduct.price);

    products[numProducts] = newProduct;

    printf("\nProduct added!\n\n");
}

// function to view all products
void viewProducts(struct Product* products, int numProducts) {
    printf("\nProduct Inventory\n");
    printf("-----------------\n");

    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%-5d %-20s %-10d $%-10.2lf\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }

    printf("\n");
}

// function to update product quantity
void updateQuantity(struct Product* products, int numProducts) {
    printf("\nUpdating Product Quantity\n");
    printf("-------------------------\n");

    printf("Enter Product ID: ");
    int id;
    scanf("%d", &id);

    struct Product* product = NULL;

    // find product with matching id
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            product = &products[i];
            break;
        }
    }

    if (product == NULL) {
        printf("Product not found!\n\n");
        return;
    }

    printf("Current Quantity: %d\n", product->quantity);
    printf("New Quantity: ");
    int quantity;
    scanf("%d", &quantity);

    product->quantity = quantity;

    printf("\nQuantity updated!\n\n");
}

// function to delete a product
void deleteProduct(struct Product* products, int numProducts) {
    printf("\nDeleting Product\n");
    printf("----------------\n");

    printf("Enter Product ID: ");
    int id;
    scanf("%d", &id);

    int index = -1;

    // find index of product with matching id
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found!\n\n");
        return;
    }

    // shift all products after deleted product back one index
    for (int i = index; i < numProducts - 1; i++) {
        products[i] = products[i + 1];
    }

    printf("\nProduct deleted!\n\n");
}

int main() {
    struct Product products[100];
    int numProducts = 0;

    int choice;
    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                addProduct(products, numProducts);
                numProducts++;
                break;

            case 2:
                viewProducts(products, numProducts);
                break;

            case 3:
                updateQuantity(products, numProducts);
                break;

            case 4:
                deleteProduct(products, numProducts);
                numProducts--;
                break;

            case 5:
                printf("Thanks for using the Product Inventory System!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}