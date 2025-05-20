//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include<stdio.h>
#include<string.h>

struct Product
{
    int prodId, quantity;
    char prodName[50];
    float price;
};

void addProduct(struct Product p[], int pos)
{

    printf("\nEnter Product ID: ");
    scanf("%d", &p[pos].prodId);

    printf("Enter Product Name: ");
    scanf("%s", p[pos].prodName);

    printf("Enter Product Quantity: ");
    scanf("%d", &p[pos].quantity);

    printf("Enter Product Price: ");
    scanf("%f", &p[pos].price);
}

void viewAllProducts(struct Product p[], int n)
{
    printf("\nProduct ID\tProduct Name\tProduct Quantity\tProduct Price\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", p[i].prodId, p[i].prodName, p[i].quantity, p[i].price);
    }
}

void searchProduct(struct Product p[], int n, int prodId)
{
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        if(p[i].prodId == prodId)
        {
            printf("\nProduct ID\tProduct Name\tProduct Quantity\tProduct Price\n");
            printf("%d\t\t%s\t\t%d\t\t%.2f\n", p[i].prodId, p[i].prodName, p[i].quantity, p[i].price);
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        printf("\nProduct ID %d not found!\n", prodId);
    }
}

void updateProduct(struct Product p[], int n, int prodId)
{
    int flag = 0;
    for(int i=0; i<n; i++)
    {
        if(p[i].prodId == prodId)
        {
            printf("\nEnter new Product Name: ");
            scanf("%s", p[i].prodName);

            printf("Enter new Product Quantity: ");
            scanf("%d", &p[i].quantity);

            printf("Enter new Product Price: ");
            scanf("%f", &p[i].price);

            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        printf("\nProduct ID %d not found!\n", prodId);
    }
}

void deleteProduct(struct Product p[], int *n, int prodId)
{
    int flag = 0;
    for(int i=0; i<*n; i++)
    {
        if(p[i].prodId == prodId)
        {
            for(int j=i; j<*n-1; j++)
            {
                p[j] = p[j+1];
            }
            (*n)--;
            flag = 1;
            break;
        }
    }
    if(!flag)
    {
        printf("\nProduct ID %d not found!\n", prodId);
    }
}

int main()
{
    int choice, n=0, prodId;
    struct Product p[100];
    do
    {
        printf("\n==========Warehouse Management System==========\n");
        printf("1. Add Product\n2. View All Products\n3. Search Product\n4. Update Product\n5. Delete Product\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addProduct(p, n);
                n++;
                break;

            case 2:
                viewAllProducts(p, n);
                break;

            case 3:
                printf("\nEnter Product ID to search: ");
                scanf("%d", &prodId);
                searchProduct(p, n, prodId);
                break;

            case 4:
                printf("\nEnter Product ID to update: ");
                scanf("%d", &prodId);
                updateProduct(p, n, prodId);
                break;

            case 5:
                printf("\nEnter Product ID to delete: ");
                scanf("%d", &prodId);
                deleteProduct(p, &n, prodId);
                break;

            case 6:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid Choice!\n");
                break;
        }

    }while(choice!=6);

    return 0;
}