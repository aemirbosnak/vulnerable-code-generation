//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include<stdio.h> 

struct product {
    char name[50];
    int quantity;
};

void display(struct product p[], int n) // Function to display product details
{
    printf("Name\tQuantity\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\n", p[i].name, p[i].quantity);
    }
}

int main()
{
    int n, choice, index; 

    printf("Enter number of products: ");
    scanf("%d",&n);

    struct product p[n];

    for(int i=0;i<n;i++) //Taking Input
    {
        printf("Enter name of product %d: ",i+1);
        scanf("%s", p[i].name);

        printf("Enter quantity of product %d: ",i+1);
        scanf("%d",&p[i].quantity);
    }

    while(choice!=-1) //Menu-Driven Interface
    {
        printf("\n1. Add quantity of a product\n");
        printf("2. Remove quantity of a product\n");
        printf("3. Display product details\n");
        printf("-1. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter index of product to add quantity: ");
                scanf("%d",&index);

                printf("Enter quantity to add: ");
                int qty_add;
                scanf("%d",&qty_add);

                p[index].quantity+=qty_add;
                printf("\nAfter adding quantity:\n");
                display(p,n);
                break;

            case 2:
                printf("\nEnter index of product to remove quantity: ");
                scanf("%d",&index);

                printf("Enter quantity to remove: ");
                int qty_remove;
                scanf("%d",&qty_remove);

                p[index].quantity-=qty_remove;
                printf("\nAfter removing quantity:\n");
                display(p,n);
                break;

            case 3:
                display(p,n);
                break;

            case -1:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid Choice. Try Again!\n");         
        }
    }

    return 0;   
}