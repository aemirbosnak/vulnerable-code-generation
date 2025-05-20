//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing product information
typedef struct {
    char name[100];
    int quantity;
    float price;
} Product;

// Define the structure for storing purchase information
typedef struct {
    char name[100];
    int quantity;
    float total_cost;
} Purchase;

// Function to add a new product to the inventory
void addProduct(Product *products, int *num_products) {
    printf("\nEnter the name of the product: ");
    scanf("%s", products[*num_products].name);
    printf("Enter the quantity of the product: ");
    scanf("%d", &products[*num_products].quantity);
    printf("Enter the price of the product: ");
    scanf("%f", &products[*num_products].price);
    (*num_products)++;
    printf("\nProduct added successfully!\n");
}

// Function to display the products currently in the inventory
void displayProducts(Product *products, int num_products) {
    if (num_products == 0) {
        printf("\nNo products in the inventory.\n");
        return;
    }
    printf("\n---Products in Inventory---\n");
    for (int i = 0; i < num_products; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n", i+1, products[i].name, products[i].quantity, products[i].price);
    }
}

// Function to sell a product and add the purchase to the purchase history
void sellProduct(Product *products, int num_products, Purchase *purchases, int *num_purchases) {
    if (num_products == 0) {
        printf("\nNo products in the inventory.\n");
        return;
    }
    printf("\nEnter the name of the product: ");
    char product_name[100];
    scanf("%s", product_name);

    int product_index = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, product_name) == 0) {
            product_index = i;
            break;
        }
    }
    if (product_index == -1) {
        printf("\nProduct not found in inventory.\n");
        return;
    }

    printf("Enter the quantity to sell: ");
    int sell_quantity;
    scanf("%d", &sell_quantity);

    if (sell_quantity > products[product_index].quantity) {
        printf("\nNot enough quantity available in inventory.\n");
        return;
    }

    products[product_index].quantity -= sell_quantity;
    float total_cost = products[product_index].price * sell_quantity;
    strcpy(purchases[*num_purchases].name, product_name);
    purchases[*num_purchases].quantity = sell_quantity;
    purchases[*num_purchases].total_cost = total_cost;
    (*num_purchases)++;
    printf("\nProduct sold successfully!\n");
}

// Function to display the purchase history
void displayPurchases(Purchase *purchases, int num_purchases) {
    if (num_purchases == 0) {
        printf("\nNo purchases made yet.\n");
        return;
    }
    printf("\n---Purchase History---\n");
    for (int i = 0; i < num_purchases; i++) {
        printf("Purchase %d: %s, Quantity: %d, Total Cost: %.2f\n", i+1, purchases[i].name, purchases[i].quantity, purchases[i].total_cost);
    }
}

int main() {
    Product products[100];
    Purchase purchases[100];
    int num_products = 0;
    int num_purchases = 0;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("\n\n---Menu---\n");
        printf("1. Add a Product to Inventory\n");
        printf("2. Display Products in Inventory\n");
        printf("3. Sell a Product\n");
        printf("4. Display Purchase History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &num_products);
                break;
            case 2:
                displayProducts(products, num_products);
                break;
            case 3:
                sellProduct(products, num_products, purchases, &num_purchases);
                break;
            case 4:
                displayPurchases(purchases, num_purchases);
                break;
            case 5:
                printf("\nExiting the program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}