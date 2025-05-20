//FormAI DATASET v1.0 Category: Table Game ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3

typedef struct {
    int row;
    int col;
} Position;

char board[ROW][COL];

// Initializes the board
void initializeBoard() {
    for (int i = 0; i < ROW; i++) {
        for (int j=0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
}

// Displays the board 
void displayBoard() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if any move is valid
int isValid(Position position) {
    if (position.row < 0 || position.row > ROW || position.col < 0 || position.col > COL) {
        return 0;
    }
    if (board[position.row][position.col] != '-') {
        return 0;
    }
    return 1;
}

// Makes a move
void makeMove(char player, Position position) {
    board[position.row][position.col] = player;
}

// Checks if anyone won or it's a draw
char checkWinner() {
    for (int i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
    }

    for (int i = 0; i < COL; i++) {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];

    for (int i = 0; i < ROW; i++) {
        for (int j=0; j < COL; j++) {
            if (board[i][j] == '-') {
                return '-';
            }
        }
    }

    return ' ';
}

// A simple AI that makes a random move
Position AITurn() {
    Position position;
    srand(time(0));
    position.row = rand() % 3;
    position.col = rand() % 3;
    return position;
}

// Get user input to make a turn
Position getUserTurn() {
    Position position;
    printf("Enter row and column number (e.g. 1 2): ");
    scanf("%d %d", &position.row, &position.col);
    position.row--;
    position.col--;
    return position;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");

    initializeBoard();

    char currentPlayer = 'X';
    displayBoard();

    while (1) {
        Position position;
        
        if (currentPlayer == 'X') {
            position = getUserTurn();
        } else {
            printf("AI's turn\n");
            position = AITurn();
        }

        if (!isValid(position)) {
            printf("Invalid move!\n");
            continue;
        }

        makeMove(currentPlayer, position);
        displayBoard();
        
        char winner = checkWinner();
        if (winner != '-') {
            if (winner == ' ') {
                printf("It's a draw!\n");
            } else {
                printf("%c won!\n", winner);
            }
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}