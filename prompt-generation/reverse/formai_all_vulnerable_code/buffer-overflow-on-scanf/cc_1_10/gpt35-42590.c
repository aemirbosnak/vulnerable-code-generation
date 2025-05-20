//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include<stdio.h>
#include<string.h>

int main()
{
    int item[10], q[10], i, total = 0, choice, price[10] = { 20,30,40,50,60,70,80,90,100,110 };
    char ch[10], name[20];

    printf("\nWelcome to Imaginary Cafe Billing System!\n");

    printf("\nEnter your name: ");
    scanf("%s", name);

    do
    {
        printf("\n1. Add item\n2. Show Bill\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter item number: ");
            scanf("%d", &i);
            printf("Enter quantity: ");
            scanf("%d", &q[i]);
            total += price[i] * q[i];
            break;

        case 2:
            printf("\nYour bill\n");

            for (i = 0; i < 10; i++)
            {
                if (q[i] != 0)
                {
                    printf("%d x Rs%d = Rs%d\n", q[i], price[i], q[i] * price[i]);
                }
            }

            if (total != 0)
            {
                printf("-----------------------------------\n");
                printf("Total=Rs%d\n", total);
            }
            else
            {
                printf("No order taken yet!\n");
            }
            break;

        case 3:
            printf("\nThank you %s for visiting Imaginary Cafe! Please come again!\n", name);
            break;

        default:
            printf("\nInvalid option! Please select a valid option!\n");
        }

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y');

    return 0;
}