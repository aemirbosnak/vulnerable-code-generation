//FormAI DATASET v1.0 Category: Product Inventory System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUCTS 100

typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int numProducts = 0;

// Function to get user input and create a new product
void createNewProduct() {
    Product newProduct;

    // Get name
    printf("\nEnter product name: ");
    scanf("%s", &newProduct.name);
    // Convert to uppercase
    for(int i = 0; i < strlen(newProduct.name); i++) {
        newProduct.name[i] = toupper(newProduct.name[i]);
    }

    // Get quantity
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    // Get price
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    // Assign ID
    newProduct.id = numProducts + 1;

    // Add product to inventory
    inventory[numProducts] = newProduct;
    numProducts++;

    printf("\nProduct added successfully!\n");
}

// Function to edit a product's details
void editProduct() {
    int id, choice;
    Product *product;

    printf("\nEnter product ID to edit: ");
    scanf("%d", &id);

    // Find product by ID
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == id) {
            product = &inventory[i];
            break;
        }
        if(i == numProducts - 1) {
            printf("\nProduct not found.\n");
            return;
        }
    }

    printf("\nChoose details to edit:\n");
    printf("1. Product name\n");
    printf("2. Quantity\n");
    printf("3. Price\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter new product name: ");
            scanf("%s", &product->name);
            // Convert to uppercase
            for (int i = 0; i < strlen(product->name); i++) {
                product->name[i] = toupper(product->name[i]);
            }
            printf("\nProduct name updated successfully!\n");
            break;
        case 2:
            printf("\nEnter new quantity: ");
            scanf("%d", &product->quantity);
            printf("\nQuantity updated successfully!\n");
            break;
        case 3:
            printf("\nEnter new price: ");
            scanf("%f", &product->price);
            printf("\nPrice updated successfully!\n");
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }
}

// Function to delete a product
void deleteProduct() {
    int id, index;
    printf("\nEnter product ID to delete: ");
    scanf("%d", &id);

    // Find product index in array
    for(int i = 0; i < numProducts; i++) {
        if(inventory[i].id == id) {
            index = i;
            break;
        }
        if(i == numProducts - 1) {
            printf("\nProduct not found.\n");
            return;
        }
    }

    // Shift elements left to delete product at index
    for(int i = index; i < numProducts - 1; i++) {
        inventory[i] = inventory[i+1];
    }
    numProducts--;
    printf("\nProduct deleted successfully!\n");
}

// Function to display all products
void displayAll() {
    if(numProducts == 0) {
        printf("\nNo products in inventory.\n");
        return;
    }

    printf("\nID\tProduct Name\t\tQuantity\tPrice\n");
    for(int i = 0; i < numProducts; i++) {
        printf("%d\t%-20s\t%-10d\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n------------------------------------------------------------\n");
        printf("Product Inventory System\n");
        printf("1. Add new product\n");
        printf("2. Edit product\n");
        printf("3. Delete product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createNewProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                displayAll();
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    }

    return 0;
}