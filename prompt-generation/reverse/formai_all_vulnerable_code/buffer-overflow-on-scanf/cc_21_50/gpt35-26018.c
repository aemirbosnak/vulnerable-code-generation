//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int randomNum = rand() % 10 + 1;
    char answer;

    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Think of a yes or no question in your mind and press enter to continue.\n\n");
    getchar();

    // check the random number for a fortune
    if (randomNum == 1)
    {
        printf("The answer is yes.\n");
    }
    else if (randomNum == 2)
    {
        printf("The answer is no.\n");
    }
    else if (randomNum == 3)
    {
        printf("It is certain.\n");
    }
    else if (randomNum == 4)
    {
        printf("Don't count on it.\n");
    }
    else if (randomNum == 5)
    {
        printf("My sources say no.\n");
    }
    else if (randomNum == 6)
    {
        printf("Outlook not so good.\n");
    }
    else if (randomNum == 7)
    {
        printf("Yes, definitely.\n");
    }
    else if (randomNum == 8)
    {
        printf("Cannot predict now.\n");
    }
    else if (randomNum == 9)
    {
        printf("Very doubtful.\n");
    }
    else
    {
        printf("Ask again later.\n");
    }

    printf("\nWould you like to ask another question? (y/n): ");
    scanf("%c", &answer);

    // check if user wants to ask another question
    while (answer == 'y' || answer == 'Y')
    {
        randomNum = rand() % 10 + 1;
        printf("\nThink of a yes or no question in your mind and press enter to continue.\n\n");
        getchar();

        if (randomNum == 1)
        {
            printf("The answer is yes.\n");
        }
        else if (randomNum == 2)
        {
            printf("The answer is no.\n");
        }
        else if (randomNum == 3)
        {
            printf("It is certain.\n");
        }
        else if (randomNum == 4)
        {
            printf("Don't count on it.\n");
        }
        else if (randomNum == 5)
        {
            printf("My sources say no.\n");
        }
        else if (randomNum == 6)
        {
            printf("Outlook not so good.\n");
        }
        else if (randomNum == 7)
        {
            printf("Yes, definitely.\n");
        }
        else if (randomNum == 8)
        {
            printf("Cannot predict now.\n");
        }
        else if (randomNum == 9)
        {
            printf("Very doubtful.\n");
        }
        else
        {
            printf("Ask again later.\n");
        }

        printf("\nWould you like to ask another question? (y/n): ");
        scanf(" %c", &answer);
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}