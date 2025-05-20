//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdio.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int player = 0;

int checkWin() {
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ')
        return 1;
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != ' ')
        return 1;
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != ' ')
        return 1;
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ')
        return 1;
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != ' ')
        return 1;
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ')
        return 1;
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;
    return 0;
}

void drawBoard() {
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---------\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---------\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void playerMove() {
    int row, col;
    printf("\nEnter row number (1-3): ");
    scanf("%d", &row);
    printf("Enter column number (1-3): ");
    scanf("%d", &col);
    
    if (board[row-1][col-1] != ' ') {
        printf("\nInvalid move. Please try again.\n");
        playerMove();
    } else {
        if (player == 1) {
            board[row-1][col-1] = 'X';
            player = 0; 
        } else { 
            board[row-1][col-1] = 'O'; 
            player = 1; 
        }
    }
}

void computerMove() {
    int chosenRow, chosenCol, foundMove;
    foundMove = 0;
    // Checking for a winning move
    for (int row = 0; row < 3 && !foundMove; ++row) {
        for (int col = 0; col < 3 && !foundMove; ++col) {
            if (board[row][col] == ' ') {
                board[row][col] = 'O';
                if (checkWin()) {
                    chosenRow = row;
                    chosenCol = col;
                    foundMove = 1;
                }
                board[row][col] = ' ';
            }
        }
    }

    // Blocking the opponent's winning move
    for (int row = 0; row < 3 && !foundMove; ++row) {
        for (int col = 0; col < 3 && !foundMove; ++col) {
            if (board[row][col] == ' ') {
                board[row][col] = 'X';
                if (checkWin()) {
                    chosenRow = row;
                    chosenCol = col;
                    foundMove = 1;
                }
                board[row][col] = ' ';
            }
        }
    }

    // Choosing a random move
    while (!foundMove) {
        int row = rand() % 3;
        int col = rand() % 3;
        if (board[row][col] == ' ') {
            chosenRow = row;
            chosenCol = col;
            foundMove = 1;
        }
    }
    board[chosenRow][chosenCol] = 'O';
}

int main() {
    while (!checkWin()) {
        drawBoard();
        if (player == 0) {
            printf("\nIt's your turn (X).\n");
            playerMove();
        } else {
            printf("\nIt's computer's turn (O).\n");
            computerMove();
        }
    }
    drawBoard();
    if (player == 1) {
        printf("\nCongratulations! You won the game!\n");
    } else {
        printf("\nComputer wins!\n");
    }
    return 0;
}