//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct product
{
    int id;
    char name[50];
    float price;
    int quantity;
};

int main()
{
    struct product product[10];
    int i, j, n;

    printf("Enter the number of products: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Product ID: ");
        scanf("%d", &product[i].id);
        printf("Enter Product Name: ");
        scanf("%s", product[i].name);
        printf("Enter Product Price: ");
        scanf("%f", &product[i].price);
        printf("Enter Product Quantity: ");
        scanf("%d", &product[i].quantity);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (product[i].id == product[j].id)
            {
                printf("Product ID: %d is already present.\n", product[i].id);
                break;
            }
        }

        if (j == n)
        {
            printf("Product ID: %d is added.\n", product[i].id);
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("Product ID: %d\n", product[i].id);
        printf("Product Name: %s\n", product[i].name);
        printf("Product Price: %.2f\n", product[i].price);
        printf("Product Quantity: %d\n", product[i].quantity);
    }

    return 0;
}