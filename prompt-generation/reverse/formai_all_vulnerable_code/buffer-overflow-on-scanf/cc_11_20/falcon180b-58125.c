//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int player_num, num_dice, dice_face, i, j, sum;
    char play_again;

    srand(time(NULL));

    printf("\nWelcome to the Dice Roller Game!\n");

    while(1) {
        printf("\nEnter the number of players (1-4): ");
        scanf("%d", &player_num);

        if(player_num < 1 || player_num > 4) {
            printf("\nInvalid number of players! Please try again.\n");
            continue;
        }

        printf("\nEnter the number of dice per player (1-6): ");
        scanf("%d", &num_dice);

        if(num_dice < 1 || num_dice > 6) {
            printf("\nInvalid number of dice! Please try again.\n");
            continue;
        }

        printf("\nEnter the number of faces on the dice (1-100): ");
        scanf("%d", &dice_face);

        if(dice_face < 1 || dice_face > 100) {
            printf("\nInvalid number of faces on the dice! Please try again.\n");
            continue;
        }

        int player_score[player_num];
        for(i=0; i<player_num; i++) {
            player_score[i] = 0;
        }

        for(i=0; i<num_dice; i++) {
            for(j=0; j<player_num; j++) {
                sum = rand() % dice_face + 1;
                player_score[j] += sum;
                printf("\nPlayer %d rolled a %d on dice %d.", j+1, sum, i+1);
            }
        }

        printf("\n\nPlayer Scores:\n");
        for(i=0; i<player_num; i++) {
            printf("\nPlayer %d: %d", i+1, player_score[i]);
        }

        printf("\n\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);

        if(play_again == 'n' || play_again == 'N') {
            break;
        }
    }

    return 0;
}