//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player1Score = 0;
    int player2Score = 0;
    int round = 1;
    printf("***Let's Play a Game!***\n\n");
    printf("Player 1, Enter your name >> ");
    char player1Name[20];
    scanf("%s", player1Name);
    printf("\nPlayer 2, Enter your name >> ");
    char player2Name[20];
    scanf("%s", player2Name);
    printf("\nWelcome, %s and %s!\n", player1Name, player2Name);

    while (player1Score < 10 && player2Score < 10) {
        printf("\n*****ROUND %d*****\n\n", round);
        int player1Roll = rand() % 6 + 1;
        int player2Roll = rand() % 6 + 1;
        printf("%s rolled a %d\n", player1Name, player1Roll);
        printf("%s rolled a %d\n", player2Name, player2Roll);

        if (player1Roll > player2Roll) {
            player1Score++;
            printf("%s wins the round!\n", player1Name);
        } else if (player2Roll > player1Roll) {
            player2Score++;
            printf("%s wins the round!\n", player2Name);
        } else {
            printf("It's a tie!\n");
        }
        round++;
    }

    if (player1Score == 10) {
        printf("\n%s Wins the Game!!!\n", player1Name);
        printf("%s Score: %d\n", player1Name, player1Score);
        printf("%s Score: %d\n", player2Name, player2Score);
    } else if (player2Score == 10) {
        printf("\n%s Wins the Game!!!\n", player2Name);
        printf("%s Score: %d\n", player1Name, player1Score);
        printf("%s Score: %d\n", player2Name, player2Score);
    } else {
        printf("There was an error determining the winner :(\n");
    }
    return 0;
}