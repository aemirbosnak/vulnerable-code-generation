//Falcon-180B DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_VALUE 100

int main() {
    int grid[SIZE][SIZE];
    int player_score = 0;
    int computer_score = 0;
    int current_player = 1;
    int valid_move = 0;

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % MAX_VALUE + 1;
        }
    }

    while (current_player <= 2) {
        system("clear");
        printf("Player 1: %d\n", player_score);
        printf("Player 2: %d\n", computer_score);
        printf("\n");

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }

        valid_move = 0;

        while (!valid_move) {
            int row, col;
            printf("Enter your move (row and column): ");
            scanf("%d %d", &row, &col);

            if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && grid[row][col] > 0) {
                grid[row][col] = 0;
                player_score += grid[row][col];
                valid_move = 1;
            } else {
                printf("Invalid move.\n");
            }
        }

        current_player++;

        if (current_player == 2) {
            int max_value = 0;
            int best_row, best_col;

            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (grid[i][j] > max_value) {
                        max_value = grid[i][j];
                        best_row = i;
                        best_col = j;
                    }
                }
            }

            grid[best_row][best_col] = 0;
            computer_score += max_value;
        }
    }

    if (player_score > computer_score) {
        printf("Player 1 wins!\n");
    } else if (computer_score > player_score) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}