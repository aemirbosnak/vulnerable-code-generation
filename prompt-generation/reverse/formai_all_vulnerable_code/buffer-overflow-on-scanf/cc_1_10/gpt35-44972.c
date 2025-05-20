//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("\tWelcome to the Automated Fortune Teller\n");
    printf("\n");
    printf("This unique program will predict your future based on your favorite color and number.\n");
    printf("Please enter your favorite color (Red, Green, Blue, Yellow, Purple, Orange): \n");

    char color[10];
    scanf("%s", color);

    printf("Please enter your favorite number (1-10): \n");

    int number;
    scanf("%d", &number);

    srand(time(NULL));
    int fortune = rand() % 5;

    if (fortune == 0)
    {
        printf("\n");
        printf("Your fortune is:\n");
        printf("You will soon receive a gift that will change your life!\n");
    }

    else if (fortune == 1)
    {
        printf("\n");
        printf("Your fortune is:\n");
        printf("You will meet the love of your life within the next year!\n");
    }

    else if (fortune == 2)
    {
        printf("\n");
        printf("Your fortune is:\n");
        printf("You will receive unexpected financial gains within the next six months!\n");
    }

    else if (fortune == 3)
    {
        printf("\n");
        printf("Your fortune is:\n");
        printf("You will have an exciting adventure in the near future!\n");
    }

    else
    {
        printf("\n");
        printf("Your fortune is:\n");
        printf("You will receive recognition for your hard work and dedication soon!\n");
    }

    return 0;
}