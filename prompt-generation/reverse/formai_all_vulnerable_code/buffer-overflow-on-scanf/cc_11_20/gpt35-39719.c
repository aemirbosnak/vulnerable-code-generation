//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice1, dice2, sum, bet;
    char choice;
    srand(time(NULL));
    
    printf("\nWelcome to the C Table Game!\n");
    printf("Each round costs 10 points to play.\n");
    
    do {
        printf("\nPress any key to roll the dice!\n");
        getchar();
        
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        sum = dice1 + dice2;
        
        printf("\nYou rolled a %d and a %d for a total of %d.\n", dice1, dice2, sum);
        printf("Enter your bet (minimum 10 points): ");
        scanf("%d", &bet);
        
        while (bet < 10) {
            printf("Invalid bet. Please enter a minimum of 10 points: ");
            scanf("%d", &bet);
        }
        
        if (bet > 100) {
            printf("You cannot bet more than 100 points.\n");
            bet = 100;
        }
        
        if (sum == 7 || sum == 11) {
            printf("Congratulations! You win %d points!\n", bet);
        } else if (sum == 2 || sum == 3 || sum == 12) {
            printf("Sorry, you lose %d points.\n", bet);
            bet *= -1;
        } else {
            printf("Roll again! You must roll another %d to win.\n", sum);
            getchar();
            
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            sum = dice1 + dice2;
            
            printf("\nYou rolled a %d and a %d for a total of %d.\n", dice1, dice2, sum);
            
            if (sum == 7) {
                printf("Sorry, you lose %d points.\n", bet);
                bet *= -1;
            } else if (sum == sum) {
                printf("Congratulations! You win %d points!\n", bet);
            } else {
                printf("Sorry, you lose %d points.\n", bet);
                bet *= -1;
            }
        }
        
        printf("\nWould you like to play again? (y/n): ");
        getchar();
        scanf("%c", &choice);
        
        while (choice != 'y' && choice != 'n') {
            printf("Invalid choice. Please enter 'y' or 'n': ");
            getchar();
            scanf("%c", &choice);
        }
        
    } while (choice == 'y');
    
    printf("\nThanks for playing the C Table Game!\n");
    
    return 0;
}