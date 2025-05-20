//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: single-threaded
#include <stdio.h>

int main() {
    int board[8][8];

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }

    printf("Welcome to Checkers!\n");
    printf("Player 1 (X), Player 2 (O):\n");

    char player1[4];
    char player2[4];

    for(int i = 0; i < 4; i++) {
        scanf("%s", &player1[i]);
    }
    for(int i = 0; i < 4; i++) {
        scanf("%s", &player2[i]);
    }

    printf("Player 1: %s\n", player1);
    printf("Player 2: %s\n", player2);

    int player1_turn = 1;
    int player2_turn = 2;
    int game_over = 0;

    while(game_over == 0) {
        printf("Player %d's turn.\n", player1_turn + 1);
        printf("Select a piece to move:\n");
        int row, col;
        scanf("%d %d", &row, &col);
        if(board[row][col] == 1) {
            board[row][col] = player1_turn;
            player1_turn = 2;
        } else if(board[row][col] == 2) {
            board[row][col] = player1_turn;
            player1_turn = 1;
        } else {
            printf("Invalid move.\n");
        }
        printf("The board after Player %d's move:\n", player1_turn + 1);
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        if(game_over == 0) {
            printf("Player 2's turn.\n");
            printf("Select a piece to move:\n");
            int row, col;
            scanf("%d %d", &row, &col);
            if(board[row][col] == 1) {
                board[row][col] = player2_turn;
                player2_turn = 2;
            } else if(board[row][col] == 2) {
                board[row][col] = player2_turn;
                player2_turn = 1;
            } else {
                printf("Invalid move.\n");
            }
            printf("The board after Player %d's move:\n", player2_turn + 1);
            for(int i = 0; i < 8; i++) {
                for(int j = 0; j < 8; j++) {
                    printf("%d ", board[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }

        if(player1_turn == 2) {
            if(player2_turn == 1) {
                player1_turn = 1;
                player2_turn = 2;
            } else {
                player1_turn = 1;
                player2_turn = 1;
            }
        } else {
            if(player2_turn == 1) {
                player1_turn = 2;
                player2_turn = 1;
            } else {
                player1_turn = 2;
                player2_turn = 2;
            }
        }

        if(game_over == 0) {
            printf("Game is not over.\n");
        } else {
            printf("Game over!\n");
        }

        if(player1_turn == 1 && player2_turn == 2) {
            printf("Player 1 wins!\n");
            game_over = 1;
        } else if(player1_turn == 2 && player2_turn == 1) {
            printf("Player 2 wins!\n");
            game_over = 1;
        }
    }

    return 0;
}