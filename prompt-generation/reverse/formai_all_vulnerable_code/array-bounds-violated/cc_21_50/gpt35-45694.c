//FormAI DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>

#define BOARD_SIZE 8

typedef enum {
    EMPTY,
    RED,
    BLACK
} piece_t;

typedef struct {
    piece_t board[BOARD_SIZE][BOARD_SIZE];
} game_t;

int main(void) {
    game_t game = {0};
    int i, j;

    // Initialize the board
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                game.board[i][j] = EMPTY;
            } else if (i < 3) {
                game.board[i][j] = BLACK;
            } else if (i > 4) {
                game.board[i][j] = RED;
            } else {
                game.board[i][j] = EMPTY;
            }
        }
    }

    // Game loop
    while (1) {
        // Print the board
        printf("    ");
        for(i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", i);
        }
        printf("\n");
        for(i = 0; i < BOARD_SIZE; i++) {
            printf("%d | ", i);
            for(j = 0; j < BOARD_SIZE; j++) {
                switch (game.board[i][j]) {
                    case EMPTY:
                        printf("  | ");
                        break;
                    case RED:
                        printf("R | ");
                        break;
                    case BLACK:
                        printf("B | ");
                        break;
                    default:
                        printf("? | ");
                        break;
                }
            }
            printf("\n");
        }

        // Ask for input
        printf("Enter move (x1 y1 x2 y2) or QUIT: ");
        char input[128];
        fgets(input, 128, stdin);
        if (strncmp(input, "QUIT\n", 5) == 0) {
            break;
        }

        // Parse input
        int x1, y1, x2, y2;
        sscanf(input, "%d %d %d %d", &x1, &y1, &x2, &y2);

        // Move piece
        if (game.board[y1][x1] == RED) {
            if (y2 == y1 + 1 && (x2 == x1 - 1 || x2 == x1 + 1)) {
                game.board[y1][x1] = EMPTY;
                game.board[y2][x2] = RED;
            } else if (y2 == y1 + 2) {
                int jump_x = (x1 + x2) / 2;
                if (game.board[y1 + 1][jump_x] == BLACK) {
                    game.board[y1][x1] = EMPTY;
                    game.board[y2][x2] = RED;
                    game.board[y1 + 1][jump_x] = EMPTY;
                }
            }
        } else if (game.board[y1][x1] == BLACK) {
            if (y2 == y1 - 1 && (x2 == x1 - 1 || x2 == x1 + 1)) {
                game.board[y1][x1] = EMPTY;
                game.board[y2][x2] = BLACK;
            } else if (y2 == y1 - 2) {
                int jump_x = (x1 + x2) / 2;
                if (game.board[y1 - 1][jump_x] == RED) {
                    game.board[y1][x1] = EMPTY;
                    game.board[y2][x2] = BLACK;
                    game.board[y1 - 1][jump_x] = EMPTY;
                }
            }
        }
    }

    return 0;
}