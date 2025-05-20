//Falcon-180B DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1_score = 0, player2_score = 0;
    int player1_turn = 1, player2_turn = 0;
    char player1_name[20], player2_name[20];
    int choice;

    //Player 1 Name
    printf("Enter Player 1 Name: ");
    scanf("%s", player1_name);

    //Player 2 Name
    printf("Enter Player 2 Name: ");
    scanf("%s", player2_name);

    int dice;
    srand(time(0));
    dice = rand() % 6 + 1;

    while(player1_score < 20 && player2_score < 20) {
        if(player1_turn) {
            printf("%s's turn. Enter your choice:\n1. Roll the dice\n2. Pass the turn\n", player1_name);
            scanf("%d", &choice);

            if(choice == 1) {
                printf("%s rolled the dice and got %d.\n", player1_name, dice);
                player1_score += dice;
            } else {
                player1_turn = 0;
            }
        } else {
            printf("%s's turn. Enter your choice:\n1. Roll the dice\n2. Pass the turn\n", player2_name);
            scanf("%d", &choice);

            if(choice == 1) {
                printf("%s rolled the dice and got %d.\n", player2_name, dice);
                player2_score += dice;
            } else {
                player2_turn = 1;
            }
        }
    }

    if(player1_score >= 20) {
        printf("%s wins the game!\n", player1_name);
    } else {
        printf("%s wins the game!\n", player2_name);
    }

    return 0;
}