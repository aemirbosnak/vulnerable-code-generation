//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller()
{
    char answer;
    int number;
    time_t t;

    t = time(NULL);
    srand(t);

    printf("Would you like to hear your fortune? (Y/N) ");
    scanf(" %c", &answer);

    if (answer == 'Y')
    {
        number = rand() % 10;
        switch (number)
        {
            case 0:
                printf("You will have a lucky day today.\n");
                break;
            case 1:
                printf("You will find love.\n");
                break;
            case 2:
                printf("You will have a lot of money.\n");
                break;
            case 3:
                printf("You will travel to a new place.\n");
                break;
            case 4:
                printf("You will have a lot of fun.\n");
                break;
            case 5:
                printf("You will be successful in your studies.\n");
                break;
            case 6:
                printf("You will have a healthy life.\n");
                break;
            case 7:
                printf("You will have a lucky number.\n");
                break;
            case 8:
                printf("You will have a lot of friends.\n");
                break;
            case 9:
                printf("You will have a fulfilling life.\n");
                break;
        }
    }
    else
    {
        printf("Thank you for your time.\n");
    }
}

int main()
{
    fortune_teller();

    return 0;
}