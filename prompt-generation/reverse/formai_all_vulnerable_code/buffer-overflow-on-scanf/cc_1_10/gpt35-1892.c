//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for products
typedef struct {
    int id;
    char name[20];
    int price;
    int stock;
} Product;

// Declare global variables
Product products[100];
int numProducts = 0;

// Function to add a new product
void addProduct() {
    // Prompt user for product details
    printf("What be the name of thy goods?\n");
    char name[20];
    scanf("%s", &name);
    printf("What be the price of thy goods?\n");
    int price;
    scanf("%d", &price);
    printf("What be the stock of thy goods?\n");
    int stock;
    scanf("%d", &stock);

    // Create new product
    Product newProduct;
    newProduct.id = numProducts + 1;
    strcpy(newProduct.name, name);
    newProduct.price = price;
    newProduct.stock = stock;

    // Add new product to inventory
    products[numProducts] = newProduct;
    numProducts++;

    // Display confirmation message
    printf("Thy goods hath been added to thy inventory.\n");
}

// Function to display all products in inventory
void displayProducts() {
    printf("Here be thy inventory:\n");
    printf("ID\tName\tPrice\tStock\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\t%d\n", products[i].id, products[i].name, products[i].price, products[i].stock);
    }
}

// Function to update a product's stock
void updateStock() {
    // Prompt user for product ID and new stock
    printf("What be the ID of the goods thou wishest to update?\n");
    int id;
    scanf("%d", &id);
    printf("What be the new stock of the goods?\n");
    int stock;
    scanf("%d", &stock);

    // Find product with matching ID
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            // Update product's stock
            products[i].stock = stock;

            // Display confirmation message
            printf("Thy goods stock hath been updated.\n");
            return;
        }
    }

    // Display error message if product does not exist
    printf("Thy goods be not found in thy inventory. Please try again.\n");
}

int main() {
    // Declare local variables
    char choice = ' ';

    // Begin Shakespearean dialogue
    printf("Good day, my gentle friends.\n");
    printf("What inventory management tasks dost thou seeketh to accomplish on this fair day?\n");

    // Display inventory management options
    while (choice != 'E') {
        printf("A - Add product\n");
        printf("D - Display products\n");
        printf("U - Update stock\n");
        printf("E - Exit\n");
        scanf(" %c", &choice);

        // Handle inventory management tasks
        switch (choice) {
            case 'A':
                addProduct();
                break;
            case 'D':
                displayProducts();
                break;
            case 'U':
                updateStock();
                break;
            case 'E':
                printf("Farewell, my gentle friends.\n");
                break;
            default:
                printf("I beg thy pardon, I comprehend not thy request. Please try again.\n");
                break;
        }
    }

    return 0;
}