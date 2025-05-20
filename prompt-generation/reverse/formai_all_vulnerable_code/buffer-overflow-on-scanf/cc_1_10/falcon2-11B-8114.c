//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: distributed
#include <stdio.h>

#define MAX_PRODUCTS 10
#define MAX_INVENTORY 100

typedef struct product_info
{
    char product_name[50];
    int quantity;
    int price;
} Product;

Product products[MAX_PRODUCTS];
int inventory[MAX_INVENTORY];

int main()
{
    // Initialize products
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        products[i].quantity = 0;
        products[i].price = 0;
    }
    
    // Initialize inventory
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        inventory[i] = 0;
    }
    
    // Perform warehouse operations
    printf("Enter product name: ");
    fflush(stdin);
    scanf("%s", products[0].product_name);
    products[0].quantity = 10;
    products[0].price = 10.99;
    
    printf("Enter product name: ");
    fflush(stdin);
    scanf("%s", products[1].product_name);
    products[1].quantity = 20;
    products[1].price = 5.99;
    
    printf("Enter product name: ");
    fflush(stdin);
    scanf("%s", products[2].product_name);
    products[2].quantity = 5;
    products[2].price = 9.99;
    
    // Display inventory and products
    printf("Inventory:\n");
    for (int i = 0; i < MAX_INVENTORY; i++)
    {
        printf("%d\t", inventory[i]);
    }
    printf("\n");
    
    printf("Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        printf("%s\t%d\t%d\n", products[i].product_name, products[i].quantity, products[i].price);
    }
    
    return 0;
}