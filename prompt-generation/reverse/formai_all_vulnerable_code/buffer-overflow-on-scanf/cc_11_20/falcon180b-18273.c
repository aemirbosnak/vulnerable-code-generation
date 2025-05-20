//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main() {
    int board[ROWS][COLS];
    int player_score = 0;
    int computer_score = 0;
    int current_player = 1;
    int choice;
    int flag = 0;
    int i, j;

    srand(time(0));

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }

    do {
        system("clear");
        printf("Player 1 Score: %d\n", player_score);
        printf("Computer Score: %d\n", computer_score);
        printf("Current Player: %d\n", current_player);
        printf("\n");

        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == 1) {
                    printf("O ");
                } else {
                    printf("X ");
                }
            }
            printf("\n");
        }

        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Invalid choice!\n");
            continue;
        }

        i = (choice - 1) / COLS;
        j = (choice - 1) % COLS;

        if (board[i][j]!= 0) {
            printf("Invalid choice!\n");
            continue;
        }

        if (current_player == 1) {
            board[i][j] = 1;
            player_score++;
        } else {
            board[i][j] = 2;
            computer_score++;
        }

        flag = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (board[i][j] == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }

        if (flag == 0) {
            printf("Game Over!\n");
            printf("Player 1 Score: %d\n", player_score);
            printf("Computer Score: %d\n", computer_score);

            if (player_score > computer_score) {
                printf("Player 1 wins!\n");
            } else if (computer_score > player_score) {
                printf("Computer wins!\n");
            } else {
                printf("Tie game!\n");
            }

            break;
        }

        current_player = (current_player % 2) + 1;

    } while (1);

    return 0;
}