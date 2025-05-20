//FormAI DATASET v1.0 Category: Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 5

int main()
{
    srand(time(NULL));
    int number = rand() % 100 + 1;
    int guess;
    int tries = 0;
    char play_again;
    
    do
    {
        printf("Guess a number between 1 and 100\n");
        while(tries < MAX_TRIES)
        {
            scanf("%d", &guess);
            tries++;
            
            if(guess == number)
            {
                printf("Congratulations! You guessed the number in %d tries!\n", tries);
                break;
            }
            else if(guess < number)
            {
                printf("Too low! Guess again.\n");
            }
            else
            {
                printf("Too high! Guess again.\n");
            }
        }
        
        if(tries == MAX_TRIES)
        {
            printf("Sorry, you could not guess the number. The number was %d.\n", number);
        }
        
        printf("Would you like to play again? (y/n)\n");
        scanf(" %c", &play_again);
        
        if(play_again == 'y')
        {
            number = rand() % 100 + 1;
            tries = 0;
        }
    } while(play_again == 'y');
    
    printf("Thank you for playing!\n");
    
    return 0;
}