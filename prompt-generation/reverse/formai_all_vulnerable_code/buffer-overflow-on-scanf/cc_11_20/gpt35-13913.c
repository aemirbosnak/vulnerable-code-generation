//FormAI DATASET v1.0 Category: Checkers Game ; Style: Alan Touring
#include <stdio.h>

// Function to print the initial board
void printBoard(char board[8][8]) {
    printf("   0 1 2 3 4 5 6 7\n");
    for(int i=0; i<8; i++) {
        printf("%d ", i);
        for(int j=0; j<8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize the board with pieces
void initializeBoard(char board[8][8]) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(i%2 == 0 && j%2 == 1) {
                if(i < 3) {
                    board[i][j] = 'b';
                } else if(i > 4) {
                    board[i][j] = 'w';
                } else {
                    board[i][j] = ' ';
                }
            } else if(i%2 == 1 && j%2 == 0) {
                if(i < 3) {
                    board[i][j] = 'b';
                } else if(i > 4) {
                    board[i][j] = 'w';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to check if a move is valid
int isValidMove(char board[8][8], int fromX, int fromY, int toX, int toY, char currentPlayer) {
    if(board[fromX][fromY] != currentPlayer) {
        return 0;
    }
    if(board[toX][toY] != ' ') {
        return 0;
    }
    if(currentPlayer == 'w') {
        if(toX > fromX) {
            return 0;
        }
        if(fromX - toX > 2 || fromY - toY > 2 || fromX - toX < 1 || fromY - toY < -1) {
            return 0;
        }
        if(fromX - toX == 2 && fromY - toY == 2 && board[fromX-1][fromY-1] == 'b') {
            return 1;
        } else if(fromX - toX == 2 && fromY - toY == -2 && board[fromX-1][fromY+1] == 'b') {
            return 1;
        } else if(fromX - toX == 1 && fromY - toY == 1) {
            return 1;
        } else if(fromX - toX == 1 && fromY - toY == -1) {
            return 1;
        }
    } else {
        if(toX < fromX) {
            return 0;
        }
        if(toX - fromX > 2 || fromY - toY > 2 || toX - fromX < 1 || fromY - toY < -1) {
            return 0;
        }
        if(toX - fromX == 2 && fromY - toY == 2 && board[fromX+1][fromY-1] == 'w') {
            return 1;
        } else if(toX - fromX == 2 && fromY - toY == -2 && board[fromX+1][fromY+1] == 'w') {
            return 1;
        } else if(toX - fromX == 1 && fromY - toY == 1) {
            return 1;
        } else if(toX - fromX == 1 && fromY - toY == -1) {
            return 1;
        }
    }
    return 0;
}

// Function to make a move
void makeMove(char board[8][8], int fromX, int fromY, int toX, int toY, char currentPlayer) {
    board[toX][toY] = board[fromX][fromY];
    board[fromX][fromY] = ' ';
    if(currentPlayer == 'w' && toX == 0) {
        board[toX][toY] = 'W';
    } else if(currentPlayer == 'b' && toX == 7) {
        board[toX][toY] = 'B';
    }
}

// Function to check if there are any valid moves left for a player
int noValidMoves(char board[8][8], char currentPlayer) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == currentPlayer || board[i][j] == toupper(currentPlayer)) {
                if(i > 0 && j > 0 && board[i-1][j-1] == ' ') {
                    if(isValidMove(board, i, j, i-1, j-1, currentPlayer)) {
                        return 0;
                    }
                }
                if(i > 0 && j < 7 && board[i-1][j+1] == ' ') {
                    if(isValidMove(board, i, j, i-1, j+1, currentPlayer)) {
                        return 0;
                    }
                }
                if(i < 7 && j > 0 && board[i+1][j-1] == ' ') {
                    if(isValidMove(board, i, j, i+1, j-1, currentPlayer)) {
                        return 0;
                    }
                }
                if(i < 7 && j < 7 && board[i+1][j+1] == ' ') {
                    if(isValidMove(board, i, j, i+1, j+1, currentPlayer)) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

// Function to get the player's move
void getPlayerMove(char board[8][8], int* fromX, int* fromY, int* toX, int* toY, char currentPlayer) {
    int validMove = 0;
    while(!validMove) {
        printf("%c's turn\n", currentPlayer);
        printf("Enter the coordinates of the piece you want to move: ");
        scanf("%d %d", fromX, fromY);
        printf("Enter the coordinates of where you want to move it: ");
        scanf("%d %d", toX, toY);
        if(isValidMove(board, *fromX, *fromY, *toX, *toY, currentPlayer)) {
            validMove = 1;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

// Function to make a computer move
void makeComputerMove(char board[8][8], char computerPlayer) {
    int fromX, fromY, toX, toY;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == computerPlayer || board[i][j] == toupper(computerPlayer)) {
                if(i > 0 && j > 0 && board[i-1][j-1] == ' ') {
                    if(isValidMove(board, i, j, i-1, j-1, computerPlayer)) {
                        fromX = i;
                        fromY = j;
                        toX = i-1;
                        toY = j-1;
                        makeMove(board, fromX, fromY, toX, toY, computerPlayer);
                        return;
                    }
                }
                if(i > 0 && j < 7 && board[i-1][j+1] == ' ') {
                    if(isValidMove(board, i, j, i-1, j+1, computerPlayer)) {
                        fromX = i;
                        fromY = j;
                        toX = i-1;
                        toY = j+1;
                        makeMove(board, fromX, fromY, toX, toY, computerPlayer);
                        return;
                    }
                }
                if(i < 7 && j > 0 && board[i+1][j-1] == ' ') {
                    if(isValidMove(board, i, j, i+1, j-1, computerPlayer)) {
                        fromX = i;
                        fromY = j;
                        toX = i+1;
                        toY = j-1;
                        makeMove(board, fromX, fromY, toX, toY, computerPlayer);
                        return;
                    }
                }
                if(i < 7 && j < 7 && board[i+1][j+1] == ' ') {
                    if(isValidMove(board, i, j, i+1, j+1, computerPlayer)) {
                        fromX = i;
                        fromY = j;
                        toX = i+1;
                        toY = j+1;
                        makeMove(board, fromX, fromY, toX, toY, computerPlayer);
                        return;
                    }
                }
            }
        }
    }
}

// Main function
int main() {
    char board[8][8];
    char humanPlayer, computerPlayer, currentPlayer;
    int fromX, fromY, toX, toY;
    int gameOver = 0;
    printf("Welcome to Checkers!\n");
    printf("Do you want to play as white or black? (w/b): ");
    scanf(" %c", &humanPlayer);
    if(humanPlayer == 'w') {
        computerPlayer = 'b';
    } else {
        computerPlayer = 'w';
    }
    initializeBoard(board);
    currentPlayer = 'w';
    while(!gameOver) {
        printBoard(board);
        if(noValidMoves(board, currentPlayer)) {
            printf("%c has no valid moves left\n", currentPlayer);
            if(currentPlayer == humanPlayer) {
                printf("Game Over! You lose.\n");
            } else {
                printf("Game Over! You win.\n");
            }
            gameOver = 1;
        } else {
            if(currentPlayer == humanPlayer) {
                getPlayerMove(board, &fromX, &fromY, &toX, &toY, currentPlayer);
                makeMove(board, fromX, fromY, toX, toY, currentPlayer);
            } else {
                printf("It's the computer's turn\n");
                makeComputerMove(board, currentPlayer);
            }
            if(currentPlayer == 'w') {
                currentPlayer = 'b';
            } else {
                currentPlayer = 'w';
            }
        }
    }
    return 0;
}