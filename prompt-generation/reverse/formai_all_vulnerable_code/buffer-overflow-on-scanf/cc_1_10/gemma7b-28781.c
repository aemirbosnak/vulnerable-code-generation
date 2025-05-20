//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x = 0, y = 0, z = 0, a = 0, b = 0, c = 0, d = 0, e = 0;
    char ch;

    printf("Welcome to the Bizarre Game of Quibble.\n");
    printf("Please enter 'start' to begin.\n");

    scanf("%s", ch);

    if (ch == 'start')
    {
        printf("The game has begun!\n");

        while (x != 9)
        {
            printf("Enter the number of the box you want to open: ");
            scanf("%d", &a);

            printf("You have chosen box number %d.\n", a);

            switch (a)
            {
                case 1:
                    b = rand() % 3 + 1;
                    printf("Inside box 1, there are %d gems.\n", b);
                    break;
                case 2:
                    c = rand() % 4 + 2;
                    printf("Inside box 2, there are %d diamonds.\n", c);
                    break;
                case 3:
                    d = rand() % 5 + 3;
                    printf("Inside box 3, there are %d rubies.\n", d);
                    break;
                case 4:
                    e = rand() % 6 + 4;
                    printf("Inside box 4, there are %d emeralds.\n", e);
                    break;
                default:
                    printf("Invalid box number.\n");
                    break;
            }

            printf("Do you want to continue playing? (y/n) ");
            scanf("%s", ch);

            if (ch == 'n')
            {
                x = 9;
            }
        }

        printf("Thank you for playing the Bizarre Game of Quibble.\n");
    }
    else
    {
        printf("Please try again.\n");
    }

    return 0;
}