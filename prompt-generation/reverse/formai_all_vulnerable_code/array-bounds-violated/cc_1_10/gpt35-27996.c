//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>

// Function that prints the Tic Tac Toe board
void printBoard(char board[]) {
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
}

// Function that checks if there is a winner or if it is a tie
int checkWin(char board[]) {
    if (board[0] == board[1] && board[1] == board[2])
        return 1;
    else if (board[3] == board[4] && board[4] == board[5])
        return 1;
    else if (board[6] == board[7] && board[7] == board[8])
        return 1;
    else if (board[0] == board[3] && board[3] == board[6])
        return 1;
    else if (board[1] == board[4] && board[4] == board[7])
        return 1;
    else if (board[2] == board[5] && board[5] == board[8])
        return 1;
    else if (board[0] == board[4] && board[4] == board[8])
        return 1;
    else if (board[2] == board[4] && board[4] == board[6])
        return 1;
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' 
             && board[3] != '4' && board[4] != '5' && board[5] != '6' 
             && board[6] != '7' && board[7] != '8' && board[8] != '9')
        return 0;
    else
        return -1;
}

// Minimax function that calculates the best move for the computer
int minimax(char board[], int depth, int isMaxPlayer) {
    int score = checkWin(board);
    if (score == 1) // If the computer wins
        return 10 - depth;
    if (score == -1) // If the player wins
        return depth - 10;
    if (score == 0) // If it is a tie or no one wins
        return 0;
    
    if (isMaxPlayer) {
        int bestScore = -1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'O';
                bestScore = fmax(bestScore, minimax(board, depth + 1, !isMaxPlayer));
                board[i] = ' ';
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'X';
                bestScore = fmin(bestScore, minimax(board, depth + 1, !isMaxPlayer));
                board[i] = ' ';
            }
        }
        return bestScore;
    }
}

// Function that makes the computer move by calling the minimax function
int makeComputerMove(char board[]) {
    int bestScore = -1000;
    int bestMove = -1;
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            int score = minimax(board, 0, 0);
            board[i] = ' ';
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    return bestMove;
}

int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    // Print the initial board
    printf("Welcome to Tic Tac Toe! You are X and the computer is O.\n");
    printBoard(board);
    
    while (1) {
        // Player's turn
        int move;
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        if (board[move - 1] == ' ') {
            board[move - 1] = 'X';
            printBoard(board);
        }
        else {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        // Check for winner
        int winner = checkWin(board);
        if (winner == 1) {
            printf("Congratulations! You won!\n");
            break;
        }
        if (winner == 0) {
            printf("It's a tie!\n");
            break;
        }
        
        // Computer's turn
        int computerMove = makeComputerMove(board);
        board[computerMove] = 'O';
        printf("The computer made a move.\n");
        printBoard(board);
        
        // Check for winner
        winner = checkWin(board);
        if (winner == 1) {
            printf("The computer won. Better luck next time!\n");
            break;
        }
        if (winner == 0) {
            printf("It's a tie!\n");
            break;
        }
    }
    return 0;
}