//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and max_number
int generate_number(int max_number)
{
    srand(time(NULL));
    return rand() % max_number + 1;
}

int main()
{
    int highscore = 0; // Variable to keep track of the highest score achieved
    char name[20]; // Variable to store the player's name
    int score = 0; // Variable to keep track of the player's score
    int guess; // Variable to store the player's guess
    int number_of_guesses = 0; // Variable to keep track of the number of guesses made
    int max_number = 100; // Maximum number that the player has to guess
    int play_again = 1; // Variable to keep track of whether the player wants to play again or not

    printf("Welcome to Guess the Number!\n\n");
    printf("What is your name?\n");
    scanf("%s", name);

    printf("\nHi %s! Here are the rules:\n", name);
    printf("1. I am thinking of a number between 1 and %d.\n", max_number);
    printf("2. You have to guess the number within 10 guesses.\n");
    printf("3. Each time you guess, I will tell you whether the number is higher or lower than your guess.\n");
    printf("4. If you guess the number within 10 guesses, you win!\n");
    printf("5. Your highscore will be kept track of and displayed at the end of each game.\n");
    printf("6. Have fun!\n\n");

    // Main game loop
    while (play_again == 1)
    {
        int number_to_guess = generate_number(max_number);

        printf("I am thinking of a number between 1 and %d. Can you guess what it is?\n", max_number);

        // Reset game variables
        score = 0;
        number_of_guesses = 0;

        // Guessing loop
        while (number_of_guesses < 10)
        {
            printf("Guess #%d: ", number_of_guesses+1);
            scanf("%d", &guess);

            if (guess == number_to_guess)
            {
                printf("Congratulations! You guessed the number in %d guesses.\n", number_of_guesses+1);

                score = 10 - number_of_guesses;

                if (score > highscore)
                {
                    highscore = score;
                    printf("New highscore! Your score is now %d.\n", score);
                }
                else
                {
                    printf("Your score is %d.\n", score);
                }

                break;
            }
            else if (guess < number_to_guess)
            {
                printf("Wrong! The number is higher than %d.\n", guess);
            }
            else
            {
                printf("Wrong! The number is lower than %d.\n", guess);
            }

            number_of_guesses++;
        }

        if (number_of_guesses == 10)
        {
            printf("\nSorry, you did not guess the number in time. The number was %d.\n", number_to_guess);
        }

        printf("\nYour highscore is %d.\n", highscore);

        // Play again loop
        printf("\nDo you want to play again?\n");
        printf("1. Yes\n");
        printf("2. No\n");

        scanf("%d", &play_again);

        while(play_again != 1 && play_again != 2)
        {
            printf("\nInvalid input. Please enter 1 or 2.\n");
            scanf("%d", &play_again);
        }

        if (play_again == 2)
        {
            printf("\nThanks for playing, %s!\n", name);
        }
    }

    return 0;
}