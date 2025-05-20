//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, x, y, z;

    srand(time(NULL)); //used to initialize the random seed

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of any number between 1-100 and I will tell you what it means.\n");

    num = rand()%100 + 1; //generating a random number between 1-100

    printf("\n");

    printf("Question 1: Is your number even or odd? (Enter 1 for even/2 for odd)\n");
    scanf("%d", &x);

    if (x == 1) //determining if the number is even or odd
    {
        printf("Question 2: Is your number divisible by 4? (Enter 1 for yes/2 for no)\n");
        scanf("%d", &y);

        if (y == 1) //determining if the number is divisible by 4
        {
            printf("Your number is %d. It means that you have an important decision or choice to make.\n", num);
        }
        else
        {
            printf("Your number is %d. It means that there may be some challenges ahead, but you will succeed.\n", num);
        }
    }
    else
    {
        printf("Question 2: Is your number divisible by 5? (Enter 1 for yes/2 for no)\n");
        scanf("%d", &z);

        if (z == 1) //determining if the number is divisible by 5
        {
            printf("Your number is %d. It means that a change is coming in your life.\n", num);
        }
        else
        {
            printf("Your number is %d. It means that you will receive good news soon.\n", num);
        }
    }

    return 0;
}