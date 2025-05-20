//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 100

// Function to add products
void add_product(char** products, int* quantities, float* prices, int* count)
{
    char name[20];
    float price;
    int quantity;
    if((*count) >= MAX_PRODUCTS)
    {
        printf("Product inventory is full.\n");
        return;
    }
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Enter product price: ");
    scanf("%f", &price);
    products[*count] = (char*)malloc(strlen(name) + 1);
    strcpy(products[*count], name);
    quantities[*count] = quantity;
    prices[*count] = price;
    (*count)++;
}

// Function to remove products
void remove_product(char** products, int* quantities, float* prices, int* count)
{
    char name[20];
    printf("Enter product name to remove: ");
    scanf("%s", name);
    for(int i = 0; i < (*count); i++)
    {
        if(strcmp(products[i], name) == 0)
        {
            (*count)--;
            free(products[i]);
            for(int j = i; j < (*count); j++)
            {
                products[j] = products[j+1];
                quantities[j] = quantities[j+1];
                prices[j] = prices[j+1];
            }
            printf("%s removed from inventory.\n", name);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

// Function to display products in inventory
void display_products(char** products, int* quantities, float* prices, int* count)
{
    printf("Product Inventory:\n");
    printf("Name\tQuantity\tPrice\n");
    for(int i = 0; i < (*count); i++)
    {
        printf("%s\t%d\t\t%.2f\n", products[i], quantities[i], prices[i]);
    }
}

int main()
{
    char* products[MAX_PRODUCTS];
    int quantities[MAX_PRODUCTS];
    float prices[MAX_PRODUCTS];
    int count = 0;
    int option = 0;
    do
    {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                add_product(products, quantities, prices, &count);
                break;
            case 2:
                remove_product(products, quantities, prices, &count);
                break;
            case 3:
                display_products(products, quantities, prices, &count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while(option != 4);
    return 0;
}