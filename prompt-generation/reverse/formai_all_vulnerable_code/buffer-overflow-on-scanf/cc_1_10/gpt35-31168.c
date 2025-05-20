//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <string.h>

// Number of maximum products
#define MAX_PRODUCTS 5

// Struct to store product information
struct Product {
    char name[20];
    char category[10];
    int quantity;
    float price;
};

int main() {
    // Declaring an array of products
    struct Product products[MAX_PRODUCTS];
    int numProducts = 0;
    
    // Welcome message
    printf("Welcome to the Product Inventory System!\n");
    
    // Loop to continuously prompt user for input
    while(1) {
        // Prompt for user input
        printf("\nEnter a product name or type 'quit' to exit: ");
        char input[20];
        scanf("%s", input);
        
        // Check for quit condition
        if(strcmp(input, "quit") == 0) {
            break;
        }
        
        // Check if maximum number of products has been reached
        if(numProducts >= MAX_PRODUCTS) {
            printf("Maximum number of products reached. Cannot add more products.\n");
            continue;
        }
        
        // Prompt for additional product information
        printf("Enter product category: ");
        scanf("%s", products[numProducts].category);
        printf("Enter product quantity: ");
        scanf("%d", &products[numProducts].quantity);
        printf("Enter product price: ");
        scanf("%f", &products[numProducts].price);
        
        // Add product to array
        strcpy(products[numProducts].name, input);
        numProducts++;
        
        // Success message
        printf("\n%s added to inventory!\n", input);
    }
    
    // Display product information
    printf("\nProduct Inventory: \n");
    for(int i = 0; i < numProducts; i++) {
        printf("\nName: %s\n", products[i].name);
        printf("Category: %s\n", products[i].category);
        printf("Quantity: %d\n", products[i].quantity);
        printf("Price: %.2f\n", products[i].price);
    }
    
    // Goodbye message
    printf("\nThank you for using the Product Inventory System!\n");
    
    return 0;
}