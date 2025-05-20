//FormAI DATASET v1.0 Category: Product Inventory System ; Style: creative
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 1000

/* Structure to hold information about a product */
struct Product {
    char name[100];
    int id;
    float price;
    int quantity;
};

/* Array to hold all products */
struct Product products[MAX_PRODUCTS];

/* Function declarations */
void addProduct();
void removeProduct();
void displayProduct();
void displayAllProducts();
void searchProduct();

/* Global variable for tracking number of products */
int numProducts = 0;

/* Main function */
int main() {
    int choice;

    /* Display menu and get user input */
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Product\n");
        printf("4. Display All Products\n");
        printf("5. Search Product\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        /* Call appropriate function based on user input */
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayProduct();
                break;
            case 4:
                displayAllProducts();
                break;
            case 5:
                searchProduct();
                break;
            case 6:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

/* Function to add a new product to the inventory */
void addProduct() {
    int id, quantity;
    float price;
    char name[100];

    /* Make sure there is space in array */
    if (numProducts >= MAX_PRODUCTS) {
        printf("\nUnable to add product - maximum number of products reached.\n");
        return;
    }

    /* Get product information from user */
    printf("\nEnter product name: ");
    scanf("%s", name);
    printf("Enter product ID: ");
    scanf("%d", &id);
    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    /* Add product to array */
    strcpy(products[numProducts].name, name);
    products[numProducts].id = id;
    products[numProducts].price = price;
    products[numProducts].quantity = quantity;

    /* Increment product count */
    numProducts++;

    printf("\nProduct added successfully.\n");
}

/* Function to remove a product from the inventory */
void removeProduct() {
    int id, i, j;
    int productFound = 0;

    /* Get product ID from user */
    printf("\nEnter product ID to remove: ");
    scanf("%d", &id);

    /* Search for product in array */
    for (i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            /* Found product - remove it by shifting remaining products over */
            productFound = 1;

            for (j = i; j < numProducts - 1; j++) {
                strcpy(products[j].name, products[j+1].name);
                products[j].id = products[j+1].id;
                products[j].price = products[j+1].price;
                products[j].quantity = products[j+1].quantity;
            }

            /* Decrement product count */
            numProducts--;

            printf("\nProduct removed successfully.\n");
            break;
        }
    }

    if (!productFound) {
        printf("\nProduct not found.\n");
    }
}

/* Function to display details of a single product */
void displayProduct() {
    int id, i;
    int productFound = 0;

    /* Get product ID from user */
    printf("\nEnter product ID to display: ");
    scanf("%d", &id);

    /* Search for product in array */
    for (i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            /* Found product - display details */
            productFound = 1;

            printf("\nProduct details:\n");
            printf("Name: %s\n", products[i].name);
            printf("ID: %d\n", products[i].id);
            printf("Price: $%.2f\n", products[i].price);
            printf("Quantity: %d\n", products[i].quantity);

            break;
        }
    }

    if (!productFound) {
        printf("\nProduct not found.\n");
    }
}

/* Function to display details of all products in the inventory */
void displayAllProducts() {
    int i;

    printf("\nInventory:\n");

    for (i = 0; i < numProducts; i++) {
        printf("\nProduct %d:\n", i+1);
        printf("Name: %s\n", products[i].name);
        printf("ID: %d\n", products[i].id);
        printf("Price: $%.2f\n", products[i].price);
        printf("Quantity: %d\n", products[i].quantity);
    }
}

/* Function to search for a product by name or ID */
void searchProduct() {
    int choice, id, i;
    char name[100];
    int productFound = 0;

    /* Display search menu and get user input */
    printf("\nSearch for product by:\n");
    printf("1. Name\n");
    printf("2. ID\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            /* Search by name */
            printf("\nEnter product name to search for: ");
            scanf("%s", name);

            for (i = 0; i < numProducts; i++) {
                if (strcmp(products[i].name, name) == 0) {
                    /* Found product - display details */
                    productFound = 1;

                    printf("\nProduct details:\n");
                    printf("Name: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Quantity: %d\n", products[i].quantity);
                }
            }

            if (!productFound) {
                printf("\nProduct not found.\n");
            }
            break;

        case 2:
            /* Search by ID */
            printf("\nEnter product ID to search for: ");
            scanf("%d", &id);

            for (i = 0; i < numProducts; i++) {
                if (products[i].id == id) {
                    /* Found product - display details */
                    productFound = 1;

                    printf("\nProduct details:\n");
                    printf("Name: %s\n", products[i].name);
                    printf("ID: %d\n", products[i].id);
                    printf("Price: $%.2f\n", products[i].price);
                    printf("Quantity: %d\n", products[i].quantity);
                }
            }

            if (!productFound) {
                printf("\nProduct not found.\n");
            }
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}