//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void play_again(int score)
{
    printf("Congratulations! You scored %d points!\n", score);
    printf("Would you like to play again? (Y/N): ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for playing!\n");
    }
}

int main()
{
    int score = 0;
    char guess;

    printf("Welcome to the Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 10. Can you guess what it is? ");

    // Loop until the user guesses the number or gives up
    while (score < 10)
    {
        scanf(" %c", &guess);

        if (guess == 'H')
        {
            score++;
            printf("Your guess is too high. Try again.\n");
        }
        else if (guess == 'L')
        {
            score++;
            printf("Your guess is too low. Try again.\n");
        }
        else if (guess == 'A')
        {
            score = 10;
            printf("Congratulations! You guessed the number!\n");
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    play_again(score);

    return 0;
}