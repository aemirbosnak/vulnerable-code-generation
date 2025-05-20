//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200
#define MAX_QUANTITY 10000
#define MAX_PRICE 100000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} Product;

void addProduct(Product* products, int count) {
    printf("Enter product name: ");
    scanf("%s", products[count].name);
    printf("Enter product description: ");
    scanf("%s", products[count].description);
    printf("Enter product quantity: ");
    scanf("%d", &products[count].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[count].price);
}

void displayProduct(Product product) {
    printf("Product name: %s\n", product.name);
    printf("Product description: %s\n", product.description);
    printf("Product quantity: %d\n", product.quantity);
    printf("Product price: $%.2f\n\n", product.price);
}

void searchProduct(Product* products, int count, char* name) {
    int i;
    for(i=0; i<count; i++) {
        if(strcmp(products[i].name, name) == 0) {
            displayProduct(products[i]);
        }
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int count = 0;
    char choice;
    
    do {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        
        switch(choice) {
            case '1':
                printf("\nEnter number of products: ");
                scanf("%d", &count);
                printf("Enter product details:\n");
                for(int i=0; i<count; i++) {
                    addProduct(products, i);
                }
                break;
            case '2':
                printf("\nProduct list:\n");
                for(int i=0; i<count; i++) {
                    displayProduct(products[i]);
                }
                break;
            case '3':
                printf("\nEnter product name to search: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                searchProduct(products, count, name);
                break;
            case '4':
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice!= '4');
    
    return 0;
}