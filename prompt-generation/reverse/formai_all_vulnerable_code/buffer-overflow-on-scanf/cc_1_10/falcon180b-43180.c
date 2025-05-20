//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0;
    int choice;
    int flag = 0;
    int i;

    srand(time(0));

    while(1) {
        system("clear");
        printf("\n\n\t\tWELCOME TO THE GAME OF CHANCE\n\n");
        printf("\t\tYou will roll a dice and the computer will also roll a dice.\n");
        printf("\t\tIf your score is greater than or equal to the computer's score, you win.\n");
        printf("\t\tIf your score is less than the computer's score, you lose.\n\n");

        printf("\t\tPress 1 to roll the dice\n");
        printf("\t\tPress 0 to quit\n\n");
        scanf("%d", &choice);

        if(choice == 0) {
            break;
        }

        for(i=0;i<2;i++) {
            int dice1 = rand() % 6 + 1;
            int dice2 = rand() % 6 + 1;

            if(i == 0) {
                printf("\t\tYou rolled a %d\n", dice1);
                playerScore += dice1;
            }
            else {
                printf("\t\tThe computer rolled a %d\n", dice2);
                computerScore += dice2;
            }

            if(playerScore >= 7 || computerScore >= 7) {
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            break;
        }
    }

    if(playerScore > computerScore) {
        printf("\n\t\tYou won!\n");
    }
    else if(playerScore < computerScore) {
        printf("\n\t\tYou lost!\n");
    }
    else {
        printf("\n\t\tIt's a tie!\n");
    }

    return 0;
}