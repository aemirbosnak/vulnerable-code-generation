//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the product inventory structure
typedef struct Product {
    char name[50];
    int quantity;
    float price;
    struct Product* next;
} Product;

// Function to insert a product into the inventory
void insertProduct(Product** head) {
    // Allocate memory for the new product
    Product* newProduct = (Product*)malloc(sizeof(Product));

    // Get the product name, quantity, and price from the user
    printf("Enter the product name: ");
    scanf("%s", newProduct->name);

    printf("Enter the product quantity: ");
    scanf("%d", &newProduct->quantity);

    printf("Enter the product price: ");
    scanf("%f", &newProduct->price);

    // Insert the new product into the inventory
    if (*head == NULL) {
        *head = newProduct;
    } else {
        (*head)->next = newProduct;
    }
}

// Function to search for a product in the inventory
Product* searchProduct(Product* head, char* name) {
    // Traverse the inventory
    while (head) {
        // Check if the product name matches the search name
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }

    // Return NULL if the product is not found
    return NULL;
}

// Function to update the quantity of a product
void updateQuantity(Product* head, char* name, int quantity) {
    // Search for the product in the inventory
    Product* product = searchProduct(head, name);

    // If the product is found, update its quantity
    if (product) {
        product->quantity = quantity;
    }
}

// Function to delete a product from the inventory
void deleteProduct(Product* head, char* name) {
    // Search for the product in the inventory
    Product* product = searchProduct(head, name);

    // If the product is found, delete it from the inventory
    if (product) {
        Product* previousProduct = NULL;

        // Traverse the inventory
        while (product->next) {
            previousProduct = product;
            product = product->next;
        }

        // If the product is the first product in the inventory, update the head of the inventory
        if (previousProduct == NULL) {
            head = product->next;
        } else {
            previousProduct->next = product->next;
        }

        // Free the memory occupied by the product
        free(product);
    }
}

int main() {
    // Create the product inventory head
    Product* head = NULL;

    // Insert some products into the inventory
    insertProduct(&head);
    insertProduct(&head);
    insertProduct(&head);

    // Search for a product in the inventory
    Product* product = searchProduct(head, "Product 2");

    // If the product is found, update its quantity
    if (product) {
        updateQuantity(head, "Product 2", 10);
    }

    // Delete a product from the inventory
    deleteProduct(head, "Product 1");

    // Print the inventory
    Product* currentProduct = head;
    while (currentProduct) {
        printf("%s: %d, $%.2f\n", currentProduct->name, currentProduct->quantity, currentProduct->price);
        currentProduct = currentProduct->next;
    }

    return 0;
}