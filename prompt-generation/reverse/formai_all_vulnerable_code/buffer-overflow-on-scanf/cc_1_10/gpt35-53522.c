//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables
    int choice, count, num, score = 0, guess = -1, i;
    
    // Set random seed
    srand(time(NULL));
    
    // Display instructions
    printf("Welcome to the Memory Game! Here's how it works:\n");
    printf("1. You will be shown a sequence of random numbers.\n");
    printf("2. You will then need to enter the correct sequence.\n");
    printf("3. Each correct guess scores 1 point and the game ends after %d guesses.\n", count);
    printf("4. Good luck!\n\n");
    
    // Game loop
    for(count = 1; count <= 10; count++)
    {
        // Reset guess
        guess = -1;
        
        // Generate the sequence
        printf("Round %d:", count);
        for(i = 0; i < count; i++)
        {
            num = rand() % 10;
            printf(" %d", num);
        }
        printf("\n");
        
        // Get user's guess
        printf("Enter the sequence you saw: ");
        for(i = 0; i < count; i++)
        {
            scanf("%d", &choice);
            if(choice != num)
            {
                guess = i;
                break;
            }
        }
        
        // Update score
        if(guess == -1)
        {
            score++;
            printf("Correct! Your score is %d/%d.\n\n", score, count);
        }
        else
        {
            printf("Incorrect! The correct sequence was:");
            for(i = 0; i < count; i++)
            {
                printf(" %d", num);
            }
            printf("\n\n");
        }
    }
    
    // End of game
    printf("Game over! Your final score is %d/10. Thanks for playing!\n", score);
    return 0;
}