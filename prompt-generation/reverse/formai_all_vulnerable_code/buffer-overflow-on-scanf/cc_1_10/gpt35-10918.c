//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerScore = 0; //initialize player score
    int computerScore = 0; //initialize computer score
    int playerChoice; //initialize player's choice
    char playAgain; //initialize play again variable
    
    srand(time(NULL)); //initialize random seed
    
    printf("Welcome to the C Table Game!\n");
    
    do{
        printf("Player Score: %d | Computer Score: %d\n", playerScore, computerScore);
        
        printf("Please choose a number between 1 and 5: ");
        scanf("%d", &playerChoice); //get user input
        
        int computerChoice = rand() % 5 + 1; //generate random number for computer's choice
        
        printf("Computer chose %d.\n", computerChoice);
        
        int combinedScore = playerChoice + computerChoice; //calculate combined score
        
        if (combinedScore % 2 == 0){ //if sum is even
            printf("%d is even!\n", combinedScore);
            if (playerChoice > computerChoice){ //player wins
                printf("You win!\n");
                playerScore++; //increment player score
            }
            else if (computerChoice > playerChoice){ //computer wins
                printf("Computer wins!\n");
                computerScore++; //increment computer score
            }
            else{ //tie
                printf("It's a tie!\n");
            }
        }
        else{ //if sum is odd
            printf("%d is odd!\n", combinedScore);
            if (playerChoice < computerChoice){ //player wins
                printf("You win!\n");
                playerScore++; //increment player score
            }
            else if (computerChoice < playerChoice){ //computer wins
                printf("Computer wins!\n");
                computerScore++; //increment computer score
            }
            else{ //tie
                printf("It's a tie!\n");
            }
        }
        
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &playAgain); //get user input for play again choice
        
    }while (playAgain == 'y'); //play again if user chooses 'y'
    
    printf("Final Score: Player: %d | Computer: %d\n", playerScore, computerScore); //output final score
    
    return 0;
}