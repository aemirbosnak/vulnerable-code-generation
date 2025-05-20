//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 1000

// Product Structure
typedef struct product {
    char prod_id[10];
    char name[50];
    int quantity;
    float price;
}Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

// Function Declarations
void addProduct();
void editProduct(char*);
void deleteProduct(char*);
void displayProduct(char*);
void printProducts();
void saveToFile();
void loadFromFile();

int main() {
    printf("Welcome to Warehouse Management System\n");

    char choice;
    int terminate = 0;
    loadFromFile(); // Load saved products from a file 

    while (!terminate) {
        printf("\nPlease select your choice: \n");
        printf("1. Add Product\n");
        printf("2. Edit Product\n");
        printf("3. Delete Product\n");
        printf("4. Display Product\n");
        printf("5. Display All Products\n");
        printf("6. Exit\n");

        scanf(" %c", &choice);
        switch (choice) {
        case '1':
            addProduct();
            break;
        case '2':
            printf("Enter the Product ID: ");
            char edit_id[10];
            scanf("%s", edit_id);
            editProduct(edit_id);
            break;
        case '3':
            printf("Enter the Product ID: ");
            char delete_id[10];
            scanf("%s", delete_id);
            deleteProduct(delete_id);
            break;
        case '4':
            printf("Enter the Product ID: ");
            char display_id[10];
            scanf("%s", display_id);
            displayProduct(display_id);
            break;
        case '5':
            printProducts();
            break;
        case '6':
            saveToFile(); // Save products to a file before exiting
            terminate = 1;
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    printf("Exiting Warehouse Management System. Goodbye!\n");
    return 0;
}

// Add a new product
void addProduct() {
    Product newProduct;
    printf("Enter the Product ID: ");
    scanf("%s", newProduct.prod_id);
    printf("Enter the Product Name: ");
    scanf(" %[^\n]s", newProduct.name);
    printf("Enter the Product Quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter the Product Price: ");
    scanf("%f", &newProduct.price);

    products[productCount++] = newProduct;
    printf("New Product added successfully!\n");
}

// Edit an existing product
void editProduct(char *edit_id) {
    int pos = -1; // position of the product to be edited
    for (int i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].prod_id, edit_id) == 0) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        printf("Enter the New Product Name: ");
        scanf(" %[^\n]s", products[pos].name);
        printf("Enter the New Product Quantity: ");
        scanf("%d", &products[pos].quantity);
        printf("Enter the New Product Price: ");
        scanf("%f", &products[pos].price);
        printf("Product edited successfully!\n");
    }
    else {
        printf("Product ID not found!\n");
    }
}

// Delete an existing product
void deleteProduct(char *delete_id) {
    int pos = -1; // position of the product to be deleted
    for (int i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].prod_id, delete_id) == 0) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < productCount - 1; i++) {
            products[i] = products[i + 1];
        }
        productCount--;
        printf("Product deleted successfully!\n");
    }
    else {
        printf("Product ID not found!\n");
    }
}

// Display an existing product
void displayProduct(char *display_id) {
    int pos = -1; // position of the product to be displayed
    for (int i = 0; i < productCount; i++)
    {
        if (strcmp(products[i].prod_id, display_id) == 0) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        printf("Product ID: %s\n", products[pos].prod_id);
        printf("Product Name: %s\n", products[pos].name);
        printf("Product Quantity: %d\n", products[pos].quantity);
        printf("Product Price: %.2f\n", products[pos].price);
    }
    else {
        printf("Product ID not found!\n");
    }
}

// Print all products
void printProducts() {
    if (productCount == 0) {
        printf("No products found!\n");
        return;
    }

    printf("All Products:\n");
    for (int i = 0; i < productCount; i++)
    {
        printf("%d - Product ID: %s | Product Name: %s | Product Quantity: %d | Product Price: %.2f\n", 
            i + 1, products[i].prod_id, products[i].name, products[i].quantity, products[i].price);
    }
}

// Save products to a file
void saveToFile() {
    FILE *fp;
    fp = fopen("products.txt", "w");
    if (fp)
    {
        fprintf(fp, "%d\n", productCount);
        for (int i = 0; i < productCount; i++)
        {
            fprintf(fp, "%s,%s,%d,%.2f\n", products[i].prod_id, products[i].name, products[i].quantity, products[i].price);
        }
        fclose(fp);
        printf("Products saved to file!\n");
    }
    else {
        printf("File could not be opened for writing!\n");
    }
}

// Load products from file
void loadFromFile() {
    FILE *fp;
    fp = fopen("products.txt", "r");
    if (fp)
    {
        fscanf(fp, "%d", &productCount);
        for (int i = 0; i < productCount; i++)
        {
            fscanf(fp, "%[^,],%[^,],%d,%f\n", 
                products[i].prod_id, products[i].name, &products[i].quantity, &products[i].price);
        }
        fclose(fp);
        printf("%d Products loaded from file!\n", productCount);
    }
    else {
        printf("File could not be opened for reading!\n");
    }
}