//FormAI DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int c_table[5][5], i, j, row, col;
    char player1[20], player2[20];
    int player1_score = 0, player2_score = 0;
    srand(time(NULL));

    printf("Welcome to the C Table Game!\n");
    printf("Please enter the name of Player 1: ");
    scanf("%s", player1);
    printf("Please enter the name of Player 2: ");
    scanf("%s", player2);

    // Initialize the C Table
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            c_table[i][j] = rand() % 5 + 1;
            printf("%d ", c_table[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("%s, please select a row: ", player1);
    scanf("%d", &row);
    printf("%s, please select a column: ", player1);
    scanf("%d", &col);
    player1_score = c_table[row][col];

    printf("%s's score: %d\n\n", player1, player1_score);

    printf("%s, please select a row: ", player2);
    scanf("%d", &row);
    printf("%s, please select a column: ", player2);
    scanf("%d", &col);
    player2_score = c_table[row][col];

    printf("%s's score: %d\n\n", player2, player2_score);

    if(player1_score > player2_score) {
        printf("%s wins!\n", player1);
    }
    else if(player1_score < player2_score) {
        printf("%s wins!\n", player2);
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}