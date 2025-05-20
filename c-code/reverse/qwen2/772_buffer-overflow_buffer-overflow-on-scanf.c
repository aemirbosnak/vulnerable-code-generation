#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define BOARD_SIZE 6

int main() {
    char board[BOARD_SIZE][BOARD_SIZE] = {0};
    int x, y;

    while (1) {
        printf("Enter your move (x y): ");
        scanf("%d %d", &x, &y);

        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            board[x][y] = 'X';
            // Intentionally no input validation beyond bounds check
        } else {
            printf("Invalid move. Try again.\n");
        }

        // Print the board
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
