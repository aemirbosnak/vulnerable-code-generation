//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

char board[3][3];
char playerSymbol, computerSymbol;

void initBoard(void) {
    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard(void) {
    int i, j;

    printf("\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool isBoardFull(void) {
    int i, j;

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

bool hasWon(char symbol) {
    int i;
    //row checking
    for(i = 0; i < 3; i++) {
        if((board[i][0] == symbol) && (board[i][1] == symbol) && (board[i][2] == symbol)) {
            return true;
        }
    }

    //column checking
    for(i = 0; i < 3; i++) {
        if((board[0][i] == symbol) && (board[1][i] == symbol) && (board[2][i] == symbol)) {
            return true;
        }
    }

    //diagonal checking
    if((board[0][0] == symbol) && (board[1][1] == symbol) && (board[2][2] == symbol)) {
        return true;
    } else if((board[2][0] == symbol) && (board[1][1] == symbol) && (board[0][2] == symbol)) {
        return true;
    }

    return false;
}

bool checkWinner(void) {
    if(hasWon(playerSymbol)) {
        printf("\n@@@@@-PLAYER %c WON-@@@@@\n", playerSymbol);
        return true;
    } else if(hasWon(computerSymbol)) {
        printf("\n@@@@@-COMPUTER %c WON-@@@@@\n", computerSymbol);
        return true;
    } else if(isBoardFull()) {
        printf("\n@@@@@-GAME DRAW-@@@@@\n");
        return true;
    }

    return false;
}

void playerTurn(void) {
    int row, col;

    printf("\n@@@@@-PLAYER %c TURN-@@@@@\n", playerSymbol);
    printf("\nEnter row (1-3) and column (1-3) with space separating them: ");
    scanf("%d %d", &row, &col);
    row--, col--;
    while((row < 0) || (row > 2) || (col < 0) || (col > 2) || (board[row][col] != '-')) {
        printf("\nInvalid move. Please try again!\n");
        printf("\nEnter row (1-3) and column (1-3) with space separating them: ");
        scanf("%d %d", &row, &col);
        row--, col--;
    }
    board[row][col] = playerSymbol;
}

void computerTurn(void) {
    int i, j;
    printf("\n@@@@@-COMPUTER %c TURN-@@@@@\n", computerSymbol);

    //checking for winning move
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = computerSymbol;
                if(hasWon(computerSymbol)) {
                    return;
                }
                board[i][j] = '-';
            }
        }
    }
    //checking for blocking move
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                board[i][j] = playerSymbol;
                if(hasWon(playerSymbol)) {
                    board[i][j] = computerSymbol;
                    return;
                }
                board[i][j] = '-';
            }
        }
    }
    //random move
    do {
        i = rand() % 3;
        j = rand() % 3;
    } while(board[i][j] != '-');
    board[i][j] = computerSymbol;
}

int main(void) {
    int toss;

    printf("\nWelcome to Tic Tac Toe!\n");
    printf("Player 1, please choose your symbol (X/O): ");
    scanf("%c", &playerSymbol);
    while((playerSymbol != 'X') && (playerSymbol != 'O')) {
        printf("\nInvalid input. Please try again!\n");
        printf("Player 1, please choose your symbol (X/O): ");
        scanf("%c", &playerSymbol);
    }

    if(playerSymbol == 'X') {
        computerSymbol = 'O';
    } else {
        computerSymbol = 'X';
    }

    printf("\nTossing...");
    toss = rand() % 2;
    if(toss == 0) {
        printf("\nPlayer 1 has won the toss!\n");
        playerTurn();
    } else {
        printf("\nComputer has won the toss!\n");
        computerTurn();
    }
    printBoard();

    while(!checkWinner()) {
        if((toss == 0) || (toss == 2)) {
            computerTurn();
            printBoard();
            playerTurn();
            printBoard();
            toss = 1;
        } else {
            playerTurn();
            printBoard();
            computerTurn();
            printBoard();
            toss = 2;
        }
    }

    return 0;
}