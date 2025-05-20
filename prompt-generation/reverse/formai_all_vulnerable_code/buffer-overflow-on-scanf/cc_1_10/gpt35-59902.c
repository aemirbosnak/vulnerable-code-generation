//FormAI DATASET v1.0 Category: Product Inventory System ; Style: beginner-friendly
// C Product Inventory System
// By: [Your Name]
// Date: [Current Date]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for product
struct Product {
    int id;
    char name[50];
    char description[100];
    float price;
    int quantity;
};

// Prototype for functions
void addProduct(struct Product products[], int *count);
void displayProduct(struct Product products[], int count);
void removeProduct(struct Product products[], int *count);

int main() {
    int choice, count = 0;
    struct Product products[100];

    printf("Welcome to the Product Inventory System\n");

    do {
        printf("\n---------------------------\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Remove a product\n");
        printf("4. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProduct(products, count);
                break;
            case 3:
                removeProduct(products, &count);
                break;
            case 4:
                printf("Thank you for using Product Inventory System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void addProduct(struct Product products[], int *count) {
    struct Product product;
    product.id = *count + 1;

    printf("\nEnter the details for product #%d\n", product.id);

    printf("Enter the product name: ");
    scanf("%s", &product.name);

    printf("Enter the product description: ");
    scanf("%s", &product.description);

    printf("Enter the product price: ");
    scanf("%f", &product.price);

    printf("Enter the product quantity: ");
    scanf("%d", &product.quantity);

    products[*count] = product;

    printf("\nProduct #%d has been added successfully.\n", product.id);
    (*count)++;
}

void displayProduct(struct Product products[], int count) {
    if(count == 0) {
        printf("\nNo products available right now.\n");
        return;
    }

    printf("\n%-5s %-20s %-20s %-10s %-10s\n", "ID", "Name", "Description", "Price", "Quantity");
    for(int i=0; i<count; i++) {
        printf("%-5d %-20s %-20s %-10.2f %-10d\n", products[i].id, products[i].name, products[i].description, products[i].price, products[i].quantity);
    }
}

void removeProduct(struct Product products[], int *count) {
    if(*count == 0) {
        printf("\nNo products available right now.\n");
        return;
    }

    int id, index = -1;

    printf("Enter the ID of the product you want to remove: ");
    scanf("%d", &id);

    for(int i=0; i<*count; i++) {
        if(products[i].id == id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Product with ID %d not found.\n", id);
    } else {
        for(int i=index; i<*count-1; i++) {
            products[i] = products[i+1];
        }

        (*count)--;
        printf("Product with ID %d has been removed successfully.\n", id);
    }
}