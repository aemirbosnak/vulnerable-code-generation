//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

int main(void) {
    int board[ROWS][COLS] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int player_score = 0, computer_score = 0;
    int turn = 0;
    char choice;
    int row, col;
    srand(time(NULL));

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    while (player_score!= 5 && computer_score!= 5) {
        if (turn % 2 == 0) {
            printf("Player's turn.\n");
            printf("Score: Player - %d, Computer - %d\n", player_score, computer_score);
            printf("Board:\n");
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%d ", board[i][j]);
                }
                printf("\n");
            }
            printf("Enter your choice (row and column): ");
            scanf("%d%c", &row, &choice);
            col = choice - 'A';

            if (board[row][col] == 1) {
                printf("Correct!\n");
                player_score++;
            } else {
                printf("Incorrect!\n");
                computer_score++;
            }
        } else {
            printf("Computer's turn.\n");
            int comp_choice;
            do {
                comp_choice = rand() % 6;
            } while (board[comp_choice / 3][comp_choice % 3]!= 1);

            row = comp_choice / 3;
            col = comp_choice % 3;

            if (board[row][col] == 1) {
                printf("Computer chose correctly!\n");
                computer_score++;
            } else {
                printf("Computer chose incorrectly!\n");
                player_score++;
            }
        }
        turn++;
    }

    if (player_score == 5) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, you lost.\n");
    }

    return 0;
}