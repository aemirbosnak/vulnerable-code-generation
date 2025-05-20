//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include<stdio.h>
#include<string.h>

void addProduct(int ids[], char names[][20], float prices[], int qtys[], int* count);
void displayProduct(int ids[], char names[][20], float prices[], int qtys[], int count);
void searchProduct(int ids[], char names[][20], float prices[], int qtys[], int count);

int main()
{
    int ids[50], count=0, choice;
    float prices[50];
    int qtys[50];
    char names[50][20];

    do
    {
        printf("Product Inventory System\n");
        printf("1. Add a product\n");
        printf("2. Display all products\n");
        printf("3. Search a product\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: addProduct(ids, names, prices, qtys, &count);
                    break;

            case 2: displayProduct(ids, names, prices, qtys, count);
                    break;

            case 3: searchProduct(ids, names, prices, qtys, count);
                    break;

            case 4: printf("Thank you! Exiting Program...\n");
                    break;

            default: printf("Invalid choice! Try Again.\n");
                     break;
        }

    }while(choice != 4);

    return 0;
}

void addProduct(int ids[], char names[][20], float prices[], int qtys[], int* count)
{
    printf("\nEnter Product ID: ");
    scanf("%d", &ids[*count]);

    printf("Enter Product Name: ");
    scanf("%s", names[*count]);

    printf("Enter Product Price: ");
    scanf("%f", &prices[*count]);

    printf("Enter Product Quantity: ");
    scanf("%d", &qtys[*count]);

    (*count)++;
    printf("Product added successfully.\n\n");
}

void displayProduct(int ids[], char names[][20], float prices[], int qtys[], int count)
{
    if(count == 0)
    {
        printf("\nNo Products Found.\n\n");
        return;
    }

    printf("\nProduct ID \t Product Name \t Product Price \t Product Quantity\n");
    printf("------------------------------------------------------------------\n");

    for(int i=0; i<count; i++)
    {
        printf("%d \t\t %s \t\t %.2f \t\t %d\n", ids[i], names[i], prices[i], qtys[i]);
    }

    printf("\n");
}

void searchProduct(int ids[], char names[][20], float prices[], int qtys[], int count)
{
    if(count == 0)
    {
        printf("\nNo Products Found.\n\n");
        return;
    }

    int search_id, found=0;

    printf("\nEnter the Product ID to search: ");
    scanf("%d", &search_id);

    for(int i=0; i<count; i++)
    {
        if(search_id == ids[i])
        {
            printf("\nProduct found!\n\n");
            printf("\nProduct ID \t Product Name \t Product Price \t Product Quantity\n");
            printf("------------------------------------------------------------------\n");

            printf("%d \t\t %s \t\t %.2f \t\t %d\n\n", ids[i], names[i], prices[i], qtys[i]);

            found=1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nProduct not found.\n\n");
    }
}