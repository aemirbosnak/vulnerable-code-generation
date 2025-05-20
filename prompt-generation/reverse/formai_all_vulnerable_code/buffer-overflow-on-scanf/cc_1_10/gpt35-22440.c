//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>
#include <stdlib.h>

/* This program generates random numbers and tells you if they are "lucky" numbers or not. */

int main()
{
    int num, sum = 0, rem;

    printf("I'm feeling lucky today! Give me a number and I'll tell you if it's a lucky number: ");
    scanf("%d", &num);

    while(num > 0 || sum > 9)
    {
        if(num == 0)
        {
            num = sum;
            sum = 0;
        }

        rem = num % 10;
        sum += rem;
        num /= 10;
    }

    if(sum == 7)
        printf("Congratulations! %d is a lucky number!\n", num);
    else
        printf("Sorry, %d is not a lucky number. Better luck next time!\n", num);

    printf("Let's generate some more lucky numbers! How many do you want?\n");
    int n;
    scanf("%d", &n);

    printf("Here are your lucky numbers:\n");

    for(int i = 1; i <= n; i++)
    {
        int randomNum = rand() % 100;
        int tempSum = 0;
        int tempNum = randomNum;

        while(tempNum > 0 || tempSum > 9)
        {
            if(tempNum == 0)
            {
                tempNum = tempSum;
                tempSum = 0;
            }

            rem = tempNum % 10;
            tempSum += rem;
            tempNum /= 10;
        }

        if(tempSum == 7)
            printf("%d - It's your lucky day!\n", randomNum);
        else
            printf("%d - Better luck next time!\n", randomNum);
    }

    printf("Thanks for playing!\n");

    return 0;
}