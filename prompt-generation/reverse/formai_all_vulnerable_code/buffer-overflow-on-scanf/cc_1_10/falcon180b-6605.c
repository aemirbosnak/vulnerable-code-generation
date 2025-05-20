//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void drawBoard(char board[ROW][COL]) {
    int i, j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char board[ROW][COL]) {
    int i;
    // Check rows
    for(i = 0; i < ROW; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    // Check columns
    for(i = 0; i < COL; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    return 0;
}

int main() {
    char board[ROW][COL] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1;
    int choice;
    int flag = 0;

    while(flag == 0) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn\n", player);
        printf("Enter your move: ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 9) {
            if(board[0][choice - 1]!= 'X' && board[0][choice - 1]!= 'O') {
                board[0][choice - 1] = (player % 2 == 0)? 'X' : 'O';
                player++;
                flag = checkWin(board);
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    drawBoard(board);
    if(player % 2 == 0) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}