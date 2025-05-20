//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct() {
    if (productCount < MAX_PRODUCTS) {
        Product p;
        printf("Enter Product ID: ");
        scanf("%d", &p.id);
        printf("Enter Product Name: ");
        scanf("%s", p.name);
        printf("Enter Product Category: ");
        scanf("%s", p.category);
        printf("Enter Product Price: ");
        scanf("%f", &p.price);
        printf("Enter Product Stock: ");
        scanf("%d", &p.stock);
        
        products[productCount++] = p;
        printf("Product added successfully!\n");
    } else {
        printf("Product limit reached! Cannot add more products.\n");
    }
}

void displayProducts() {
    if (productCount == 0) {
        printf("No products available.\n");
        return;
    }
    printf("\nProduct List:\n");
    printf("ID\tName\t\tCategory\tPrice\tStock\n");
    for (int i = 0; i < productCount; i++) {
        printf("%d\t%s\t\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].category, products[i].price, products[i].stock);
    }
}

void searchProduct() {
    int id, found = 0;
    printf("Enter Product ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            printf("Product Found: ID: %d, Name: %s, Category: %s, Price: %.2f, Stock: %d\n", products[i].id, products[i].name, products[i].category, products[i].price, products[i].stock);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            for (int j = i; j < productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            productCount--;
            printf("Product with ID %d deleted successfully!\n", id);
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void updateProduct() {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            printf("Enter new Product Name: ");
            scanf("%s", products[i].name);
            printf("Enter new Product Category: ");
            scanf("%s", products[i].category);
            printf("Enter new Product Price: ");
            scanf("%f", &products[i].price);
            printf("Enter new Product Stock: ");
            scanf("%d", &products[i].stock);
            printf("Product updated successfully!\n");
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d not found!\n", id);
    }
}

void showMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Product\n");
    printf("2. Display Products\n");
    printf("3. Search Product\n");
    printf("4. Delete Product\n");
    printf("5. Update Product\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                updateProduct();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}