//MISTRAL-7B DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 3
#define HEIGHT 3
#define EMPTY '.'
#define X 'X'
#define O 'O'

typedef struct { int x, y; } pos;

int check_win(char board[WIDTH][HEIGHT], char player, pos p) {
    int i, j, count = 1;
    for (i = p.y - 1; i <= p.y + 1 && i >= 0 && i < HEIGHT; i++) {
        for (j = p.x - 1; j <= p.x + 1 && j >= 0 && j < WIDTH; j++) {
            if (board[j][i] != player && board[j][i] != EMPTY) {
                count = 0;
                break;
            }
            if (i == p.y && j == p.x) continue;
            if (count > 2) return 1;
        }
    }
    return count == 3;
}

int main() {
    srand(time(NULL));
    char board[WIDTH][HEIGHT];
    int player = EMPTY;
    int x, y, choice;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[j][i] = EMPTY;
        }
    }

    do {
        printf("Current Board:\n");
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("%c ", board[j][i]);
            }
            printf("\n");
        }
        printf("\nYour Turn (%d,%d): ", &x, &y);
        scanf("%d%d", &x, &y);
        if (board[x][y] != EMPTY) {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[x][y] = player == EMPTY ? X : O;
        player = player == X ? O : X;
        pos p = {x, y};
        if (check_win(board, player, p)) {
            printf("Congratulations! You won.\n");
            break;
        }
        choice = rand() % 2 + 1;
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
        while (board[x][y] != EMPTY) {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        board[x][y] = player == X ? X : O;
    } while (check_win(board, player, (pos){-1, -1}));

    printf("Game Over.\n");
    return 0;
}