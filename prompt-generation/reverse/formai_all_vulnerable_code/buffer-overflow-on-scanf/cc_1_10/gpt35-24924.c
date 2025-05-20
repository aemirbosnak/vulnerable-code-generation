//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int getPlayerMove(int player);
int checkWin();
void printBoard();
void makeMove(int player, int move);

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

int main() {
    int currentPlayer = 1;
    int currentMove;
    int gameStatus;

    printf("Welcome to Tic Tac Toe AI!\n");

    while(1) {
        printBoard();

        currentMove = getPlayerMove(currentPlayer);
        makeMove(currentPlayer, currentMove);
        gameStatus = checkWin();

        if(gameStatus == 1) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        } else if(gameStatus == 2) {
            printf("Draw!\n");
            break;
        }

        currentPlayer = currentPlayer % 2 + 1;
    }

    return 0;
}

int getPlayerMove(int player) {
    int move;

    while(1) {
        printf("Player %d, please enter your move (1-9): ", player);
        scanf("%d", &move);

        if(move >= 1 && move <= 9) {
            if(board[(move - 1) / 3][(move - 1) % 3] == ' ') {
                return move;
            } else {
                printf("Invalid move. Please try again.\n");
            }
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }
}

int checkWin() {
    int i, j;

    for(i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1;
        }
    }

    for(i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return 1;
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1;
    }

    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
        return 1;
    }

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }

    return 2;
}

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void makeMove(int player, int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    board[row][col] = player == 1 ? 'X' : 'O';
}