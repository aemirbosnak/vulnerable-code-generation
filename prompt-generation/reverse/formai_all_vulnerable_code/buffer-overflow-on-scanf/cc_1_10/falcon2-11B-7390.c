//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(char *board, int player, int turn) {
    if (player == 1) {
        printf("Player 1's turn.\n");
    } else {
        printf("Player 2's turn.\n");
    }
    
    printf("Current board state: %s\n", board);
    printf("Current turn: %d\n", turn);
    
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("(%d,%d): %d\n", i, j, board[i * 8 + j]);
        }
    }
    
    int x, y;
    printf("Enter coordinates (x,y): ");
    scanf("%d%d", &x, &y);
    
    if (board[x * 8 + y]!= -1) {
        printf("Invalid move. Please try again.\n");
        return;
    }
    
    board[x * 8 + y] = player;
    if (player == 1) {
        printf("Player 1 moved to (%d,%d).\n", x, y);
    } else {
        printf("Player 2 moved to (%d,%d).\n", x, y);
    }
    
    if (checkForWinner(board, player) || checkForStalemate(board)) {
        printf("Game over. Winner: ");
        if (player == 1) {
            printf("Player 1\n");
        } else {
            printf("Player 2\n");
        }
    }
    
    if (turn % 2 == 0) {
        player = 2;
    } else {
        player = 1;
    }
    turn++;
}

void displayBoard(char *board) {
    int i, j;
    for (i = 0; i < 8; i++) {
        printf(" %c | %c | %c |\n", board[i * 8], board[i * 8 + 1], board[i * 8 + 2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c |\n", board[i * 8 + 3], board[i * 8 + 4], board[i * 8 + 5]);
        printf("---+---+---\n");
        printf(" %c | %c | %c |\n", board[i * 8 + 6], board[i * 8 + 7], board[i * 8 + 8]);
        printf("--------------------------------------\n");
    }
}

int checkForWinner(char *board, int player) {
    int i, j;
    for (i = 0; i < 8; i++) {
        if (board[i * 8] == player && board[i * 8 + 1] == player && board[i * 8 + 2] == player) {
            return 1;
        }
        if (board[i * 8 + 3] == player && board[i * 8 + 4] == player && board[i * 8 + 5] == player) {
            return 1;
        }
        if (board[i * 8 + 6] == player && board[i * 8 + 7] == player && board[i * 8 + 8] == player) {
            return 1;
        }
        if (board[i * 8 + 0] == player && board[i * 8 + 3] == player && board[i * 8 + 6] == player) {
            return 1;
        }
        if (board[i * 8 + 1] == player && board[i * 8 + 4] == player && board[i * 8 + 7] == player) {
            return 1;
        }
        if (board[i * 8 + 2] == player && board[i * 8 + 5] == player && board[i * 8 + 8] == player) {
            return 1;
        }
        if (board[i * 8 + 0] == player && board[i * 8 + 4] == player && board[i * 8 + 8] == player) {
            return 1;
        }
        if (board[i * 8 + 2] == player && board[i * 8 + 4] == player && board[i * 8 + 6] == player) {
            return 1;
        }
    }
    return 0;
}

int checkForStalemate(char *board) {
    int i, j;
    for (i = 0; i < 8; i++) {
        if (board[i * 8] == -1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    srand(time(0));
    
    char board[64] = {0};
    
    char player = 1;
    int turn = 0;
    
    printf("Welcome to C Chess AI!\n");
    printf("Player 1: ");
    scanf("%d", &player);
    
    while (player!= 0) {
        if (player == 1) {
            printf("Player 1: ");
        } else {
            printf("Player 2: ");
        }
        scanf("%d", &player);
    }
    
    while (turn < 50) {
        playGame(board, player, turn);
        displayBoard(board);
        printf("\n");
        turn++;
    }
    
    displayBoard(board);
    printf("\nGame over. Stalemate.\n");
    
    return 0;
}