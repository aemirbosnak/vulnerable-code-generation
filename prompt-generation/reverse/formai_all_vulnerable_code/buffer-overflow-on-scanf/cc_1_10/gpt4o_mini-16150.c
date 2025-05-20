//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function to add a product to the inventory
void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Oh no! The inventory is full! Can't add more products.\n");
        return;
    }

    Product newProduct;
    printf("🎉 Let's add a new product! 🎉\n");
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    inventory[productCount] = newProduct;
    productCount++;
    printf("Hooray! Product added successfully. 🎊\n");
}

// Function to view all products in the inventory
void viewProducts() {
    if (productCount == 0) {
        printf("Oops! No products in the inventory yet! 🌼\n");
        return;
    }

    printf("📦 Here's the list of products in the inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product %d: Name: %s, Quantity: %d, Price: %.2f\n", 
                i + 1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// Function to delete a product from the inventory
void deleteProduct() {
    if (productCount == 0) {
        printf("Oh dear! There's nothing to delete! 🌥️\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name of the product to delete: ");
    scanf("%s", name);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("🎈 Product '%s' removed successfully! 🎈\n", name);
            return;
        }
    }
    printf("Oops! Product '%s' not found in the inventory. 😢\n", name);
}

// Function to display the menu
void displayMenu() {
    printf("\n🌟 Product Inventory System 🌟\n");
    printf("1. Add Product\n");
    printf("2. View Products\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Please enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                printf("Thank you for using the Product Inventory System! 😊\n");
                break;
            default:
                printf("Whoops! That's not a valid choice! Please try again. 🤔\n");
        }
    } while (choice != 4);

    return 0;
}