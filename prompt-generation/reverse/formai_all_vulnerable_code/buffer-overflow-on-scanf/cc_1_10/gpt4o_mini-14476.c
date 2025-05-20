//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;

// Function Prototypes
void addProduct();
void viewProducts();
void deleteProduct();
void clearScreen();
void menu();

int main() {
    clearScreen();
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n🎉 ** Product Inventory System ** 🎉\n");
        printf("1. Add Product\n");
        printf("2. View Products\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
                printf("Exiting the program. See you next time! 🎈\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full! Cannot add more products.\n");
        return;
    }

    Product newProduct;
    newProduct.id = productCount + 1; // Assign ID based on count
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name); // Read product name with spaces
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[productCount] = newProduct;
    productCount++;

    printf("Product added successfully! 🎊\n");
}

void viewProducts() {
    if (productCount == 0) {
        printf("No products in inventory. Please add some products! 📦\n");
        return;
    }

    printf("\n📦 ** Inventory List ** 📦\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
               inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void deleteProduct() {
    if (productCount == 0) {
        printf("No products to delete! 📭\n");
        return;
    }

    int id;
    printf("Enter the product ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > productCount) {
        printf("Invalid ID! Please enter a valid product ID. 🚫\n");
        return;
    }

    for (int i = id - 1; i < productCount - 1; i++) {
        inventory[i] = inventory[i + 1]; // Shift products to fill the gap
    }
    productCount--;

    printf("Product with ID %d deleted successfully! 🎉\n", id);
}

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear screen
}