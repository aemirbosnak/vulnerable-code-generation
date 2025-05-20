//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 50
#define MAX_NAME_LENGTH 50

typedef struct{
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(){
    if(numProducts == MAX_PRODUCTS){
        printf("Cannot add more products. Limit reached.\n");
        return;
    }

    Product newProduct;
    printf("Enter name of the product: ");
    fgets(newProduct.name, MAX_NAME_LENGTH, stdin);
    strtok(newProduct.name, "\n"); // Remove trailing newline character
    printf("Enter price of the product: ");
    scanf("%f", &newProduct.price);
    printf("Enter quantity of the product: ");
    scanf("%d", &newProduct.quantity);

    products[numProducts++] = newProduct;
    printf("Product added successfully.\n");
}

void listProducts(){
    if(numProducts == 0){
        printf("No products to display.\n");
        return;
    }

    printf("Name\tPrice\tQuantity\n");
    for(int i = 0; i < numProducts; i++){
        printf("%s\t%.2f\t%d\n", products[i].name, products[i].price, products[i].quantity);
    }
}

void sellProduct(){
    if(numProducts == 0){
        printf("No products to sell.\n");
        return;
    }

    char nameToSell[MAX_NAME_LENGTH];
    printf("Enter name of product to sell: ");
    fgets(nameToSell, MAX_NAME_LENGTH, stdin);
    strtok(nameToSell, "\n"); // Remove trailing newline character

    for(int i = 0; i < numProducts; i++){
        if(strcmp(nameToSell, products[i].name) == 0){
            if(products[i].quantity == 0){
                printf("Product out of stock.\n");
                return;
            }

            printf("Price of %s is %.2f. Enter quantity to sell: ", products[i].name, products[i].price);
            int quantityToSell;
            scanf("%d", &quantityToSell);

            if(quantityToSell > products[i].quantity){
                printf("Not enough quantity in stock.\n");
                return;
            }

            products[i].quantity -= quantityToSell;
            printf("%d %s sold for %.2f each.\n", quantityToSell, products[i].name, products[i].price);
            return;
        }
    }

    printf("Product not found.\n");
}

int main(){
    int choice;
    do{
        printf("\n1. Add product\n");
        printf("2. List products\n");
        printf("3. Sell product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Remove trailing newline character

        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                listProducts();
                break;
            case 3:
                sellProduct();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);

    return 0;
}