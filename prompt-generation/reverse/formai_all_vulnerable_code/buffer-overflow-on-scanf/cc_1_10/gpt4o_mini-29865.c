//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NOT_FOUND -1

// A structure that represents a product
typedef struct {
    int id;
    char name[50];
} Product;

// A function to initialize a list of products
void initializeProducts(Product products[], int *size) {
    products[0] = (Product){.id = 1, .name = "Laptop"};
    products[1] = (Product){.id = 2, .name = "Smartphone"};
    products[2] = (Product){.id = 3, .name = "Tablet"};
    products[3] = (Product){.id = 4, .name = "Headphones"};
    products[4] = (Product){.id = 5, .name = "Smartwatch"};
    *size = 5; // Initialize number of products
}

// A function that searches for a product by its name using linear search
int linearSearch(Product products[], int size, const char *targetName) {
    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].name, targetName) == 0) {
            return i; // Found, return index
        }
    }
    return ITEM_NOT_FOUND; // Not found
}

// A function to display all products
void displayProducts(Product products[], int size) {
    printf("Available Products:\n");
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", products[i].id, products[i].name);
    }
}

// A function to search and display product by name
void searchProduct(Product products[], int size) {
    char targetName[50];
    printf("Enter the product name to search: ");
    scanf("%49s", targetName);
    
    int index = linearSearch(products, size, targetName);

    if (index != ITEM_NOT_FOUND) {
        printf("Product found: ID = %d, Name = %s\n", products[index].id, products[index].name);
    } else {
        printf("Product with name '%s' not found.\n", targetName);
    }
}

// Main function to execute the above functionalities
int main() {
    Product products[MAX_ITEMS]; // Array to hold products
    int size = 0; // Size of products array
    
    initializeProducts(products, &size); // Initialize products
    
    int choice;
    do {
        printf("\n--- Product Search Program ---\n");
        printf("1. Display Products\n");
        printf("2. Search Product by Name\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayProducts(products, size);
                break;
            case 2:
                searchProduct(products, size);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
    
    return 0; // Return 0 for successful execution
}