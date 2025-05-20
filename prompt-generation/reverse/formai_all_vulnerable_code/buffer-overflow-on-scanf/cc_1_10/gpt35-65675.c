//FormAI DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player1 = 0, player2 = 0;
    int dice;
    char choice;
    
    printf("\t\tWELCOME TO THE C TABLE GAME\n\n");
    
    srand(time(NULL)); //initialize random seed
    
    do {
        printf("Player 1, Press any key to roll the dice: ");
        getchar();
        dice = rand() % 6 + 1; //generate random number between 1-6
        printf("You have rolled a %d\n", dice);
        player1 += dice; //add dice to player 1's score
        
        printf("Player 1, Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        
        while (choice != 'y' && choice != 'n') { //validate input
            printf("Invalid Choice! Please enter 'y' or 'n': ");
            scanf(" %c", &choice);
        }
        
        if (choice == 'y') {
            printf("Player 1 rolled again!\n");
            printf("Player 1's score is now: %d\n", player1);
        }
        
        printf("\n");
        
        if (player1 >= 50) {
            printf("Congratulations! Player 1 has won!\n");
            break;
        }
        
        printf("Player 2, Press any key to roll the dice: ");
        getchar();
        dice = rand() % 6 + 1;
        printf("You have rolled a %d\n", dice);
        player2 += dice;
        
        printf("Player 2, Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
        
        while (choice != 'y' && choice != 'n') {
            printf("Invalid Choice! Please enter 'y' or 'n': ");
            scanf(" %c", &choice);
        }
        
        if (choice == 'y') {
            printf("Player 2 rolled again!\n");
            printf("Player 2's score is now: %d\n", player2);
        }
        
        printf("\n");
        
        if (player2 >= 50) {
            printf("Congratulations! Player 2 has won!\n");
            break;
        }
    } while (1); //infinite loop until a winner is declared
    
    printf("\nGAME OVER!\n");
    
    return 0;
}