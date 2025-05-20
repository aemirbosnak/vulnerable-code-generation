//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct Product {
    int ID;
    char name[50];
    int quantity;
};

// Function to add a new product
void addProduct(struct Product* products, int* numProducts) {
    printf("Enter product ID: ");
    scanf("%d", &products[*numProducts].ID);
    printf("Enter product name: ");
    scanf(" %s", &products[*numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);
    (*numProducts)++;
    printf("Product added successfully!\n");
}

// Function to remove a product
void removeProduct(struct Product* products, int* numProducts) {
    int id, index = -1;
    printf("Enter product ID: ");
    scanf("%d", &id);
    // Find the index of the product with the given ID
    for (int i = 0; i < *numProducts; i++) {
        if (products[i].ID == id) {
            index = i;
            break;
        }
    }
    // Remove the product if it exists
    if (index != -1) {
        for (int i = index; i < *numProducts - 1; i++) {
            products[i] = products[i+1];
        }
        (*numProducts)--;
        printf("Product removed successfully!\n");
    } else {
        printf("Product with ID %d not found.\n", id);
    }
}

// Function to display all products
void displayProducts(struct Product* products, int numProducts) {
    if (numProducts == 0) {
        printf("No products found.\n");
    } else {
        printf("ID\tName\t\tQuantity\n");
        for (int i = 0; i < numProducts; i++) {
            printf("%d\t%s\t%d\n", products[i].ID, products[i].name, products[i].quantity);
        }
    }
}

int main() {
    struct Product products[100];
    int numProducts = 0, choice;
    while (1) {
        printf("Enter choice:\n1. Add product\n2. Remove product\n3. Display products\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                displayProducts(products, numProducts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}