//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, num3, sum, guess, luck_num;
    char letter, again;

    printf("Prepare for a shock, my dear...!\n");

    // Generating random numbers
    num1 = rand() % 11;
    num2 = rand() % 11;
    num3 = rand() % 11;

    // Calculating the sum of the numbers
    sum = num1 + num2 + num3;

    // Guessing the sum
    printf("Enter your guess:");
    scanf("%d", &guess);

    // Checking if the guess is correct
    if (guess == sum)
    {
        printf("You've won! The sum is %d.\n", sum);
    }
    else
    {
        printf("Sorry, your guess is incorrect. The sum is %d.\n", sum);
    }

    // Determining luck number
    luck_num = rand() % 3;

    // Giving lucky number
    printf("Your lucky number is: %d.\n", luck_num);

    // Asking for another guess
    printf("Do you want to guess again? (Y/N): ");
    scanf(" %c", &again);

    // Checking if the user wants to guess again
    if (again == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for playing. Come back soon!\n");
    }

    return 0;
}