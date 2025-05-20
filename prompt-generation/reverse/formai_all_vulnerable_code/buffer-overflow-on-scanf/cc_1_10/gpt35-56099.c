//FormAI DATASET v1.0 Category: Table Game ; Style: rigorous
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

int main() 
{ 
    // Variable initialization 
    int playerScore = 0, computerScore = 0, rollDice; 
    char choice; 
    
    // Seed the random number generator 
    srand(time(NULL)); 

    // Game loop 
    do 
    { 
        printf("\nPlayer's turn:\n"); 
        printf("Press 'r' to roll the dice: "); 
        scanf(" %c", &choice); 
        
        if(choice == 'r') 
        { 
            rollDice = (rand() % 6) + 1; 
            printf("You rolled a %d\n", rollDice); 
            
            if(rollDice == 1) 
            { 
                printf("You lose your turn and 1 point\n"); 
                playerScore--; 
            } 
            else 
            { 
                playerScore += rollDice; 
            } 
        }
    
        printf("\nPlayer's score: %d\n", playerScore); 
        
        // Computer's turn 
        printf("\nComputer's turn:\n"); 
        
        rollDice = (rand() % 6) + 1; 
        printf("Computer rolled a %d\n", rollDice); 
        
        if(rollDice == 1) 
        { 
            printf("Computer loses its turn and 1 point\n"); 
            computerScore--; 
        } 
        else 
        { 
            computerScore += rollDice; 
        } 
        
        printf("\nComputer's score: %d\n", computerScore); 
        
    } while(playerScore < 100 && computerScore < 100);
    
    // Game over 
    printf("\n\nGAME OVER!\n"); 
    printf("Player's final score: %d\n", playerScore); 
    printf("Computer's final score: %d\n", computerScore); 
    
    if(playerScore > computerScore) 
    { 
        printf("Congratulations, you win!\n"); 
    } 
    else 
    { 
        printf("Sorry, the computer wins.\nBetter luck next time.\n"); 
    } 
    
    return 0; 
}