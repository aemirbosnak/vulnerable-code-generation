//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkForWin(char board[3][3], char mark) {
    int i, j;
    for (i = 0; i < 3; i++) {
        if ((board[i][0] == mark) && (board[i][1] == mark) && (board[i][2] == mark)) {
            return 1;
        }
        if ((board[0][i] == mark) && (board[1][i] == mark) && (board[2][i] == mark)) {
            return 1;
        }
    }
    if ((board[0][0] == mark) && (board[1][1] == mark) && (board[2][2] == mark)) {
        return 1;
    }
    if ((board[0][2] == mark) && (board[1][1] == mark) && (board[2][0] == mark)) {
        return 1;
    }
    return 0;
}

void displayBoard(char board[3][3]) {
    printf("\n");
    printf("  0 1 2\n");
    printf("0 %c|%c|%c\n", board[0][0], board[0][1], board[0][2]);
    printf("  -----\n");
    printf("1 %c|%c|%c\n", board[1][0], board[1][1], board[1][2]);
    printf("  -----\n");
    printf("2 %c|%c|%c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int minimax(char board[3][3], int depth, char player) {
    int score = 0;
    int bestScore = 0; 
    int row, col; 
    int i, j;
    char opponent = (player == 'X') ? 'O' : 'X'; 
    
    if (checkForWin(board, opponent)) { 
        return depth - 10; 
    } else if (checkForWin(board, player)) { 
        return 10 - depth; 
    } else if (depth == 0) { 
        return 0;
    }
    
    bestScore = (player == 'X') ? -100 : 100;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;                
                score = minimax(board, depth - 1, (player == 'X') ? 'O' : 'X');
                if (player == 'X') {
                    if (score > bestScore) {
                        bestScore = score;
                    }
                } else {
                    if (score < bestScore) {
                        bestScore = score;
                    }
                }
                board[i][j] = ' ';
            }
        }
    }
    
    return bestScore;

}

void computerMove(char board[3][3], char computerMark, char playerMark) {
    int row, col, score;
    int i, j;
    int bestScore = (computerMark == 'X') ? -100 : 100;
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {            
            if (board[i][j] == ' ') {
                board[i][j] = computerMark;
                score = minimax(board, 9, playerMark);
                if (computerMark == 'X') {
                    if (score > bestScore) {
                        bestScore = score;
                        row = i;
                        col = j;
                    }
                } else {
                    if (score < bestScore) {
                        bestScore = score;
                        row = i;
                        col = j;
                    }
                }
                board[i][j] = ' ';
            }
        }
    }
    board[row][col] = computerMark;
    printf("Computer plays <%c> at position (%d, %d):\n", computerMark, row, col);
}

int isBoardFull(char board[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char playerMark, computerMark;
    int row, col, turn = 0;
    int i, j;

    srand(time(NULL));
    int playerTurn = rand() % 2;
    
    printf("Welcome to Tic Tac Toe!\n");
    
    if (playerTurn == 0) {
        printf("You go first!\n");
        playerMark = 'X';
        computerMark = 'O';
    } else {
        printf("Computer goes first.\n");
        playerMark = 'O';
        computerMark = 'X';
        computerMove(board, computerMark, playerMark);
        displayBoard(board);
        turn++;
    }

    while (1) {
        printf("Enter row and column for <%c> (use space): ", playerMark);
        scanf("%d %d", &row, &col);
        while (board[row][col] != ' ') {
            printf("Invalid move, please try again.\n");
            printf("Enter row and column for <%c> (use space): ", playerMark);
            scanf("%d %d", &row, &col);
        }
        board[row][col] = playerMark;
        displayBoard(board);
        turn++;
        if (checkForWin(board, playerMark)) {
            printf("Congratulations! You win!\n");
            break;            
        } else if (isBoardFull(board)) {
            printf("Game ends in a tie.\n");
            break;
        }
        computerMove(board, computerMark, playerMark);
        displayBoard(board);
        turn++;
        if (checkForWin(board, computerMark)) {
            printf("Sorry, you lose!\n");
            break;            
        } else if (isBoardFull(board)) {
            printf("Game ends in a tie.\n");
            break;
        }
    }
    
    return 0;
}