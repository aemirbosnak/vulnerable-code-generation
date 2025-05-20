//Gemma-7B DATASET v1.0 Category: Product Inventory System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

typedef struct Product
{
    char name[50];
    int quantity;
    float price;
} Product;

int main()
{
    Product inventory[100];
    int i = 0;
    char input[50];

    printf("Welcome to the C Product Inventory System!\n");
    printf("------------------------\n");

    // Create a new product
    printf("Enter the name of the product: ");
    scanf("%s", inventory[i].name);

    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[i].quantity);

    printf("Enter the price of the product: ");
    scanf("%f", &inventory[i].price);

    i++;

    // Print the inventory
    printf("Here is your inventory:\n");
    for (int j = 0; j < i; j++)
    {
        printf("%s - %d - %.2f\n", inventory[j].name, inventory[j].quantity, inventory[j].price);
    }

    // Search for a product
    printf("Enter the name of the product you want to search for: ");
    scanf("%s", input);

    for (int j = 0; j < i; j++)
    {
        if (strcmp(inventory[j].name, input) == 0)
        {
            printf("Found! %s - %d - %.2f\n", inventory[j].name, inventory[j].quantity, inventory[j].price);
        }
    }

    return 0;
}