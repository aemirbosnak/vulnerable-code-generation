//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void morph_bill(int choice)
{
    switch (choice)
    {
        case 1:
            printf("Welcome to the Coffee Beanery!\n");
            printf("Please select a beverage:\n");
            printf("1. Espresso\n");
            printf("2. Latte\n");
            printf("3. Cappuccino\n");
            printf("4. Mocha\n");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    printf("You ordered an espresso. Price: $3.00\n");
                    break;
                case 2:
                    printf("You ordered a latte. Price: $4.00\n");
                    break;
                case 3:
                    printf("You ordered a cappuccino. Price: $5.00\n");
                    break;
                case 4:
                    printf("You ordered a mocha. Price: $6.00\n");
                    break;
            }
            break;
        case 2:
            printf("Welcome to the Teapot Cafe!\n");
            printf("Please select a tea:\n");
            printf("1. Black Tea\n");
            printf("2. Green Tea\n");
            printf("3. Herbal Tea\n");
            scanf("%d", &choice);
            switch (choice)
            {
                case 1:
                    printf("You ordered black tea. Price: $2.00\n");
                    break;
                case 2:
                    printf("You ordered green tea. Price: $3.00\n");
                    break;
                case 3:
                    printf("You ordered herbal tea. Price: $4.00\n");
                    break;
            }
            break;
    }
}

int main()
{
    int choice;
    printf("Please select a cafe:\n");
    printf("1. Coffee Beanery\n");
    printf("2. Teapot Cafe\n");
    scanf("%d", &choice);
    morph_bill(choice);
    return 0;
}