//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: configurable
#include <stdio.h>

// Define struct for product information
typedef struct {
    int id;
    char name[50];
    int quantity;
} Product;

// Define functions for product management
void addProduct(Product products[], int numProducts);
void removeProduct(Product products[], int numProducts);
void displayProducts(Product products[], int numProducts);

int main() {
    int choice, numProducts = 0;
    Product products[100];

    do {
        // Display options to user
        printf("\n\nWarehouse Management System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display All Products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute user's choice
        switch(choice) {
            case 1:
                addProduct(products, numProducts);
                numProducts++;
                break;
            case 2:
                removeProduct(products, numProducts);
                numProducts--;
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while(choice != 4);

    return 0;
}

// Function to add product to system
void addProduct(Product products[], int numProducts) {
    Product p;
    printf("\nEnter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    products[numProducts] = p;
    printf("\nProduct added successfully.");
}

// Function to remove product from system
void removeProduct(Product products[], int numProducts) {
    int id;
    printf("\nEnter product ID to be removed: ");
    scanf("%d", &id);
    for(int i = 0; i < numProducts; i++) {
        if(products[i].id == id) {
            for(int j = i; j < numProducts; j++) {
                products[j] = products[j+1];
            }
            printf("\nProduct removed successfully.");
            return;
        }
    }
    printf("\nProduct with ID %d not found.", id);
}

// Function to display all products in system
void displayProducts(Product products[], int numProducts) {
    printf("\nList of Products\n");
    printf("ID\tName\tQuantity\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%d\t%s\t%d\n", products[i].id, products[i].name, products[i].quantity);
    }
}