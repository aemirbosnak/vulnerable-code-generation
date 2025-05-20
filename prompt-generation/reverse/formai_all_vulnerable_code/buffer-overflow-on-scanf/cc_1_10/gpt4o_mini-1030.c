//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold product details
typedef struct {
    int id;
    char name[50];
    float price;
} Product;

// Function to compare two products for sorting by ID
int compareById(const void *a, const void *b) {
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    return (productA->id - productB->id);
}

// Function to compare two products for sorting by name
int compareByName(const void *a, const void *b) {
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    return strcmp(productA->name, productB->name);
}

// Function to compare two products for sorting by price
int compareByPrice(const void *a, const void *b) {
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    if (productA->price < productB->price) return -1;
    else if (productA->price > productB->price) return 1;
    else return 0;
}

// Function to print the list of products
void printProducts(Product *products, int count) {
    printf("\nID\tName\t\tPrice\n");
    printf("----------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%d\t%s\t%.2f\n", products[i].id, products[i].name, products[i].price);
    }
}

int main() {
    int numberOfProducts;
    
    printf("Enter number of products: ");
    scanf("%d", &numberOfProducts);
    
    // Allocate memory for products
    Product *products = malloc(numberOfProducts * sizeof(Product));
    if (products == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Input products
    for (int i = 0; i < numberOfProducts; ++i) {
        printf("Enter details for product %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &products[i].id);
        printf("Name: ");
        scanf("%s", products[i].name);  // Read product name
        printf("Price: ");
        scanf("%f", &products[i].price);
    }

    int choice;
    do {
        printf("\nSelect sorting method:\n");
        printf("1. Sort by ID\n");
        printf("2. Sort by Name\n");
        printf("3. Sort by Price\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                qsort(products, numberOfProducts, sizeof(Product), compareById);
                printf("Products sorted by ID:\n");
                printProducts(products, numberOfProducts);
                break;
            case 2:
                qsort(products, numberOfProducts, sizeof(Product), compareByName);
                printf("Products sorted by Name:\n");
                printProducts(products, numberOfProducts);
                break;
            case 3:
                qsort(products, numberOfProducts, sizeof(Product), compareByPrice);
                printf("Products sorted by Price:\n");
                printProducts(products, numberOfProducts);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }

    } while (choice != 4);

    // Free allocated memory
    free(products);

    return 0;
}