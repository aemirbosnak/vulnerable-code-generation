//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>

#define MAX_PRODUCTS 10

// Struct defining a product
typedef struct {
    int id;
    char name[20];
    int quantity;
} Product;

// Function declarations
void addProduct(Product products[], int* numProducts);
void displayInventory(Product products[], int numProducts);
void updateQuantity(Product products[], int numProducts);
void removeProduct(Product products[], int* numProducts);

int main() {
    Product products[MAX_PRODUCTS]; // Array to store products
    int numProducts = 0; // Number of products currently in inventory
    int choice;

    do {
        // Display menu
        printf("\n1. Add product");
        printf("\n2. Display inventory");
        printf("\n3. Update quantity");
        printf("\n4. Remove product");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch(choice) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                displayInventory(products, numProducts);
                break;
            case 3:
                updateQuantity(products, numProducts);
                break;
            case 4:
                removeProduct(products, &numProducts);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.");
                break;
        }
    } while(choice != 5);

    return 0;
}

// Function definition to add a product to the inventory
void addProduct(Product products[], int* numProducts) {
    // Check if inventory is full
    if(*numProducts == MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.");
        return;
    }

    // Prompt user for product details
    printf("\nEnter product ID: ");
    scanf("%d", &products[*numProducts].id);
    printf("Enter product name: ");
    scanf("%s", products[*numProducts].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*numProducts].quantity);

    // Increment number of products in inventory
    (*numProducts)++;

    printf("Product added successfully.");
}

// Function definition to display the inventory
void displayInventory(Product products[], int numProducts) {
    // Check if inventory is empty
    if(numProducts == 0) {
        printf("Inventory is empty.");
        return;
    }

    // Display inventory header
    printf("\nProduct ID\tProduct Name\tQuantity");

    // Loop through products and display details
    for(int i = 0; i < numProducts; i++) {
        printf("\n%d\t\t%s\t\t%d", products[i].id, products[i].name, products[i].quantity);
    }
}

// Function definition to update the quantity of a product
void updateQuantity(Product products[], int numProducts) {
    // Check if inventory is empty
    if(numProducts == 0) {
        printf("Inventory is empty.");
        return;
    }

    int id, quantity;

    // Prompt user for product ID and new quantity
    printf("\nEnter product ID: ");
    scanf("%d", &id);
    printf("Enter new quantity: ");
    scanf("%d", &quantity);

    // Loop through products to find the product to update
    for(int i = 0; i < numProducts; i++) {
        if(products[i].id == id) {
            // Update product quantity
            products[i].quantity = quantity;
            printf("Quantity updated successfully.");
            return;
        }
    }

    // Product not found
    printf("Product not found.");
}

// Function definition to remove a product from the inventory
void removeProduct(Product products[], int* numProducts) {
    // Check if inventory is empty
    if(*numProducts == 0) {
        printf("Inventory is empty.");
        return;
    }

    int id;

    // Prompt user for product ID
    printf("\nEnter product ID: ");
    scanf("%d", &id);

    // Loop through products to find the product to remove
    for(int i = 0; i < *numProducts; i++) {
        if(products[i].id == id) {
            // Move all products after the removed product one position to the left
            for(int j = i; j < (*numProducts) - 1; j++) {
                products[j] = products[j+1];
            }

            // Decrement number of products in inventory
            (*numProducts)--;
            printf("Product removed successfully.");
            return;
        }
    }

    // Product not found
    printf("Product not found.");
}