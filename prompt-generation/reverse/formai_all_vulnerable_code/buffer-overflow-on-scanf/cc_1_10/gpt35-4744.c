//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>

int main()
{
    int level, difficulty, score = 0, guess, secretNumber, attempts;
    
    printf("Welcome to the Guess My Secret Number game!\n\n");
    
    printf("Please select the game level:\n1) Easy\n2) Medium\n3) Hard\n");
    scanf("%d", &level);
    
    switch(level)
    {
        case 1:
            difficulty = 10;
            attempts = 5;
            break;
        case 2:
            difficulty = 50;
            attempts = 10;
            break;
        case 3:
            difficulty = 100;
            attempts = 15;
            break;
        default:
            printf("Invalid selection. Please try again.");
            return 0;
    }
    
    secretNumber = rand() % difficulty + 1;
    
    printf("\nYou have %d attempts to guess my secret number between 1 and %d.\n\n", attempts, difficulty);
    
    while(score < attempts)
    {
        printf("You have %d attempts left.\nEnter your guess: ", attempts - score);
        scanf("%d", &guess);
        
        if(guess == secretNumber)
        {
            printf("\nCongratulations! You guessed my secret number %d and earned %d points.\n", secretNumber, difficulty * attempts / (score + 1));
            return 0;
        }
        else if(guess < secretNumber)
        {
            printf("Your guess is too low. Try again.\n\n");
        }
        else
        {
            printf("Your guess is too high. Try again.\n\n");
        }
        score++;
    }
    
    printf("\nGame over! You did not guess my secret number %d.\n", secretNumber);
    
    return 0;
}