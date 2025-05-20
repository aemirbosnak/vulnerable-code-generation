//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between given limits
int generateRandomNumber(int lower, int upper)
{
    int num;
    srand(time(0)); // seed the random generator
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// Function to check if the guess is correct
int isGuessCorrect(int guess, int answer)
{
    if (guess == answer)
        return 1;
    else if (guess < answer)
        printf("Your guess is low. Try again!\n");
    else
        printf("Your guess is high. Try again!\n");
    return 0;
}

// Function to update the score and high score
void updateScore(int score, int *highScore)
{
    if (score > *highScore)
    {
        *highScore = score;
        printf("Congratulations! You have a new high score: %d\n\n", *highScore);
    }
    else
    {
        printf("Your score: %d\n\n", score);
    }
}

// Main game loop
void playGame()
{
    int lowerLimit = 1;
    int upperLimit = 100;
    int answer = generateRandomNumber(lowerLimit, upperLimit);
    int guess;
    int score = 0;
    int highScore = 0;

    printf("\nWelcome to the Guessing Game!\n");
    printf("You have to guess the number between %d and %d\n", lowerLimit, upperLimit);
    printf("You will earn points based on the number of tries it takes you to guess the correct answer.\n");
    printf("You can quit the game at any time by entering a negative number as your guess.\n\n");

    while (1)
    {
        printf("Guess the number: ");
        scanf("%d", &guess);
        if (guess < 0)
        {
            printf("Quitting the game...\n");
            break;
        }
        score++;
        if (isGuessCorrect(guess, answer))
        {
            printf("Congratulations! You guessed the correct answer in %d tries!\n", score);
            updateScore(score, &highScore);
            break;
        }
    }
}

// Main function
int main()
{
    char choice;

    printf("Welcome to the Awesome Terminal Based Game!\n\n");

    while (1)
    {
        printf("Press 'p' to play the game or 'q' to quit: ");
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q')
        {
            printf("Thank you for playing. Goodbye!\n");
            break;
        }
        else if (choice == 'p' || choice == 'P')
        {
            playGame();
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}