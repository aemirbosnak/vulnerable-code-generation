//FormAI DATASET v1.0 Category: Product Inventory System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

//Defining maximum number of products
#define MAX_PRODUCTS 100

//Defining struct for product inventory data
struct Product {
    char name[50];
    int quantity;
    float price;
};

//Function to add a new product to the inventory
void addProduct(struct Product products[], int *productCount) {
    //Checking if maximum number of products have been added
    if (*productCount >= MAX_PRODUCTS) {
        printf("Inventory is full!\n");
        return;
    }
    
    //Getting input from user for new product
    printf("Enter product name: ");
    scanf("%s", products[*productCount].name);
    printf("Enter quantity: ");
    scanf("%d", &products[*productCount].quantity);
    printf("Enter price: ");
    scanf("%f", &products[*productCount].price);
    
    //Increasing product count
    *productCount += 1;
    
    printf("Product added successfully!\n");
}

//Function to display all products in the inventory
void displayAllProducts(struct Product products[], int productCount) {
    //Checking if there are any products in the inventory
    if (productCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    
    printf("Product Inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    
    //Iterating through all products and printing their data
    for (int i = 0; i < productCount; i++) {
        printf("%s\t%d\t$%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

//Function to search for a product based on name
void searchProduct(struct Product products[], int productCount) {
    //Checking if there are any products in the inventory
    if (productCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    
    char searchName[50];
    
    printf("Enter product name to search for: ");
    scanf("%s", searchName);
    
    //Iterating through all products to find matching name
    for (int i = 0; i < productCount; i++) {
        if (strcmp(searchName, products[i].name) == 0) {
            printf("Name\tQuantity\tPrice\n");
            printf("%s\t%d\t$%.2f\n", products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    
    printf("Product not found!\n");
}

int main() {
    //Initializing product inventory array and count variable
    struct Product products[MAX_PRODUCTS];
    int productCount = 0;
    
    //Displaying menu and getting user input
    int choice;
    
    do {
        printf("\n---Product Inventory System---\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search for Product\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                displayAllProducts(products, productCount);
                break;
            case 3:
                searchProduct(products, productCount);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}