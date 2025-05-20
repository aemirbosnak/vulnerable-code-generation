//FormAI DATASET v1.0 Category: Product Inventory System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void menu() {
    printf("\n--- Product Inventory System ---\n");
    printf("1. Add new product\n");
    printf("2. Search product\n");
    printf("3. Update product\n");
    printf("4. Remove product\n");
    printf("5. List all products\n");
    printf("6. Exit\n");
    printf("Enter an option: ");
}

void addProduct() {
    Product product;
    product.id = numProducts + 1;
    printf("\nEnter product name: ");
    scanf("%s", &product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    products[numProducts++] = product;
    printf("\nProduct added successfully!\n");
}

void searchProduct() {
    char name[50];
    printf("\nEnter product name: ");
    scanf("%s", &name);
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(products[i].name, name) == 0) {
            printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: $%0.2f\n", 
                products[i].id, products[i].name, products[i].quantity, products[i].price);
            return;
        }
    }
    printf("\nProduct not found!\n");
}

void updateProduct() {
    int id;
    printf("\nEnter product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            printf("\nEnter new product name: ");
            scanf("%s", &products[i].name);
            printf("Enter new product quantity: ");
            scanf("%d", &products[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &products[i].price);
            printf("\nProduct updated successfully!\n");
            return;
        }
    }
    printf("\nProduct not found!\n");
}

void removeProduct() {
    int id;
    printf("\nEnter product ID: ");
    scanf("%d", &id);
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            for (int j = i; j < numProducts - 1; j++) {
                products[j] = products[j + 1];
            }
            numProducts--;
            printf("\nProduct removed successfully!\n");
            return;
        }
    }
    printf("\nProduct not found!\n");
}

void listProducts() {
    printf("\n--- All Products ---\n");
    for (int i = 0; i < numProducts; i++) {
        printf("\nID: %d\nName: %s\nQuantity: %d\nPrice: $%0.2f\n", 
            products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                searchProduct();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                removeProduct();
                break;
            case 5:
                listProducts();
                break;
            case 6:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please enter a valid option.\n");
        }
    } while (1);
    return 0;
}