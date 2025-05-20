//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include<stdio.h>
#include<stdlib.h>

 struct Warehouse //Defining a structure of Warehouse.
{
    int product_id;
    char product_name[50];
    int quantity;
    float price;
};

void add_product(struct Warehouse w[], int count) //Function definition for adding products to the Warehouse
{
    printf("\n*************** Adding Product ***************\n");
    printf("Enter Product ID: ");
    scanf("%d", &w[count].product_id);
    fflush(stdin);

    printf("Enter Product Name: ");
    gets(w[count].product_name);

    printf("Enter Quantity: ");
    scanf("%d", &w[count].quantity);
    fflush(stdin);

    printf("Enter Price: ");
    scanf("%f", &w[count].price);
    fflush(stdin);

    printf("\nProduct Added successfully. Press any key to continue...");
    getchar();
}

void list_products(struct Warehouse w[], int count) //Function definition for listing products in the Warehouse
{
    printf("\n*************** List of Products ***************\n");
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");

    for(int i=0; i<count; i++)
    {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", w[i].product_id, w[i].product_name, w[i].quantity, w[i].price);
    }
    
    printf("\nPress any key to continue...");
    getchar();
}

void search_product(struct Warehouse w[], int count) //Function definition for searching a product in the Warehouse
{
    int id;
    printf("\n*************** Search Product ***************\n");
    printf("Enter Product ID: ");
    scanf("%d", &id);
    fflush(stdin);

    for(int i=0; i<count; i++)
    {
        if(w[i].product_id==id)
        {
            printf("\nProduct Found!\n");
            printf("Product ID: %d\n", w[i].product_id);
            printf("Product Name: %s\n", w[i].product_name);
            printf("Quantity: %d\n", w[i].quantity);
            printf("Price: %.2f\n", w[i].price);

            printf("\nPress any key to continue...");
            getchar();
            return;
        }
    }

    printf("\nProduct not found. Press any key to continue...");
    getchar();
}

void modify_product(struct Warehouse w[], int count) //Function definition for modifying a product in the Warehouse
{
    int id;
    printf("\n*************** Modify Product ***************\n");
    printf("Enter Product ID to Modify: ");
    scanf("%d", &id);

    for(int i=0; i<count; i++)
    {
        if(w[i].product_id==id)
        {
            printf("Enter new Product Name: ");
            gets(w[i].product_name);

            printf("Enter new Quantity: ");
            scanf("%d", &w[i].quantity);

            printf("Enter new Price: ");
            scanf("%f", &w[i].price);

            printf("\nModifications saved successfully. Press any key to continue...");
            getchar();
            return;
        }
    }

    printf("\nProduct not found. Press any key to continue...");
    getchar();
}

int main()
{
    printf("********************* Warehouse Management System *********************\n");

    int choice=0, count=0;
    struct Warehouse w[100];

    while(choice!=5) //The menu-driven approach has been used to provide flexibility to the user during the program execution..
    {
        printf("\nMain Menu:\n1. Add Product\n2. List Products\n3. Search Product\n4. Modify Product\n5. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_product(w, count++);
                break;

            case 2:
                list_products(w, count);
                break;

            case 3:
                search_product(w, count);
                break;

            case 4:
                modify_product(w, count);
                break;

            case 5:
                exit(0);
        }
    }

    return 0;
}