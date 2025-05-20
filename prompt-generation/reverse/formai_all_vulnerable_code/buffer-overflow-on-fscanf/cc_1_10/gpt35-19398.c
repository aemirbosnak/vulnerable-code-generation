//FormAI DATASET v1.0 Category: Product Inventory System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

/* Product structure */
struct product {
    char name[50];
    int price;
    int quantity;
};

/* Global variables */
struct product products[MAX_PRODUCTS];
int numProducts = 0;

/* Function prototypes */
void addProduct();
void removeProduct();
void updateProduct();
void printProducts();
void saveToFile();
void loadFromFile();

/* Main function */
int main() {
    char option;

    loadFromFile(); /* Load data from file */

    /* Main menu loop */
    do {
        printf("\n\n");
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Print products\n");
        printf("5. Save to file\n");
        printf("6. Load from file\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                addProduct();
                break;
            case '2':
                removeProduct();
                break;
            case '3':
                updateProduct();
                break;
            case '4':
                printProducts();
                break;
            case '5':
                saveToFile();
                break;
            case '6':
                loadFromFile();
                break;
            case '0':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while(option != '0');

    return 0;
}

/* Function to add a product to the inventory */
void addProduct() {
    struct product newProduct;

    /* Read product info from user */
    printf("\nEnter name of product: ");
    scanf(" %[^\n]", newProduct.name);
    printf("Enter price of product: ");
    scanf(" %d", &newProduct.price);
    printf("Enter quantity of product: ");
    scanf(" %d", &newProduct.quantity);

    /* Add product to array */
    products[numProducts] = newProduct;
    numProducts++;

    printf("Product added successfully.\n");
}

/* Function to remove a product from the inventory */
void removeProduct() {
    int index, i;

    /* Display products */
    printProducts();

    /* Read index of product to remove */
    printf("Enter index of product to remove: ");
    scanf(" %d", &index);

    /* Shift products down one index */
    for(i=index; i<numProducts-1; i++) {
        products[i] = products[i+1];
    }

    /* Decrement number of products */
    numProducts--;

    printf("Product removed successfully.\n");
}

/* Function to update a product in the inventory */
void updateProduct() {
    int index;

    /* Display products */
    printProducts();

    /* Read index of product to update */
    printf("Enter index of product to update: ");
    scanf(" %d", &index);

    /* Read updated product info from user */
    printf("\nEnter new name of product: ");
    scanf(" %[^\n]", products[index].name);
    printf("Enter new price of product: ");
    scanf(" %d", &products[index].price);
    printf("Enter new quantity of product: ");
    scanf(" %d", &products[index].quantity);

    printf("Product updated successfully.\n");
}

/* Function to print all products in the inventory */
void printProducts() {
    int i;

    printf("\n%-4s%-20s%-10s%s\n", "Index", "Name", "Price", "Quantity");
    printf("----------------------------------------------------------\n");

    for(i=0; i<numProducts; i++) {
        printf("%-4d%-20s%-10d%d\n", i, products[i].name, products[i].price, products[i].quantity);
    }
}

/* Function to save inventory data to file */
void saveToFile() {
    FILE *fp;
    int i;

    fp = fopen("products.dat", "w");

    for(i=0; i<numProducts; i++) {
        fprintf(fp, "%s\n%d\n%d\n", products[i].name, products[i].price, products[i].quantity);
    }

    fclose(fp);

    printf("Data saved to file.\n");
}

/* Function to load inventory data from file */
void loadFromFile() {
    FILE *fp;
    char name[50];
    int price, quantity;

    fp = fopen("products.dat", "r");

    if(fp == NULL) {
        printf("Could not open file. Starting with empty inventory.\n");
        return;
    }

    numProducts = 0;

    while(!feof(fp)) {
        fscanf(fp, "%[^\n]\n%d\n%d\n", name, &price, &quantity);

        strcpy(products[numProducts].name, name);
        products[numProducts].price = price;
        products[numProducts].quantity = quantity;

        numProducts++;
    }

    fclose(fp);

    printf("Data loaded from file.\n");
}