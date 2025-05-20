//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 30

// Structure to store product details
struct product {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

// Function to add a new product to the inventory
void addProduct(struct product inventory[], int* size) {
    if (*size >= MAX_PRODUCTS) {
        printf("Inventory is full, cannot add more products.\n");
        return;
    }
    struct product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    inventory[*size] = newProduct;
    *size += 1;
}

// Function to search for a product in the inventory
void searchProduct(struct product inventory[], int size, char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Product found: %s, quantity: %d, price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to update the quantity of a product in the inventory
void updateQuantity(struct product inventory[], int size, char* name, int quantity) {
    for (int i = 0; i < size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += quantity;
            printf("Product quantity updated: %d\n", inventory[i].quantity);
            return;
        }
    }
    printf("Product not found.\n");
}

// Function to delete a product from the inventory
void deleteProduct(struct product inventory[], int* size, char* name) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            *size -= 1;
            printf("Product deleted.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

int main() {
    struct product inventory[MAX_PRODUCTS];
    int size = 0;
    char input[10];
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;

    // Menu
    while (1) {
        printf("--------------------------------------------------\n");
        printf("1. Add product\n");
        printf("2. Search product\n");
        printf("3. Update product quantity\n");
        printf("4. Delete product\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%s", input);
        if (strcmp(input, "1") == 0) {
            addProduct(inventory, &size);
        } else if (strcmp(input, "2") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            searchProduct(inventory, size, name);
        } else if (strcmp(input, "3") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            updateQuantity(inventory, size, name, quantity);
        } else if (strcmp(input, "4") == 0) {
            printf("Enter product name: ");
            scanf("%s", name);
            deleteProduct(inventory, &size, name);
        } else if (strcmp(input, "5") == 0) {
            break;
        } else {
            printf("Invalid input.\n");
        }
    }

    // Print inventory
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%s, quantity: %d, price: %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    return 0;
}