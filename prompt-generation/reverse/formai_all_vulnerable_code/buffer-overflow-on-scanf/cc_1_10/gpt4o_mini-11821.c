//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: paranoid
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

// Function prototypes
void addProduct();
void removeProduct();
void listProducts();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n*** Paranoid Product Inventory System ***\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. List Products\n");
        printf("4. Exit\n");
        printf("Choose wisely (1-4): ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                listProducts();
                break;
            case 4:
                printf("Exiting the inventory system... but are you sure?\n");
                exit(0);
            default:
                printf("Invalid choice! Do you think we're playing games here?\n");
        }
    }
    return 0;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Can't add more products! Can you hear the inventory saying 'no'? You're pushing it!\n");
        return;
    }

    Product newProduct;
    printf("Enter product name: ");
    fgets(newProduct.name, NAME_LENGTH, stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = '\0'; // Strip newline
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    clearBuffer();

    inventory[productCount++] = newProduct;
    printf("Added '%s' to the inventory... or did I?\n", newProduct.name);
}

void removeProduct() {
    char name[NAME_LENGTH];
    printf("Enter the name of the product you wish to remove: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0'; // Strip newline

    for (int i = 0; i < productCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            // Shift the products down
            for (int j = i; j < productCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            productCount--;
            printf("Removed '%s' from the inventory! But was it really there?\n", name);
            return;
        }
    }
    printf("Product '%s' not found! Are you sure you're not imagining it?\n", name);
}

void listProducts() {
    if (productCount == 0) {
        printf("No products in inventory... or are they hiding from you?\n");
        return;
    }

    printf("\nCurrent products in inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product %d: %s, Quantity: %d, Price: %.2f\n", i + 1,
               inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer. Is it really empty?
}