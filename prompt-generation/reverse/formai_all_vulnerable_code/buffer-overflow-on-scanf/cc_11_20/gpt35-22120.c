//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// struct to hold product information
typedef struct 
{
    char name[50];
    float price;
    int quantity;
} Product;

int main()
{
    Product products[MAX_PRODUCTS];  // initialize an array to hold products
    int numProducts = 0;  // initialize the number of products to zero
    char input[50];

    printf("Welcome to the Product Inventory System!\n");

    while (1)
    {
        printf("\nPlease select an option:\n");
        printf("1. Add a product\n");
        printf("2. View all products\n");
        printf("3. Search for a product\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        fgets(input, 50, stdin);

        // add product option
        if (strcmp(input, "1\n") == 0)
        {
            printf("\nEnter product name: ");
            fgets(products[numProducts].name, 50, stdin);
            printf("Enter product price: ");
            scanf("%f", &products[numProducts].price);
            printf("Enter product quantity: ");
            scanf("%d", &products[numProducts].quantity);
            getchar(); // get rid of extra newline character
            numProducts++;
            printf("\nProduct successfully added!\n");
        }

        // view products option
        else if (strcmp(input, "2\n") == 0)
        {
            if (numProducts == 0)
            {
                printf("\nThere are no products in the inventory.\n");
            }
            else
            {
                printf("\nProducts in inventory:\n");
                printf("Name\tPrice\tQuantity\n");
                for (int i = 0; i < numProducts; i++)
                {
                    printf("%s \t$%.2f \t%d\n", products[i].name, products[i].price, products[i].quantity);
                }
            }
        }

        // search for product option
        else if (strcmp(input, "3\n") == 0)
        {
            if (numProducts == 0)
            {
                printf("\nThere are no products in the inventory.\n");
            }
            else
            {
                int found = 0;
                printf("\nEnter product name: ");
                fgets(input, 50, stdin);

                for (int i = 0; i < numProducts; i++)
                {
                    if (strcmp(products[i].name, input) == 0)
                    {
                        printf("\nProduct found!\n");
                        printf("Name\tPrice\tQuantity\n");
                        printf("%s \t$%.2f \t%d\n", products[i].name, products[i].price, products[i].quantity);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("\nProduct not found.\n");
                }
            }
        }

        // quit option
        else if (strcmp(input, "4\n") == 0)
        {
            printf("\nGoodbye! Thank you for using the Product Inventory System.\n");
            exit(0);  // exit the program
        }

        // invalid option
        else
        {
            printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}