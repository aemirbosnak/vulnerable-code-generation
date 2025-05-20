//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to display the board
void displayBoard(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// check if the game is over
int isGameOver(char board[3][3]) {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1;
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return 1;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1;
    }
    // check if board is full
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    // game is a tie
    return 2;
}

// function to get user input
void getUserInput(char board[3][3], int *x, int *y) {
    printf("Enter row and column (example: 1 2): ");
    scanf("%d %d", x, y);
    while (*x < 1 || *x > 3 || *y < 1 || *y > 3 || board[*x-1][*y-1] != ' ') {
        printf("Invalid input. Enter row and column (example: 1 2): ");
        scanf("%d %d", x, y);
    }
}

// function to get computer input
void getComputerInput(char board[3][3], int *x, int *y, char computerSymbol) {
    int i, j;
    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == computerSymbol && board[i][2] == ' ') {
            *x = i;
            *y = 2;
            return;
        }
        if (board[i][0] == board[i][2] && board[i][0] == computerSymbol && board[i][1] == ' ') {
            *x = i;
            *y = 1;
            return;
        }
        if (board[i][1] == board[i][2] && board[i][1] == computerSymbol && board[i][0] == ' ') {
            *x = i;
            *y = 0;
            return;
        }
    }
    // check columns
    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[0][j] == computerSymbol && board[2][j] == ' ') {
            *x = 2;
            *y = j;
            return;
        }
        if (board[0][j] == board[2][j] && board[0][j] == computerSymbol && board[1][j] == ' ') {
            *x = 1;
            *y = j;
            return;
        }
        if (board[1][j] == board[2][j] && board[1][j] == computerSymbol && board[0][j] == ' ') {
            *x = 0;
            *y = j;
            return;
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == computerSymbol && board[2][2] == ' ') {
        *x = 2;
        *y = 2;
        return;
    }
    if (board[0][0] == board[2][2] && board[0][0] == computerSymbol && board[1][1] == ' ') {
        *x = 1;
        *y = 1;
        return;
    }
    if (board[1][1] == board[2][2] && board[1][1] == computerSymbol && board[0][0] == ' ') {
        *x = 0;
        *y = 0;
        return;
    }
    if (board[0][2] == board[1][1] && board[0][2] == computerSymbol && board[2][0] == ' ') {
        *x = 2;
        *y = 0;
        return;
    }
    if (board[0][2] == board[2][0] && board[0][2] == computerSymbol && board[1][1] == ' ') {
        *x = 1;
        *y = 1;
        return;
    }
    if (board[1][1] == board[2][0] && board[1][1] == computerSymbol && board[0][2] == ' ') {
        *x = 0;
        *y = 2;
        return;
    }
    // check if center is available
    if (board[1][1] == ' ') {
        *x = 1;
        *y = 1;
        return;
    }
    // check if corner is available
    srand(time(NULL));
    i = rand() % 4;
    switch (i) {
        case 0:
            if (board[0][0] == ' ') {
                *x = 0;
                *y = 0;
            } else {
                getComputerInput(board, x, y, computerSymbol);
            }
            break;
        case 1:
            if (board[0][2] == ' ') {
                *x = 0;
                *y = 2;
            } else {
                getComputerInput(board, x, y, computerSymbol);
            }
            break;
        case 2:
            if (board[2][0] == ' ') {
                *x = 2;
                *y = 0;
            } else {
                getComputerInput(board, x, y, computerSymbol);
            }
            break;
        case 3:
            if (board[2][2] == ' ') {
                *x = 2;
                *y = 2;
            } else {
                getComputerInput(board, x, y, computerSymbol);
            }
            break;
    }
}

// main function
int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char playerSymbol, computerSymbol;
    int x, y, winner, turn;
    printf("Enter your symbol (X or O): ");
    scanf(" %c", &playerSymbol);
    while (playerSymbol != 'X' && playerSymbol != 'O') {
        printf("Invalid input. Enter your symbol (X or O): ");
        scanf(" %c", &playerSymbol);
    }
    computerSymbol = (playerSymbol == 'X') ? 'O' : 'X';
    turn = 1;
    while (1) {
        if (turn % 2 == 1) {
            printf("\nYour turn:\n");
            getUserInput(board, &x, &y);
            board[x-1][y-1] = playerSymbol;
            displayBoard(board);
        } else {
            printf("\nComputer's turn:\n");
            getComputerInput(board, &x, &y, computerSymbol);
            board[x][y] = computerSymbol;
            displayBoard(board);
        }
        winner = isGameOver(board);
        if (winner == 1) {
            if (turn % 2 == 1) {
                printf("\nCongratulations! You won!\n");
            } else {
                printf("\nSorry, you lost. Better luck next time.\n");
            }
            break;
        } else if (winner == 2) {
            printf("\nGame over. It's a tie.\n");
            break;
        }
        turn++;
    }
    return 0;
}