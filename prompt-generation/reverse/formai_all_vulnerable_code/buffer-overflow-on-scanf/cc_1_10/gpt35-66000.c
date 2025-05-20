//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining the maximum size of the product inventory
#define MAX_SIZE 100

//Defining the structure of the product
struct product{
    int id;
    char name[50];
    int quantity;
    float price;
};

//Defining the function to add a product
void addProduct(struct product products[], int *count)
{
    printf("\n\n===ADD A NEW PRODUCT===\n");
    printf("Enter product id: ");
    scanf("%d",&products[*count].id);
    printf("Enter product name: ");
    scanf("%s", products[*count].name);
    printf("Enter product quantity: ");
    scanf("%d", &products[*count].quantity);
    printf("Enter product price: ");
    scanf("%f", &products[*count].price);
    printf("\nProduct added successfully!\n");
    (*count)++;
}

//Defining the function to search for a product
void searchProduct(struct product products[], int count)
{
    int productId;
    printf("\n\n===SEARCH FOR A PRODUCT===\n");
    printf("Enter the product id: ");
    scanf("%d",&productId);
    for(int i=0;i<count;i++)
    {
        if(products[i].id == productId)
        {
            printf("\nProduct id: %d\n", products[i].id);
            printf("Product name: %s\n", products[i].name);
            printf("Product quantity: %d\n", products[i].quantity);
            printf("Product price: %.2f\n", products[i].price);
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//Defining the function to delete a product
void deleteProduct(struct product products[], int *count)
{
    int productId;
    printf("\n\n===DELETE A PRODUCT===\n");
    printf("Enter the product id: ");
    scanf("%d",&productId);
    for(int i=0;i<*count;i++)
    {
        if(products[i].id == productId)
        {
            for(int j=i;j<*count;j++)
            {
               products[j].id = products[j+1].id;
               strcpy(products[j].name, products[j+1].name);
               products[j].quantity = products[j+1].quantity;
               products[j].price = products[j+1].price;
            }
            (*count)--;
            printf("\nProduct deleted successfully!\n");
            return;
        }
    }
    printf("\nProduct not found!\n");
}

//Defining the function to update a product
void updateProduct(struct product products[], int count)
{
    int productId;
    printf("\n\n===UPDATE A PRODUCT===\n");
    printf("Enter the product id: ");
    scanf("%d",&productId);
    for(int i=0;i<count;i++)
    {
        if(products[i].id == productId)
        {
            printf("\nEnter new product name: ");
            scanf("%s", products[i].name);
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

//Defining the function to display all products
void displayProducts(struct product products[], int count)
{
    printf("\n\n===AVAILABLE PRODUCTS===\n");
    for(int i=0;i<count;i++)
    {
        printf("\n-----------------------\n");
        printf("Product id: %d\n", products[i].id);
        printf("Product name: %s\n", products[i].name);
        printf("Product quantity: %d\n", products[i].quantity);
        printf("Product price: %.2f\n", products[i].price);
    }
    printf("\n");
}

//Main function
int main()
{
    struct product products[MAX_SIZE];
    int count = 0, choice = 0;
    while(1)
    {
        printf("\n\n===C PRODUCT INVENTORY SYSTEM===\n");
        printf("1. Add a product\n");
        printf("2. Search for a product\n");
        printf("3. Delete a product\n");
        printf("4. Update a product\n");
        printf("5. Display all products\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addProduct(products, &count);
                break;
            case 2:
                searchProduct(products, count);
                break;
            case 3:
                deleteProduct(products, &count);
                break;
            case 4:
                updateProduct(products, count);
                break;
            case 5:
                displayProducts(products, count);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice! Please enter again.\n");
        }
    }
    return 0;
}