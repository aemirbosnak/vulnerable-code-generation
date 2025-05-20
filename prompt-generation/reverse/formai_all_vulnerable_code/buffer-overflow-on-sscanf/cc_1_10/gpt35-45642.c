//FormAI DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_PRODUCTS 50
#define MAX_NAME_LENGTH 50

// Structs
typedef struct Product {
    int id;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

// Prototypes
void addProduct(Product*, int*);
void removeProduct(Product*, int*);
void viewProducts(Product*, int);
void saveProducts(Product*, int);
void loadProducts(Product*, int*);

// Main function
int main() {
    int numProducts = 0;
    Product products[MAX_PRODUCTS];

    // Load products from file
    loadProducts(products, &numProducts);

    // Loop until user quits
    int selection = 0;
    while (selection != 4) {
        printf("Please select an option:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. View Products\n");
        printf("4. Quit\n");
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                addProduct(products, &numProducts);
                break;
            case 2:
                removeProduct(products, &numProducts);
                break;
            case 3:
                viewProducts(products, numProducts);
                break;
            case 4:
                saveProducts(products, numProducts);
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }

    return 0;
}

// Function to add a new product
void addProduct(Product* products, int* numProducts) {
    int id = *numProducts + 1;  // new id is just the number of current products plus one
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;

    // Get inputs from user
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter price: ");
    scanf("%f", &price);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Add new product to array
    Product newProduct = { id, name, price, quantity };
    products[*numProducts] = newProduct;
    *numProducts += 1;
}

// Function to remove a product
void removeProduct(Product* products, int* numProducts) {
    int idToRemove;
    printf("Enter ID of product to remove: ");
    scanf("%d", &idToRemove);

    // Find product with matching ID and remove it from array
    int i;
    for (i = 0; i < *numProducts; i++) {
        if (products[i].id == idToRemove) {
            // Shift all products after this one down one index
            memmove(&products[i], &products[i + 1], (*numProducts - i - 1) * sizeof(Product));
            *numProducts -= 1;
            printf("Product %d removed\n", idToRemove);
            return;
        }
    }

    printf("No product with ID %d found\n", idToRemove);
}

// Function to view all products
void viewProducts(Product* products, int numProducts) {
    if (numProducts == 0) {
        printf("No products found\n");
        return;
    }

    printf("ID\tName\tPrice\tQuantity\n");
    int i;
    for (i = 0; i < numProducts; i++) {
        printf("%d\t%s\t$%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

// Function to save products to file
void saveProducts(Product* products, int numProducts) {
    FILE* fptr = fopen("products.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i;
    for (i = 0; i < numProducts; i++) {
        fprintf(fptr, "%d,%s,%.2f,%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }

    fclose(fptr);
}

// Function to load products from file
void loadProducts(Product* products, int* numProducts) {
    FILE* fptr = fopen("products.txt", "r");
    if (fptr == NULL) {
        printf("No saved products found\n");
        return;
    }

    char line[MAX_NAME_LENGTH + 20];  // maximum length of line is ID, name, price, and quantity separated by commas
    while (fgets(line, sizeof(line), fptr)) {
        // Parse each line and add product to array
        int id;
        char name[MAX_NAME_LENGTH];
        float price;
        int quantity;
        sscanf(line, "%d,%[^,],%f,%d", &id, name, &price, &quantity);
        Product newProduct = { id, name, price, quantity };
        products[*numProducts] = newProduct;
        *numProducts += 1;
    }

    fclose(fptr);
}