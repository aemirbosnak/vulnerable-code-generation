//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, choice, yesno;
    char name[20];
    srand(time(NULL));

    printf("Welcome to the Crystal Ball, %s!\n", name);
    printf("Would you like to see your future? (1/2): ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        num = rand() % 10;
        switch (num)
        {
            case 0:
                printf("You will have a prosperous future.\n");
                break;
            case 1:
                printf("You will have a bright future.\n");
                break;
            case 2:
                printf("You will have a lucky future.\n");
                break;
            case 3:
                printf("You will have a successful future.\n");
                break;
            case 4:
                printf("You will have a prosperous future.\n");
                break;
            case 5:
                printf("You will have a bright future.\n");
                break;
            case 6:
                printf("You will have a lucky future.\n");
                break;
            case 7:
                printf("You will have a successful future.\n");
                break;
            case 8:
                printf("You will have a prosperous future.\n");
                break;
            case 9:
                printf("You will have a bright future.\n");
                break;
            default:
                printf("I do not have the ability to predict the future.\n");
                break;
        }

        printf("Would you like to hear the answer to a yes/no question? (1/2): ");
        scanf("%d", &yesno);

        if (yesno == 1)
        {
            num = rand() % 2;
            switch (num)
            {
                case 0:
                    printf("Yes.\n");
                    break;
                case 1:
                    printf("No.\n");
                    break;
            }
        }
    }
    else
    {
        printf("Thank you for visiting the Crystal Ball, %s.\n", name);
    }

    return 0;
}