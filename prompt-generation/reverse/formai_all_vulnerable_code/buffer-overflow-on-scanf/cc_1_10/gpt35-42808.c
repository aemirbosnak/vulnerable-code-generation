//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Defining a struct for products
typedef struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

// Defining function prototypes
int menu();
void addProduct(Product* products, int numProducts);
void removeProduct(Product* products, int numProducts);
void displayProducts(Product* products, int numProducts);
void updateProduct(Product* products, int numProducts);

int main() {

    int numProducts = 0; // Number of products in the warehouse
    Product products[100]; // Array of products in the warehouse
    int choice; // For storing user's choice from the menu

    printf("Welcome to the Warehouse Management System.\n");

    do {
        choice = menu();
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
                updateProduct(products, numProducts);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu and get user's choice
int menu() {

    int choice;

    printf("\nMenu:\n");
    printf("1. Add a product\n");
    printf("2. Remove a product\n");
    printf("3. List all products\n");
    printf("4. Update a product\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    return choice;
}

// Function to add a new product to the warehouse
void addProduct(Product* products, int numProducts) {

    Product newProduct;
    newProduct.id = numProducts + 1; // Assign an ID to the new product

    getchar(); // Clear the input buffer

    printf("\nEnter product name: ");
    fgets(newProduct.name, 50, stdin);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    products[numProducts] = newProduct;

    printf("Product added successfully.\n");
}

// Function to remove a product from the warehouse
void removeProduct(Product* products, int numProducts) {

    int idToDelete, indexToDelete;

    if (numProducts == 0) {
        printf("\nNo products in warehouse.\n");
        return;
    }

    printf("\nEnter product ID to delete: ");
    scanf("%d", &idToDelete);

    // Find the index of the product with the given ID
    for (int i=0; i<numProducts; i++) {
        if (products[i].id == idToDelete) {
            indexToDelete = i;
            break;
        }
        if (i == numProducts - 1) {
            printf("\nProduct with ID %d not found.\n", idToDelete);
            return;
        }
    }

    // Shift all elements to the left to overwrite the deleted element
    for (int i=indexToDelete; i<numProducts-1; i++) {
        products[i] = products[i+1];
    }

    printf("Product deleted successfully.\n");
}

// Function to display all products in the warehouse
void displayProducts(Product* products, int numProducts) {

    if (numProducts == 0) {
        printf("\nNo products in warehouse.\n");
        return;
    }

    printf("\n%-10s%-20s%-10s%-10s\n", "ID", "Name", "Price", "Quantity");

    for (int i=0; i<numProducts; i++) {
        printf("%-10d%-20s%-10.2f%-10d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to update a product in the warehouse
void updateProduct(Product* products, int numProducts) {

    int idToUpdate, choice, indexToUpdate;

    if (numProducts == 0) {
        printf("\nNo products in warehouse.\n");
        return;
    }

    printf("\nEnter product ID to update: ");
    scanf("%d", &idToUpdate);

    // Find the index of the product with the given ID
    for (int i=0; i<numProducts; i++) {
        if (products[i].id == idToUpdate) {
            indexToUpdate = i;
            break;
        }
        if (i == numProducts - 1) {
            printf("\nProduct with ID %d not found.\n", idToUpdate);
            return;
        }
    }

    do {
        printf("\nProduct details:\n");
        printf("1. Name: %s", products[indexToUpdate].name);
        printf("2. Price: %.2f\n", products[indexToUpdate].price);
        printf("3. Quantity: %d\n", products[indexToUpdate].quantity);
        printf("4. Exit update menu\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                getchar(); // Clear input buffer
                printf("\nEnter new product name: ");
                fgets(products[indexToUpdate].name, 50, stdin);
                break;
            case 2:
                printf("Enter new product price: ");
                scanf("%f", &products[indexToUpdate].price);
                break;
            case 3:
                printf("Enter new product quantity: ");
                scanf("%d", &products[indexToUpdate].quantity);
                break;
            case 4:
                printf("Exiting update menu.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    printf("Product updated successfully.\n");
}