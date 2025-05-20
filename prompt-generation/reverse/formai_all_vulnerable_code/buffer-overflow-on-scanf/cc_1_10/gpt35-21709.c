//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product
{
    char name[20];
    float price;
    int quantity;
};

void addProduct(struct product *p, int *size)
{
    printf("\nEnter product name: ");
    scanf("%s", p[*size].name);
    printf("Enter product price: ");
    scanf("%f", &p[*size].price);
    printf("Enter product quantity: ");
    scanf("%d", &p[*size].quantity);
    (*size)++;
    printf("\nProduct added successfully!\n");
}

void viewInventory(struct product *p, int size)
{
    if(size == 0)
    {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\nProduct Name\tProduct Price\tProduct Quantity\n");
    for(int i = 0; i < size; i++)
    {
        printf("%s\t\t%.2f\t\t%d\n", p[i].name, p[i].price, p[i].quantity);
    }
}

void findProduct(struct product *p, int size)
{
    char pname[20];
    printf("\nEnter product name: ");
    scanf("%s", pname);
    int flag = 0;
    for(int i = 0; i < size; i++)
    {
        if(strcmp(p[i].name, pname) == 0)
        {
            printf("\nProduct found!\nProduct Name: %s\nPrice: %.2f\nQuantity: %d\n", p[i].name, p[i].price, p[i].quantity);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nProduct not found!\n");
    }
}

void sellProduct(struct product *p, int size)
{
    char pname[20];
    printf("\nEnter product name: ");
    scanf("%s", pname);
    int flag = 0;
    for(int i = 0; i < size; i++)
    {
        if(strcmp(p[i].name, pname) == 0)
        {
            int quantity;
            printf("\nEnter quantity to sell: ");
            scanf("%d", &quantity);
            if(quantity > p[i].quantity)
            {
                printf("\nInsufficient quantity of product in inventory!\n");
                flag = 1;
                break;
            }
            p[i].quantity -= quantity;
            printf("\nSold %d units of %s successfully!\n", quantity, pname);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nProduct not found!\n");
    }
}

int main()
{
    struct product p[50];
    int size = 0, choice;
    do
    {
        printf("\n===== Product Inventory System =====\n");
        printf("\n1. Add Product\n2. View Inventory\n3. Find Product\n4. Sell Product\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addProduct(p, &size);
                break;
            case 2:
                viewInventory(p, size);
                break;
            case 3:
                findProduct(p, size);
                break;
            case 4:
                sellProduct(p, size);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while(choice != 5);
    return 0;
}