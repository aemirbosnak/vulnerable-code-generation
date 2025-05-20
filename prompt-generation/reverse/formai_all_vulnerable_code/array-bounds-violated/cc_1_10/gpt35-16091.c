//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>

char gameBoard[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char playerSymbol, currentSymbol;
int row, col, moveCounter;

void displayBoard() {
    printf("\n\n");
    printf(" %c | %c | %c\n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
    printf("\n\n");
}

void getPlayerSymbol() {
    printf("Choose your symbol 'X' or 'O': ");
    scanf("%c", &playerSymbol);
    while (getchar() != '\n');
    if (playerSymbol == 'X') {
        currentSymbol = 'X';
    } else {
        currentSymbol = 'O';
    }
}

void getMove() {
    printf("Enter row and column number to move (e.g. 2 3): ");
    scanf("%d %d", &row, &col);
    while (getchar() != '\n');
    while (gameBoard[row - 1][col - 1] != ' ') {
        printf("Invalid move. Please try again.\n");
        printf("Enter row and column number to move (e.g. 2 3): ");
        scanf("%d %d", &row, &col);
        while (getchar() != '\n');
    }
    gameBoard[row - 1][col - 1] = currentSymbol;
    moveCounter++;
}

int checkWin() {
    //Check Rows
    for (int i = 0; i < 3; i++){
        if (gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2] && gameBoard[i][2] != ' ') {
            return 1;
        }
    }
    //Check Columns
    for (int i = 0; i < 3; i++){
        if (gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i] && gameBoard[2][i] != ' ') {
            return 1;
        }
    }
    //Check Diagonals
    if (gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2] && gameBoard[2][2] != ' ') {
        return 1;
    }
    if (gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0] && gameBoard[2][0] != ' ') {
        return 1;
    }
    if (moveCounter == 9) {
        return 2; //Game Tied
    }
    return 0;
}

int main() {
    printf("Welcome to Tic Tac Toe Game!\n\n");
    displayBoard();
    getPlayerSymbol();
    while (1) {
        printf("Player %c turn:\n", currentSymbol);
        getMove();
        displayBoard();
        if (checkWin() == 1) {
            printf("Player %c won!\n", currentSymbol);
            break;
        }
        if (checkWin() == 2) {
            printf("Game tied!\n");
            break;
        }
        if (currentSymbol == 'X') {
            currentSymbol = 'O';
        } else {
            currentSymbol = 'X';
        }
    }
    return 0;
}