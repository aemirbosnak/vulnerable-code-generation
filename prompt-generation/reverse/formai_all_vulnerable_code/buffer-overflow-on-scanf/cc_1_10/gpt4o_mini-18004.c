//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float price;
    int quantity;
} Product;

void addProduct(Product *products, int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }
    
    Product newProduct;
    newProduct.id = *count + 1; // Simple ID assignment based on count
    printf("Enter product name: ");
    scanf(" %[^\n]s", newProduct.name); // Read string with spaces
    printf("Enter price: ");
    scanf("%f", &newProduct.price);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);

    products[*count] = newProduct;
    (*count)++;
    
    printf("Product added successfully!\n");
}

void displayProducts(Product *products, int count) {
    if (count == 0) {
        printf("No products in inventory.\n");
        return;
    }

    printf("\nProduct Inventory:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

void searchProduct(Product *products, int count) {
    char searchName[NAME_LENGTH];
    printf("Enter the product name to search: ");
    scanf(" %[^\n]s", searchName);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(products[i].name, searchName) == 0) {
            printf("\nProduct Found:\n");
            printf("ID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product not found in the inventory.\n");
    }
}

void menu() {
    printf("\nWelcome to the Product Inventory System!\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Search Product\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                displayProducts(products, count);
                break;
            case 3:
                searchProduct(products, count);
                break;
            case 4:
                printf("Exiting the system. Have a peaceful day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}