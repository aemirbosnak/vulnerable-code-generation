//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the amazing game of Dice!\n");
    printf("Are you ready to play? (y/n): ");
    
    char response;
    scanf("%c", &response);
    
    if (response == 'y')
    {
        printf("Great! Let's get started. You will roll the dice and try to reach 20 points.\n");
        
        srand(time(NULL));
        int total = 0;
        
        while (total < 20)
        {
            int roll = rand() % 6 + 1;
            total += roll;
            
            printf("You rolled a %d, your total is now %d.\n", roll, total);
            
            if (total > 20)
            {
                printf("Oh no! You went over 20. You lose!\n");
                break;
            }
            
            if (total == 20)
            {
                printf("Congratulations! You reached 20 and won the game!\n");
                break;
            }
            
            printf("Do you want to roll again? (y/n): ");
            scanf(" %c", &response);
            
            if (response != 'y')
            {
                printf("Thanks for playing!\n");
                break;
            }
        }
    }
    
    else if (response == 'n')
    {
        printf("Oh, that's too bad. Maybe next time.\n");
    }
    
    else
    {
        printf("Sorry, I didn't understand your response. Please restart the program and try again.\n");
    }

    return 0;
}