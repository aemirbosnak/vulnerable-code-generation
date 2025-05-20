//GPT-4o-mini DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define EMPTY ' '
#define PLAYER 'X'
#define AI 'O'

char board[3][3];
int turns = 0;

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
}

void printBoard() {
    printf("Current board:\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
}

bool isBoardFull() {
    return turns >= 9;
}

bool isWinner(char player) {
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

void playerMove() {
    int row, col;
    while (1) {
        printf("Enter your move (row and column): ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY) {
            printf("Oops! Invalid move. Try again, Einstein!\n");
        } else {
            board[row][col] = PLAYER;
            turns++;
            break;
        }
    }
}

void aiMove() {
    printf("AI is thinking... or maybe it's just taking a nap!\n");
    srand(time(NULL)); // Seed for randomness
    int row, col;

    while (1) {
        row = rand() % 3;
        col = rand() % 3;
        if (board[row][col] == EMPTY) {
            board[row][col] = AI;
            turns++;
            printf("AI chose (%d, %d). I hope you're ready!\n", row, col);
            break;
        }
    }
}

void playGame() {
    while (true) {
        printBoard();
        playerMove();
        
        if (isWinner(PLAYER)) {
            printBoard();
            printf("Congratulations! You've outsmarted the AI! 🏆\n");
            return;
        }
        
        if (isBoardFull()) {
            printBoard();
            printf("It's a tie! Even the AI has to admit you're both amazing! 🎉\n");
            return;
        }

        aiMove();
        
        if (isWinner(AI)) {
            printBoard();
            printf("Oh no! The AI has won! Better luck next time, human! 🤖💔\n");
            return;
        }
        
        if (isBoardFull()) {
            printBoard();
            printf("Looks like it's a tie again! Maybe you should both get some snacks! 🍕\n");
            return;
        }
    }
}

int main() {
    printf("Welcome to Tic Tac Toe! May the best player win!\n");
    initializeBoard();
    playGame();
    return 0;
}