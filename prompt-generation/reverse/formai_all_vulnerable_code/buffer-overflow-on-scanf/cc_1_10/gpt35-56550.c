//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

//Function to display the main menu
void showMenu()
{
    printf("\n\t\tCafe Billing System");
    printf("\n\t\t-----------------------\n");
    printf("\nPlease select an option:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Show bill\n");
    printf("4. Exit\n");
}


int main()
{
    //Declaring variables
    int option, itemID, quantity, flag, totalBill = 0;

    //Creating an array to store the menu items
    char items[5][20] = {"Samosa", "Sandwich", "Pizza", "Burger", "Coffee"};

    //Creating an array to store the prices of the menu items
    int prices[5] = {10, 20, 50, 40, 30};

    //Creating an array to store the quantity of the menu items ordered
    int quantityArr[5] = {0, 0, 0, 0, 0};

    printf("\t\t Welcome to Cafe Billing System \n ");

    do
    {
        showMenu();
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                flag = 0;
                printf("\nEnter item ID (1-5): ");
                scanf("%d", &itemID);
                if (itemID < 1 || itemID > 5)
                {
                    printf("\nInvalid Item ID! Please try again.\n");
                    break;
                }

                printf("\nEnter quantity: ");
                scanf("%d", &quantity);

                if (quantity <= 0)
                {
                    printf("\nInvalid quantity! Please try again.\n");
                    break;
                }

                //Updating the quantity of the respective item
                quantityArr[itemID-1] += quantity;
                printf("\n  %s(s) added successfully!\n", items[itemID-1]);

                break;

            case 2:
                flag = 0;
                printf("\nEnter item ID (1-5): ");
                scanf("%d", &itemID);
                if (itemID < 1 || itemID > 5)
                {
                    printf("\nInvalid Item ID! Please try again.\n");
                    break;
                }

                printf("\nEnter quantity: ");
                scanf("%d", &quantity);

                if (quantity <= 0)
                {
                    printf("\nInvalid quantity! Please try again.\n");
                    break;
                }

                //Updating the quantity of the respective item
                if(quantityArr[itemID-1] >= quantity)
                {
                    quantityArr[itemID-1] -= quantity;
                    printf("\n %s(s) removed successfully!\n", items[itemID-1]);
                }
                else
                    printf("You don't have the required quantity of %s!\n", items[itemID-1]);

                break;

            case 3:
                flag = 1;
                printf("\nBill:\n");
                printf("--------------\n");
                printf("Item \t  Quantity  \t  Price \t  Total\n");
                for(int i=0; i<5; i++)
                {
                    if(quantityArr[i])
                    {
                        printf("%s \t  %d \t    %d \t  %d\n", items[i], quantityArr[i], prices[i], (prices[i]*quantityArr[i]));
                        totalBill += (prices[i]*quantityArr[i]);
                    }
                }
                printf("--------------\n");
                printf("Total Bill: \t\t\t\t%d", totalBill);

                break;
            case 4:
                exit(0);

            default:
                printf("\nInvalid option! Please try again.\n");
        }

    }while(option != 4);

    return 0;
}