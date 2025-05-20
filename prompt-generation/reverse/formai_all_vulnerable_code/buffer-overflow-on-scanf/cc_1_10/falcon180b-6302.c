//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a product
struct Product {
    char name[50];
    int quantity;
    float price;
};

// Function to add a new product to the warehouse
void addProduct(struct Product *warehouse[], int size, int capacity) {
    int choice;
    printf("\nEnter your choice:\n");
    printf("1. Add product\n");
    printf("2. View products\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter product name: ");
            scanf("%s", (*warehouse)[size-1].name);
            printf("Enter product quantity: ");
            scanf("%d", &(*warehouse)[size-1].quantity);
            printf("Enter product price: ");
            scanf("%f", &(*warehouse)[size-1].price);
            printf("\nProduct added successfully!\n");
            break;

        case 2:
            printf("\nProduct ID\tProduct Name\tQuantity\tPrice\n");
            for(int i=0; i<size; i++) {
                printf("%d\t%s\t%d\t%.2f\n", i+1, (*warehouse)[i].name, (*warehouse)[i].quantity, (*warehouse)[i].price);
            }
            break;

        case 3:
            printf("\nExiting...\n");
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
    }
}

// Function to view all products in the warehouse
void viewProducts(struct Product *warehouse, int size) {
    printf("\nWarehouse:\n");
    printf("-----------------------------\n");
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");
    for(int i=0; i<size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i+1, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
    printf("-----------------------------\n");
}

// Main function
int main() {
    int size = 0;
    struct Product *warehouse = (struct Product *)malloc(100 * sizeof(struct Product)); // Allocate memory for 100 products
    int capacity = 100;

    while(1) {
        addProduct(warehouse, size, capacity);
        viewProducts(warehouse, size);
    }

    return 0;
}