//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int board[ROWS][COLS] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
    int player_score = 0, computer_score = 0;
    int flag = 0;
    int choice;
    int i, j;

    srand(time(0));

    printf("Welcome to the Memory Game!\n\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 3 + 1;
        }
    }

    while (flag == 0) {
        system("clear");
        printf("Score: You - %d, Computer - %d\n", player_score, computer_score);
        printf("Board:\n");

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == 1)
                    printf("1");
                else if (board[i][j] == 2)
                    printf("2");
                else
                    printf("3");
            }
            printf("\n");
        }

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        i = choice - 1;
        j = 0;

        if (board[i][j]!= 0) {
            if (board[i][j] == board[i][j + 1]) {
                board[i][j] = 0;
                board[i][j + 1] = 0;
                player_score += 10;
            } else {
                board[i][j] = 0;
                board[i][j + 1] = 0;
                computer_score += 10;
            }
        } else {
            board[i][j] = 1;
            board[i][j + 1] = 1;
            computer_score += 10;
        }

        if (computer_score >= 80) {
            flag = 1;
            printf("\nComputer wins!\n");
        } else if (player_score >= 80) {
            flag = 1;
            printf("\nYou win!\n");
        }
    }

    return 0;
}