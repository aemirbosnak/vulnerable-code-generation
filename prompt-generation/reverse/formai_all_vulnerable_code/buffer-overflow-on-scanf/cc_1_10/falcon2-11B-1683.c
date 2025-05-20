//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int player1Score = 0;
    int player2Score = 0;
    int dice1 = 0;
    int dice2 = 0;
    int turn = 1;
    int totalScore = 0;
    
    while (1) {
        printf("Player %d's turn.\n", turn);
        printf("Enter your dice roll: ");
        scanf("%d %d", &dice1, &dice2);
        printf("Dice roll: %d %d\n", dice1, dice2);
        
        if (dice1 == 1 || dice2 == 1) {
            printf("Sorry, you have rolled snake eyes. Your turn ends.\n");
        } else {
            if (turn == 1) {
                if (dice1 + dice2 == 7) {
                    printf("You have rolled a 7! You win this round and score %d points.\n", 100);
                    player1Score += 100;
                } else {
                    printf("You have rolled %d %d. Your score is %d.\n", dice1, dice2, player1Score);
                }
            } else if (turn == 2) {
                if (dice1 + dice2 == 7) {
                    printf("You have rolled a 7! You win this round and score %d points.\n", 100);
                    player2Score += 100;
                } else {
                    printf("You have rolled %d %d. Your score is %d.\n", dice1, dice2, player2Score);
                }
            }
            
            totalScore += player1Score + player2Score;
            printf("Total score: %d\n", totalScore);
            
            if (totalScore >= 500) {
                printf("Congratulations! You have won the game with a total score of %d points.\n", totalScore);
                break;
            }
            
            printf("Enter your dice roll: ");
            scanf("%d %d", &dice1, &dice2);
            printf("Dice roll: %d %d\n", dice1, dice2);
            
            turn = (turn + 1) % 2;
        }
    }
    
    return 0;
}