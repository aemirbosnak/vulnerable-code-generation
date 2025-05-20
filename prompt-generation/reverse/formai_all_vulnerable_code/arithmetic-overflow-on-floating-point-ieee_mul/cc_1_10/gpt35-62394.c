//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Product Inventory System v1.0! Wandering through the land of code, anything is possible...\n");

    char productName[100];
    int productQuantity = 0;
    float productPrice = 0.0;

    printf("Enter the name of the product: ");
    fgets(productName, 100, stdin);

    printf("Enter the quantity of the product: ");
    scanf("%d", &productQuantity);

    printf("Enter the price of the product: ");
    scanf("%f", &productPrice);

    char *productNameCopy = (char *) malloc(strlen(productName) + 1);
    strcpy(productNameCopy, productName);

    printf("\n\nYou have entered the following data:\n");
    printf("Product Name: %s\n", productNameCopy);
    printf("Product Quantity: %d\n", productQuantity);
    printf("Product Price: %.2f\n", productPrice);

    printf("\n\nOh, wait... something is not right here! Let's change something a bit...\n");
    productPrice = productPrice * 2;

    printf("Product Price: %.2f\n\n", productPrice);

    printf("The product with name %s, quantity of %d and price of %.2f has been successfully added to the inventory!\n\n", productNameCopy, productQuantity, productPrice);

    printf("Let's take a stroll through the inventory and see what we can find...\n");

    printf("--------------------------------------------------------------\n");
    printf("| %20s | %15s | %10s |\n", "Product Name", "Quantity", "Price");
    printf("--------------------------------------------------------------\n");
    printf("| %20s | %15d | %10.2f |\n", productNameCopy, productQuantity, productPrice);
    printf("--------------------------------------------------------------\n");

    printf("\nThe land of code is amazing, isn't it? Until we meet again, wander wisely...\n");

    free(productNameCopy);

    return 0;
}