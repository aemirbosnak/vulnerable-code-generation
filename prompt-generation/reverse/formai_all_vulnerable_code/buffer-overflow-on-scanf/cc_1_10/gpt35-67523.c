//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int players;
    printf("Welcome to Guess the Number game!\n\n");
    printf("Please enter the number of players: ");
    scanf("%d", &players);
    
    while(players < 1 || players > 10)
    {
        printf("Invalid number of players. Please enter a number between 1 and 10: ");
        scanf("%d", &players);
    }
    
    int guess, answer, attempts = 0, min, max;
    srand(time(NULL));
    answer = rand() % 100 + 1;
    
    printf("\nGuess a number between 1 and 100.\n");
    
    if(players > 1)
    {
        printf("\nThe number of attempts will be divided between the players.\n");
        printf("Please enter the minimum and maximum number of attempts for each player: ");
        scanf("%d %d", &min, &max);
    }
    
    for(int i = 1; i <= players; i++)
    {
        attempts = 0;
        printf("\nPlayer %d's turn.\n", i);
        
        while(guess != answer)
        {
            attempts++;
            
            if(players == 1 || attempts <= max)
            {
                printf("Attempt %d: ", attempts);
                scanf("%d", &guess);
                
                if(guess > answer)
                {
                    printf("Too high! Guess again.\n");
                }
                else if(guess < answer)
                {
                    printf("Too low! Guess again.\n");
                }
                else
                {
                    printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
                }
            }
            else
            {
                printf("\nNo more attempts remaining. The number was %d. Better luck next time!\n", answer);
                break;
            }
        }
    }
    
    printf("\nThank you for playing Guess the Number game!\n");
    
    return 0;
}