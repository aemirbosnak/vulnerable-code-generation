//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roll;
    srand(time(NULL));
    printf("Welcome to the Romantic Dice Roller!\n");
    printf("In this game, you and your partner will take turns rolling a dice.\n");
    printf("The first one to reach 10 points wins a romantic surprise!\n");
    printf("Press any key to begin...\n");
    getchar();

    int player1Score = 0;
    int player2Score = 0;
    char player1Name[20];
    char player2Name[20];

    printf("Enter your name: ");
    scanf("%s", player1Name);
    printf("Enter your partner's name: ");
    scanf("%s", player2Name);

    while (player1Score < 10 && player2Score < 10) {
        printf("\n%s, it's your turn! Press any key to roll the dice...\n", player1Name);
        getchar();
        roll = rand() % 6 + 1;
        printf("%s rolled a %d!\n", player1Name, roll);

        if (roll == 6) {
            printf("%s got a kiss! %s now has %d points.\n", player1Name, player1Name, ++player1Score);
        } else if (roll == 5) {
            printf("%s got a hug! %s now has %d points.\n", player1Name, player1Name, ++player1Score);
        } else if (roll >= 3) {
            printf("%s got a point! %s now has %d points.\n", player1Name, player1Name, ++player1Score);
        } else {
            printf("%s lost a point... Better luck next time!\n", player1Name);
        }

        printf("\n%s, it's your turn! Press any key to roll the dice...\n", player2Name);
        getchar();
        roll = rand() % 6 + 1;
        printf("%s rolled a %d!\n", player2Name, roll);

        if (roll == 6) {
            printf("%s got a kiss! %s now has %d points.\n", player2Name, player2Name, ++player2Score);
        } else if (roll == 5) {
            printf("%s got a hug! %s now has %d points.\n", player2Name, player2Name, ++player2Score);
        } else if (roll >= 3) {
            printf("%s got a point! %s now has %d points.\n", player2Name, player2Name, ++player2Score);
        } else {
            printf("%s lost a point... Better luck next time!\n", player2Name);
        }
    }

    if (player1Score == 10) {
        printf("\n%s wins! Congratulations, you've reached 10 points first!\n", player1Name);
    } else {
        printf("\n%s wins! Congratulations, you've reached 10 points first!\n", player2Name);
    }

    return 0;
}