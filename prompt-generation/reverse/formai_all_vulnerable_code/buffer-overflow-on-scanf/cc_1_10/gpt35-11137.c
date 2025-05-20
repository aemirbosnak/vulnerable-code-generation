//FormAI DATASET v1.0 Category: Product Inventory System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Product
{
    char name[20];
    int quantity;
    float price;
};

struct Product stock[MAX];
int size = 0;

void addProduct()
{
    printf("\n------------------------------------");
    printf("\n           ADD NEW PRODUCT          ");
    printf("\n------------------------------------");

    if(size >= MAX)
    {
        printf("\nInventory is Full.");
        return;
    }

    printf("\nEnter Product Name: ");
    scanf("%s", stock[size].name);
    printf("Enter Product Quantity: ");
    scanf("%d", &stock[size].quantity);
    printf("Enter Product Price: ");
    scanf("%f", &stock[size].price);

    size++;

    printf("\nProduct Added Successfully.\n");
}

void displayAllProducts()
{
    printf("\n------------------------------------");
    printf("\n         LIST OF ALL PRODUCTS       ");
    printf("\n------------------------------------");

    if(size == 0)
    {
        printf("\nInventory is Empty.\n");
        return;
    }

    printf("\nProduct Name\tQuantity\tPrice\n");

    for(int i=0; i<size; i++)
    {
        printf("%s\t\t%d\t\t%.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
}

void searchProduct()
{
    char searchName[20];
    int found = 0;

    printf("\n------------------------------------");
    printf("\n           SEARCH FOR PRODUCT       ");
    printf("\n------------------------------------");

    printf("\nEnter Product Name: ");
    scanf("%s", searchName);

    for(int i=0; i<size; i++)
    {
        if(strcmp(searchName, stock[i].name) == 0)
        {
            printf("\nProduct Found.");
            printf("\nProduct Name: %s", stock[i].name);
            printf("\nProduct Quantity: %d", stock[i].quantity);
            printf("\nProduct Price: %.2f\n", stock[i].price);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nProduct not Found.\n");
}

void updateProduct()
{
    char searchName[20];
    int found = 0;

    printf("\n------------------------------------");
    printf("\n           UPDATE A PRODUCT         ");
    printf("\n------------------------------------");

    printf("\nEnter Product Name: ");
    scanf("%s", searchName);

    for(int i=0; i<size; i++)
    {
        if(strcmp(searchName, stock[i].name) == 0)
        {
            printf("\nProduct Found.");
            printf("\nProduct Name: %s", stock[i].name);
            printf("\nProduct Quantity: %d", stock[i].quantity);
            printf("\nProduct Price: %.2f\n", stock[i].price);

            printf("\nEnter New Quantity: ");
            scanf("%d", &stock[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &stock[i].price);

            found = 1;
            break;
        }
    }

    if(!found)
        printf("\nProduct not Found.\n");
    else
        printf("\nProduct Updated Successfully.\n");
}

void deleteProduct()
{
    char searchName[20];
    int found = 0;

    printf("\n------------------------------------");
    printf("\n           DELETE A PRODUCT         ");
    printf("\n------------------------------------");

    printf("\nEnter Product Name: ");
    scanf("%s", searchName);

    for(int i=0; i<size; i++)
    {
        if(strcmp(searchName, stock[i].name) == 0)
        {
            printf("\nProduct Found.");
            printf("\nProduct Name: %s", stock[i].name);
            printf("\nProduct Quantity: %d", stock[i].quantity);
            printf("\nProduct Price: %.2f\n", stock[i].price);

            printf("\nAre you sure you want to delete this product?(y/n): ");
            char ch[5];
            scanf("%s", ch);

            if(strcmp(ch, "y")==0)
            {
                for(int j=i; j<size; j++)
                {
                    stock[j] = stock[j+1];
                }

                size--;
                found = 1;
                printf("\nProduct Deleted Successfully.\n");
                break;
            }
            else
            {
                printf("\nDeletion Cancelled.\n");
                found = 1;
                break;
            }
        }
    }

    if(!found)
        printf("\nProduct not Found.\n");
}

int main()
{
    int choice;

    printf("\n------------------------------------");
    printf("\n       PRODUCT INVENTORY SYSTEM     ");
    printf("\n------------------------------------");

    while(1)
    {
        printf("\n1. Add a Product\n2. Display all Products\n3. Search for a Product\n4. Update a Product\n5. Delete a Product\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addProduct();
                break;
            case 2:
                displayAllProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                updateProduct();
                break;
            case 5:
                deleteProduct();
                break;
            case 6:
                printf("\nExiting Program.\n");
                exit(0);
            default:
                printf("\nInvalid Choice. Try Again.\n");
        }
    }
    
    return 0;
}