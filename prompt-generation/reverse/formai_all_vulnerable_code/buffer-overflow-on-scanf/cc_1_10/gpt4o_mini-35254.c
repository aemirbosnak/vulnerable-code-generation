//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include <stdio.h>

#define SIZE 3
#define PLAYER 'X'
#define AI 'O'
#define EMPTY ' '

void initializeBoard(char board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            board[i][j] = EMPTY;
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n Tic Tac Toe Board:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if(j < SIZE - 1) printf("|");
        }
        printf("\n");
        if(i < SIZE - 1) {
            printf("-----------\n");
        }
    }
}

int checkWin(char board[SIZE][SIZE], char player) {
    for(int i = 0; i < SIZE; i++) {
        if((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
           (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    }
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
       (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    
    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            if(board[i][j] == EMPTY)
                return 0; 
    return 1;
}

void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    printf("\nYour turn! Enter row and column (0-2): ");
    scanf("%d %d", &row, &col);
    if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == EMPTY) {
        board[row][col] = PLAYER;
    } else {
        printf("Oops! Invalid move. Try again.\n");
        playerMove(board);
    }
}

void aiMove(char board[SIZE][SIZE]) {
    printf("\nAI is thinking...\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == EMPTY) {
                board[i][j] = AI;
                if(checkWin(board, AI)) {
                    printf("AI places \"%c\" at position (%d, %d).\n", AI, i, j);
                    return;
                }
                board[i][j] = EMPTY; // Reset
            }
        }
    }
    
    // If no winning move, pick the first available spot
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(board[i][j] == EMPTY) {
                board[i][j] = AI;
                printf("AI places \"%c\" at position (%d, %d).\n", AI, i, j);
                return;
            }
        }
    }
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    printf("Welcome to Tic Tac Toe!\n");
    
    while(1) {
        printBoard(board);
        
        playerMove(board);
        if(checkWin(board, PLAYER)) {
            printBoard(board);
            printf("Congratulations! You win! 🎉\n");
            break;
        }
        if(checkDraw(board)) {
            printBoard(board);
            printf("It's a draw! 😊\n");
            break;
        }
        
        aiMove(board);
        if(checkWin(board, AI)) {
            printBoard(board);
            printf("AI wins this time! 🤖\n");
            break;
        }
        if(checkDraw(board)) {
            printBoard(board);
            printf("It's a draw! 😊\n");
            break;
        }
    }
    
    printf("Thank you for playing! See you next time! 😊\n");
    return 0;
}