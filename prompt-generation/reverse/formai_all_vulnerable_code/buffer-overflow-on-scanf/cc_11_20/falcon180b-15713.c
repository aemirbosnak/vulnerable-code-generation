//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the game board
void printBoard(int board[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == 1)
                printf("X ");
            else if(board[i][j] == 2)
                printf("O ");
            else
                printf("_ ");
        }
        printf("\n");
    }
}

// Function to check if a player has won
int checkWin(int board[3][3], int player) {
    // Check horizontal lines
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }

    // Check vertical lines
    for(int j=0; j<3; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
        if(board[j][0] == player && board[j][1] == player && board[j][2] == player)
            return 1;
    }

    // Check diagonal lines
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

int main() {
    srand(time(NULL));
    int board[3][3] = {{1, 2, 0}, {2, 1, 0}, {0, 0, 0}};
    int player = 1;
    int moves = 0;

    while(1) {
        system("clear");
        printBoard(board);
        printf("\nMoves: %d\n", moves);
        printf("Player %d's turn\n", player);

        int x, y;
        if(player == 1) {
            x = 0;
            y = 0;
        } else {
            x = 2;
            y = 2;
        }

        while(1) {
            char choice;
            printf("Enter your move (1-%d): ", 9);
            scanf("%c", &choice);
            if(choice >= '1' && choice <= '9') {
                int num = choice - '0';
                if(board[x][y] == 0 && num <= 8) {
                    board[x][y] = player;
                    moves++;
                    break;
                }
            }
            printf("Invalid move, try again.\n");
        }

        if(checkWin(board, player)) {
            printf("\nPlayer %d wins!\n", player);
            break;
        }

        player =!player;
    }

    return 0;
}