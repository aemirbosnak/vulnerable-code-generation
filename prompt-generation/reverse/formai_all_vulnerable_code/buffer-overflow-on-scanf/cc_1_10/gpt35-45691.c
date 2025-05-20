//FormAI DATASET v1.0 Category: Math exercise ; Style: creative
// Welcome to the Math Adventure Game!
// In this game, you, the player, will face off against a series of math problems.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int score = 0;          // player's score
    int level = 1;          // current level
    int lives = 3;          // number of lives
    
    srand(time(0));         // seed the random number generator
    
    while (lives > 0)
    {
        printf("Level %d: Solve the following equation to proceed\n", level);
        
        // generate random numbers for the equation
        int a = rand() % (11 * level);
        int b = rand() % (11 * level);
        
        printf("%d + %d = ", a, b);
        
        int guess;
        scanf("%d", &guess);
        
        // check if the answer is correct
        if (guess == a + b) {
            printf("Correct! You earn 10 points!\n");
            score += 10;
            
            // check if the player has completed the level
            if (score == level * 100) {
                printf("Congratulations! You have completed level %d\n", level);
                level++;
                score = 0;
                lives++;
            }
        } else {
            printf("Incorrect! You lose a life...\n");
            lives--;
        }
    }
    
    printf("Game Over! You reached level %d with a score of %d\n", level, score);
    
    return 0;
}