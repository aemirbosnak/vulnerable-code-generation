//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int mainMenu = 0;
char menu[10] = {'A', 'B', 'C'};
float stock[3] = {10, 5, 15};

int main()
{
    printf("Welcome to the Medical Store Management System!\n");

    while (mainMenu!= 5)
    {
        printf("\n1. Show Stock\n2. Add Medicine\n3. Remove Medicine\n4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &mainMenu);

        if (mainMenu == 1)
        {
            printf("\nCurrent Stock:\n");

            for (int i = 0; i < 3; i++)
            {
                if (menu[i] == 'A')
                {
                    printf("Medicine A - %f\n", stock[i]);
                }
                else if (menu[i] == 'B')
                {
                    printf("Medicine B - %f\n", stock[i]);
                }
                else if (menu[i] == 'C')
                {
                    printf("Medicine C - %f\n", stock[i]);
                }
            }
        }
        else if (mainMenu == 2)
        {
            printf("Add Medicine:\n");

            for (int i = 0; i < 3; i++)
            {
                printf("Enter the name of the medicine: ");
                scanf("%s", &menu[i]);

                printf("Enter the stock of the medicine: ");
                scanf("%f", &stock[i]);
            }
        }
        else if (mainMenu == 3)
        {
            printf("Remove Medicine:\n");

            for (int i = 0; i < 3; i++)
            {
                printf("Enter the name of the medicine to remove: ");
                scanf("%s", &menu[i]);

                printf("Enter the stock to remove: ");
                scanf("%f", &stock[i]);
            }
        }
        else if (mainMenu == 4)
        {
            printf("Thank you for using our Medical Store Management System!\n");
            break;
        }
    }

    return 0;
}