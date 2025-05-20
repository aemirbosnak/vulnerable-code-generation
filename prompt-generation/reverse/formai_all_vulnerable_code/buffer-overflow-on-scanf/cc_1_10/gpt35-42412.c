//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int answer=0;
    int guess=0;
    int count=0;
    char choice;
    
    srand((unsigned int)time(0));
    answer = rand()%100+1; // Generate random number between 1 to 100
    
    printf("Welcome to Guess a Number!\n\n");
    
    do
    {
        printf("Please guess a number between 1 and 100: ");
        scanf("%d", &guess);
        count++; // Keep track of number of guesses
        
        if(guess < answer)
        {
            printf("\nYour guess is too low.\n");
        }
        else if(guess > answer)
        {
            printf("\nYour guess is too high.\n");
        }
        else
        {
            printf("\nCongratulations! You guessed the correct number in %d tries.\n", count);
            
            printf("\nWould you like to play again? (y/n): ");
            scanf(" %c", &choice); // Need to add space before %c to clear input buffer
            
            if(choice == 'y' || choice == 'Y')
            {
                answer = rand()%100+1;
                count=0;
                printf("\n\nNew game started!\n\n");
                continue; // Restart the game
            }
            else
            {
                printf("Thank you for playing!\n");
                break; // Exit the game
            }
        }
    }while(1); // Infinite loop
    
    return 0;
}