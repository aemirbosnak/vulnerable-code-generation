//FormAI DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>

char board[8][8] = {
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'},
    {'_', 'w', '_', 'w', '_', 'w', '_', 'w'},
    {'w', '_', 'w', '_', 'w', '_', 'w', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
};

void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int player = 1; // player 1 is white, player 2 is black
    int x1, y1, x2, y2;

    while (1) {
        printf("Player %d's turn\n", player);

        printf("Enter the x and y coordinates of the piece you want to move: ");
        scanf("%d%d", &x1, &y1);

        printf("Enter the x and y coordinates of where you want to move: ");
        scanf("%d%d", &x2, &y2);

        if (board[x1][y1] == '_') {
            printf("There is no piece there\n");
            continue;
        }

        if (player == 1 && board[x1][y1] == 'b') {
            printf("You can only move your own pieces\n");
            continue;
        }

        if (player == 2 && board[x1][y1] == 'w') {
            printf("You can only move your own pieces\n");
            continue;
        }

        if (board[x2][y2] != '_') {
            printf("There is already a piece there\n");
            continue;
        }

        if (player == 1 && x2 >= x1) {
            printf("You can only move your pieces forward\n");
            continue;
        }

        if (player == 2 && x2 <= x1) {
            printf("You can only move your pieces forward\n");
            continue;
        }

        int dx = x2 - x1;
        int dy = y2 - y1;

        if (dx == 1 && dy == 1 && board[x1+1][y1+1] != '_' && board[x1+1][y1+1] != board[x1][y1]) { // capture to the right
            board[x2][y2] = board[x1][y1];
            board[x1][y1] = '_';
            board[x1+1][y1+1] = '_';
        }
        else if (dx == 1 && dy == -1 && board[x1+1][y1-1] != '_' && board[x1+1][y1-1] != board[x1][y1]) { // capture to the left
            board[x2][y2] = board[x1][y1];
            board[x1][y1] = '_';
            board[x1+1][y1-1] = '_';
        }
        else if (dx == 2 && dy == 2 && board[x1+1][y1+1] != '_' && board[x1+1][y1+1] != board[x1][y1]) { // jump to the right
            board[x2][y2] = board[x1][y1];
            board[x1][y1] = '_';
            board[x1+1][y1+1] = '_';
        }
        else if (dx == 2 && dy == -2 && board[x1+1][y1-1] != '_' && board[x1+1][y1-1] != board[x1][y1]) { // jump to the left
            board[x2][y2] = board[x1][y1];
            board[x1][y1] = '_';
            board[x1+1][y1-1] = '_';
        }
        else {
            printf("Invalid move\n");
            continue;
        }

        print_board();

        if (player == 1 && x2 == 0) {
            printf("Player 1 wins!\n");
            break;
        }
        else if (player == 2 && x2 == 7) {
            printf("Player 2 wins!\n");
            break;
        }

        player = (player % 2) + 1;
    }

    return 0;
}