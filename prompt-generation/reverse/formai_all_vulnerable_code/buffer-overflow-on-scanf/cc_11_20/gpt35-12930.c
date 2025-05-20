//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];
int maxDepth = 0;

// Initialize the game board
void initBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Display the game board
void displayBoard() {
    printf("\n| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
}

// Check if someone won the game
char checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != '-' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return '-';
}

// Check if the game is over
int gameOver() {
    char result = checkWin();
    if (result == 'X' || result == 'O') {
        printf("\nGame over! %c won!\n", result);
        return 1;
    }
    else {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    return 0; // Game is not over yet
                }
            }
        }
        printf("\nGame over! It's a tie!\n");
        return 1;
    }
}

// Evaluate the score of the current board for a given player
int evaluate(char player) {
    int score = 0;

    // Check rows
    for (int i = 0; i < 3; i++) {
        int numPlayer = 0, numOpponent = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == player) {
                numPlayer++;
            }
            else if (board[i][j] != '-') {
                numOpponent++;
            }
        }
        if (numPlayer == 3) {
            return 10;
        }
        else if (numOpponent == 3) {
            return -10;
        }
        else if (numPlayer == 2 && numOpponent == 0) {
            score += 5;
        }
        else if (numPlayer == 1 && numOpponent == 0) {
            score++;
        }
        else if (numOpponent == 2 && numPlayer == 0) {
            score -= 5;
        }
        else if (numOpponent == 1 && numPlayer == 0) {
            score--;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        int numPlayer = 0, numOpponent = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][j] == player) {
                numPlayer++;
            }
            else if (board[i][j] != '-') {
                numOpponent++;
            }
        }
        if (numPlayer == 3) {
            return 10;
        }
        else if (numOpponent == 3) {
            return -10;
        }
        else if (numPlayer == 2 && numOpponent == 0) {
            score += 5;
        }
        else if (numPlayer == 1 && numOpponent == 0) {
            score++;
        }
        else if (numOpponent == 2 && numPlayer == 0) {
            score -= 5;
        }
        else if (numOpponent == 1 && numPlayer == 0) {
            score--;
        }
    }

    // Check diagonals
    int numPlayer = 0, numOpponent = 0;
    for (int i = 0, j = 0; i < 3; i++, j++) {
        if (board[i][j] == player) {
            numPlayer++;
        }
        else if (board[i][j] != '-') {
            numOpponent++;
        }
    }
    if (numPlayer == 3) {
        return 10;
    }
    else if (numOpponent == 3) {
        return -10;
    }
    else if (numPlayer == 2 && numOpponent == 0) {
        score += 5;
    }
    else if (numPlayer == 1 && numOpponent == 0) {
        score++;
    }
    else if (numOpponent == 2 && numPlayer == 0) {
        score -= 5;
    }
    else if (numOpponent == 1 && numPlayer == 0) {
        score--;
    }

    numPlayer = 0, numOpponent = 0;
    for (int i = 2, j = 0; i >= 0; i--, j++) {
        if (board[i][j] == player) {
            numPlayer++;
        }
        else if (board[i][j] != '-') {
            numOpponent++;
        }
    }
    if (numPlayer == 3) {
        return 10;
    }
    else if (numOpponent == 3) {
        return -10;
    }
    else if (numPlayer == 2 && numOpponent == 0) {
        score += 5;
    }
    else if (numPlayer == 1 && numOpponent == 0) {
        score++;
    }
    else if (numOpponent == 2 && numPlayer == 0) {
        score -= 5;
    }
    else if (numOpponent == 1 && numPlayer == 0) {
        score--;
    }

    return score;
}

// Minimax algorithm with alpha-beta pruning
int minimax(char player, int depth, int alpha, int beta) {
    int score = evaluate(player);
    if (depth == maxDepth || score == 10 || score == -10) {
        return score;
    }

    char opponent;
    if (player == 'X') {
        opponent = 'O';
    }
    else {
        opponent = 'X';
    }

    if (player == 'O') {
        int bestValue = alpha;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = player;
                    int maxValue = minimax(opponent, depth + 1, bestValue, beta);
                    board[i][j] = '-';
                    if (maxValue > bestValue) {
                        bestValue = maxValue;
                    }
                    if (bestValue >= beta) {
                        return bestValue;
                    }
                }
            }
        }
        return bestValue;
    }
    else {
        int bestValue = beta;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = player;
                    int minValue = minimax(opponent, depth + 1, alpha, bestValue);
                    board[i][j] = '-';
                    if (minValue < bestValue) {
                        bestValue = minValue;
                    }
                    if (bestValue <= alpha) {
                        return bestValue;
                    }
                }
            }
        }
        return bestValue;
    }
}

// Make a move
void makeMove(char player) {
    if (player == 'X') {
        int row, col;
        do {
            printf("\nEnter row (1-3) and column (1-3) to make a move: ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (row < 0 || row >= 3 || col < 0 || col >= 3) {
                printf("\nInvalid row or column. Try again.\n");
            }
            else if (board[row][col] != '-') {
                printf("\nThat cell is already taken. Try again.\n");
            }
            else {
                board[row][col] = 'X';
            }
        } while (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-');
    }
    else {
        printf("\nAI is thinking ...\n");
        int bestValue = -1000;
        int row = -1, col = -1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                    int value = minimax('X', 0, -1000, 1000);
                    board[i][j] = '-';
                    if (value > bestValue) {
                        bestValue = value;
                        row = i;
                        col = j;
                    }
                }
            }
        }
        board[row][col] = 'O';
        printf("\nAI played on row %d and column %d.\n", row + 1, col + 1);
    }
}

int main() {
    srand(time(NULL));
    printf("\nWelcome to Tic Tac Toe!\n\n");
    printf("Choose the level of difficulty (1-5):\n");
    printf("1 = Easy\n2 = Medium\n3 = Hard\n4 = Expert\n5 = Impossible\n");
    scanf("%d", &maxDepth);
    if (maxDepth < 1 || maxDepth > 5) {
        maxDepth = 1;
    }
    initBoard();
    displayBoard();

    char player = '-';
    int turn = rand() % 2;
    if (turn == 0) {
        printf("\nAI goes first.\n");
        player = 'O';
    }
    else {
        printf("\nYou go first.\n");
        player = 'X';
    }

    while (!gameOver()) {
        makeMove(player);
        displayBoard();
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }

    return 0;
}