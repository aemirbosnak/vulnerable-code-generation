//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int item_code=0, quantity=0, choice=0, total_sales=0;
    float price=0.0, amount=0.0;
    char name[20];

    while(1) // This is an endless loop
    {
        // Display menu and get user choice
        printf("==========C Cafe Billing System==========\n");
        printf("\n1. Add Item\n");
        printf("2. Generate Bill\n");
        printf("3. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n========Add Item========\n");
                printf("Enter item code: ");
                scanf("%d", &item_code);
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("\nItem added successfully!\n");
                break;

            case 2:
                printf("\n========Generate Bill========\n");
                printf("Item Code\tName\tPrice\tQuantity\tAmount\n");

                // Calculate and display bill
                if(item_code==0)
                    printf("\nNo items added yet!\n");
                else
                {
                    amount = quantity * price;
                    total_sales += amount;
                    printf("%d\t%s\t%.2f\t%d\t%.2f\n", item_code, name, price, quantity, amount);
                }
                printf("-------------------------------\n");
                printf("\t\t\tTotal Sales: %d\n", total_sales);
                printf("================================\n");
                break;

            case 3:
                printf("\nGoodbye! See you soon.\n");
                exit(0); // This will exit the program
                break;

            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }
    return 0;
}