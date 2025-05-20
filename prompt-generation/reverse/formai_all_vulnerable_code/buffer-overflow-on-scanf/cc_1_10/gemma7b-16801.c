//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *);

int main()
{
    char str[256];
    int i, total = 0, choice, item_no;

    printf("Welcome to Cryptic Cafe Billing System!\n\n");

    printf("Please select an option:\n");
    printf("1. Order\n");
    printf("2. View Menu\n");
    printf("3. Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter item number:");
            scanf("%d", &item_no);

            printf("Enter item name:");
            scanf("%s", str);

            encrypt(str);

            printf("Enter quantity:");
            scanf("%d", &i);

            total += i * item_no;

            printf("Item added to the order.\n");
            break;

        case 2:
            printf("Here is the menu:\n");
            // List of items
            break;

        case 3:
            printf("Thank you for your visit. Total amount: $%d\n", total);
            exit(0);
            break;

        default:
            printf("Invalid input.\n");
            break;
    }

    main();
}

void encrypt(char *str)
{
    int i, len = strlen(str);

    for (i = 0; i < len; i++)
    {
        str[i] = str[i] + 3;
    }
}