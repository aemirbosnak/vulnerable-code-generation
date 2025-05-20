//FormAI DATASET v1.0 Category: Game ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char player1[20], player2[20];
    int score1=0, score2=0;
    printf("Welcome to the Love Game!\n\n");
    printf("Player 1, please enter your name: ");
    scanf("%s", player1);
    printf("Player 2, please enter your name: ");
    scanf("%s", player2);
    printf("\n%s and %s, may your love story blossom with this game!\n", player1, player2);
    printf("--------------------------------------------------\n");

    //gameplay
    int round = 1;
    while(round <= 5) {
        printf("\nRound %d\n", round);
        printf("------------\n");
        printf("%s, enter a number from 1 to 10: ", player1);
        int guess1;
        scanf("%d", &guess1);
        printf("%s, enter a number from 1 to 10: ", player2);
        int guess2;
        scanf("%d", &guess2);

        if(guess1 == guess2) {
            printf("Wow, both of you thought alike!\n");
        } else if(guess1 > guess2) {
            printf("%s wins this round!\n", player1);
            score1++;
        } else {
            printf("%s wins this round!\n", player2);
            score2++;
        }
        round++;
    }
    printf("\nResults\n-----------\n");
    printf("%s: %d\n", player1, score1);
    printf("%s: %d\n", player2, score2);

    if(score1 == score2) {
        printf("\nIt's a tie!\nYou really belong to each other!\n");
    } else if(score1 > score2) {
        printf("\n%s wins the Love Game!\n%s, do something special for %s today!\n", player1, player2, player1);
    } else {
        printf("\n%s wins the Love Game!\n%s, do something special for %s today!\n", player2, player1, player2);
    }
    printf("\nLove is in the air!\n");
    return 0;
}