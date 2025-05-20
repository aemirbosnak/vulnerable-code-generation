//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Board size
#define N 3

// Player types
#define HUMAN 1
#define AI 2
#define EMPTY 0

// Function to check if a player has won
int check_win(int board[N][N], int player) {
    // Check rows
    for (int i = 0; i < N; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < N; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Function to get the best move for the AI
int get_best_move(int board[N][N], int player) {
    // Get all possible moves
    int moves[N * N];
    int num_moves = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == EMPTY) {
                moves[num_moves++] = i * N + j;
            }
        }
    }

    // Evaluate each move
    int best_move = -1;
    int best_score = -1000;
    for (int i = 0; i < num_moves; i++) {
        // Make the move
        int move = moves[i];
        int row = move / N;
        int col = move % N;
        board[row][col] = player;

        // Check if the move is a winning move
        int score = check_win(board, player);

        // Undo the move
        board[row][col] = EMPTY;

        // Update the best move if the move is a winning move or if the score is better
        if (score > best_score) {
            best_move = move;
            best_score = score;
        }
    }

    return best_move;
}

// Function to play the game
void play_game() {
    // Create the game board
    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = EMPTY;
        }
    }

    // Choose who goes first
    int turn = HUMAN;
    if (rand() % 2 == 0) {
        turn = AI;
    }

    // Play the game
    while (1) {
        // Get the player's move
        int move;
        if (turn == HUMAN) {
            printf("Enter your move (row, col): ");
            scanf("%d %d", &move, &move);
        } else {
            move = get_best_move(board, AI);
        }

        // Make the move
        int row = move / N;
        int col = move % N;
        board[row][col] = turn;

        // Check if the game is over
        int winner = check_win(board, turn);
        if (winner == HUMAN) {
            printf("You win!\n");
            break;
        } else if (winner == AI) {
            printf("I win!\n");
            break;
        } else if (check_win(board, EMPTY) == 0) {
            printf("Tie!\n");
            break;
        }

        // Switch turns
        turn = turn == HUMAN ? AI : HUMAN;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}