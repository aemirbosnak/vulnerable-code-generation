//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct Product
{
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];

void displayProducts()
{
    int i = 0;
    for (i = 0; products[i].name[0] != '\0'; i++)
    {
        printf("%s, %d, %.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void addNewProduct()
{
    Product newProduct;
    printf("Enter product name: ");
    scanf("%s", newProduct.name);
    printf("Enter quantity: ");
    scanf("%d", &newProduct.quantity);
    printf("Enter price: ");
    scanf("%f", &newProduct.price);

    int i = 0;
    for (i = 0; products[i].name[0] != '\0'; i++)
    {
        if (products[i].name[0] == '\0')
        {
            products[i] = newProduct;
            break;
        }
    }

    if (i == MAX_PRODUCTS - 1)
    {
        printf("Error: Maximum number of products reached.\n");
    }
}

void updateQuantity(char *name, int quantity)
{
    int i = 0;
    for (i = 0; products[i].name[0] != '\0'; i++)
    {
        if (strcmp(products[i].name, name) == 0)
        {
            products[i].quantity = quantity;
            break;
        }
    }

    if (i == MAX_PRODUCTS - 1)
    {
        printf("Error: Product not found.\n");
    }
}

void deleteProduct(char *name)
{
    int i = 0;
    for (i = 0; products[i].name[0] != '\0'; i++)
    {
        if (strcmp(products[i].name, name) == 0)
        {
            products[i].name[0] = '\0';
            break;
        }
    }

    if (i == MAX_PRODUCTS - 1)
    {
        printf("Error: Product not found.\n");
    }
}

int main()
{
    addNewProduct();
    addNewProduct();
    updateQuantity("Product 1", 10);
    deleteProduct("Product 2");
    displayProducts();

    return 0;
}