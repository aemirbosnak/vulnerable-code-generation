//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int birthYear, age, luckyNum;
    int sum = 0;
    int num1, num2, num3;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Please enter your birth year: ");
    scanf("%d", &birthYear);

    age = 2021 - birthYear;

    printf("Please enter your lucky number: ");
    scanf("%d", &luckyNum);

    srand(time(NULL));

    num1 = rand() % 101;
    num2 = rand() % 101;
    num3 = rand() % 101;

    printf("\n%s, your lucky numbers are: %d, %d, %d\n", name, luckyNum, num1, num2);

    sum = luckyNum + num1 + num2;

    if (sum > age)
    {
        printf("You will have a long and prosperous life!\n");
    }
    else
    {
        printf("You should take care of your health!\n");
    }

    if (sum % 2 == 0)
    {
        printf("You are a balanced individual!\n");
    }
    else
    {
        printf("You may encounter some unexpected events!\n");
    }

    if ((num1 == num2) && (num2 == num3))
    {
        printf("You will have good luck in the near future!\n");
    }
    else
    {
        printf("You need to work harder to achieve your goals!\n");
    }

    return 0;
}