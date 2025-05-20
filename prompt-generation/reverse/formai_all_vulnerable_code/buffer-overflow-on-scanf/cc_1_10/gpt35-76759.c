//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int quantity;
    float price;
};

void addProduct(struct Product products[], int *pCount)
{
    printf("\nAdd New Product\n");
    printf("----------------\n");

    printf("Enter the Product Name: ");
    scanf("%s", products[*pCount].name);

    printf("Enter the Product Quantity: ");
    scanf("%d", &products[*pCount].quantity);

    printf("Enter the Product Price: ");
    scanf("%f", &products[*pCount].price);

    *pCount += 1;

    printf("\nProduct added successfully!\n\n");
}

void searchProduct(struct Product products[], int count)
{
    char name[50];
    int found = 0;

    printf("\nSearch Product\n");
    printf("----------------\n");

    printf("Enter the Product Name: ");
    scanf("%s", name);

    for (int i = 0; i < count; i++)
    {
        if (strcmp(products[i].name, name) == 0)
        {
            printf("\nProduct Found!\n\n");
            printf("Product Name   : %s\n", products[i].name);
            printf("Product Quantity   : %d\n", products[i].quantity);
            printf("Product Price  : $%.2f\n", products[i].price);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nProduct not found!\n\n");
}

void printInventory(struct Product products[], int count)
{
    printf("\nInventory Report\n");
    printf("----------------\n");

    for (int i = 0; i < count; i++)
    {
        printf("Product Name   : %s\n", products[i].name);
        printf("Product Quantity   : %d\n", products[i].quantity);
        printf("Product Price  : $%.2f\n", products[i].price);
        printf("-------------------------\n");
    }
}

int main()
{
    struct Product products[100];
    int count = 0;
    int choice;
    char exitChoice = 'n';

    printf("Warehouse Management System\n");
    printf("---------------------------\n");

    do
    {
        printf("\n1. Add Product");
        printf("\n2. Search Product");
        printf("\n3. Print Inventory Report");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addProduct(products, &count); break;
            case 2: searchProduct(products, count); break;
            case 3: printInventory(products, count); break;
            case 4: 
                printf("\nAre you sure you want to exit? (y/n): ");
                scanf(" %c", &exitChoice);
                break;
            default: printf("\nInvalid choice!\n\n"); break;
        }
    } while (exitChoice != 'y');

    printf("\nThank you for using the Warehouse Management System!\n");

    return 0;
}