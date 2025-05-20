//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, r, i, guess, luck_num;
    char answer, yes_no;
    time_t t;

    // Generate random number between 1-10
    srand(time(NULL));
    r = rand() % 10 + 1;

    // Display a welcome message
    printf("Welcome to the Crystal Ball, my dear user!\n");

    // Ask the user to guess a number
    printf("Please guess a number between 1 and 10: ");
    scanf("%d", &guess);

    // Check if the user's guess is correct
    if (guess == r)
    {
        printf("Congratulations! You have guessed the number!\n");
    }
    else
    {
        printf("Sorry, your guess is incorrect. The number was %d.\n", r);
    }

    // Ask the user if they want to play again
    printf("Do you want to play again? (Y/N): ");
    scanf(" %c", &yes_no);

    // If the user wants to play again, generate a new random number and repeat the above steps
    if (yes_no == 'Y')
    {
        r = rand() % 10 + 1;
        guess = 0;
        printf("Please guess a number between 1 and 10: ");
        scanf("%d", &guess);
        if (guess == r)
        {
            printf("Congratulations! You have guessed the number!\n");
        }
        else
        {
            printf("Sorry, your guess is incorrect. The number was %d.\n", r);
        }
    }

    // Display a goodbye message
    printf("Thank you for playing, my dear user. Until next time!\n");

    return 0;
}