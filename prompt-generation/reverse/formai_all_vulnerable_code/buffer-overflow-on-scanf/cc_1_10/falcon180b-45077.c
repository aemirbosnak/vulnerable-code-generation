//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// Product struct
typedef struct {
    char name[100];
    int quantity;
    double price;
} Product;

// Function to add a product
void addProduct(Product *products, int *numProducts) {
    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);
    printf("Enter product price: ");
    scanf("%lf", &products[*numProducts].price);
    (*numProducts)++;
}

// Function to display products
void displayProducts(Product *products, int numProducts) {
    printf("\nProduct List:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2lf\n", products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to update product quantity
void updateQuantity(Product *products, int numProducts, char *name) {
    printf("Enter new quantity for %s: ", name);
    scanf("%d", &products[numProducts - 1].quantity);
}

// Function to calculate total value of inventory
double calculateTotalValue(Product *products, int numProducts) {
    double totalValue = 0.0;
    for (int i = 0; i < numProducts; i++) {
        totalValue += products[i].quantity * products[i].price;
    }
    return totalValue;
}

int main() {
    int numProducts = 0;
    Product products[100];

    // Add products
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);
    addProduct(products, &numProducts);

    // Display products
    displayProducts(products, numProducts);

    // Update quantity
    char name[100];
    printf("Enter product name to update quantity: ");
    scanf("%s", name);
    updateQuantity(products, numProducts, name);

    // Display updated products
    displayProducts(products, numProducts);

    // Calculate total value of inventory
    double totalValue = calculateTotalValue(products, numProducts);
    printf("\nTotal value of inventory: $%.2lf\n", totalValue);

    return 0;
}