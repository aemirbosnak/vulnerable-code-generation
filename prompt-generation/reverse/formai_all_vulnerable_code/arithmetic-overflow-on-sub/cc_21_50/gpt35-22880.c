//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[3][3] = {0};  // Initialize the board with all zeros
    int player = 1;  // Player 1 starts the game
    int row, col;
    int moves = 0;  // Keep track of the number of moves

    srand(time(NULL));  // Seed the random number generator

    printf("Welcome to Tic-Tac-Toe!\n");

    // Display the initial board
    printf("\n   1   2   3\n");
    printf("1  - | - | -\n");
    printf("  ---|---|---\n");
    printf("2  - | - | -\n");
    printf("  ---|---|---\n");
    printf("3  - | - | -\n\n");

    while (moves < 9) {  // Loop until the board is full
        printf("Player %d's turn:\n", player);

        // Generate a random move for the computer player (player 2)
        if (player == 2) {
            do {
                row = rand() % 3;
                col = rand() % 3;
            } while (board[row][col] != 0);  // Keep generating random moves until an empty square is found
        }
        else {  // Ask the human player to enter their move
            do {
                printf("Enter the row and column numbers (separated by a space): ");
                scanf("%d %d", &row, &col);
                row--;  // Adjust the row and column numbers to match the indexing of the board array
                col--;
            } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != 0);  // Check if the move is within the bounds of the board and the square is empty
        }

        if (player == 1) {  // Player 1's turn
            board[row][col] = 1;
        }
        else {  // Player 2's turn
            board[row][col] = -1;
        }
        
        moves++;  // Increment the number of moves

        // Display the updated board
        printf("\n   1   2   3\n");
        printf("1 ");
        if (board[0][0] == 1) {
            printf("X");
        }
        else if (board[0][0] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf(" | ");
        if (board[0][1] == 1) {
            printf("X");
        }
        else if (board[0][1] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf(" | ");
        if (board[0][2] == 1) {
            printf("X");
        }
        else if (board[0][2] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf("\n  ---|---|---\n");
        printf("2 ");
        if (board[1][0] == 1) {
            printf("X");
        }
        else if (board[1][0] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf(" | ");
        if (board[1][1] == 1) {
            printf("X");
        }
        else if (board[1][1] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf(" | ");
        if (board[1][2] == 1) {
            printf("X");
        }
        else if (board[1][2] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf("\n  ---|---|---\n");
        printf("3 ");
        if (board[2][0] == 1) {
            printf("X");
        }
        else if (board[2][0] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf(" | ");
        if (board[2][1] == 1) {
            printf("X");
        }
        else if (board[2][1] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf(" | ");
        if (board[2][2] == 1) {
            printf("X");
        }
        else if (board[2][2] == -1) {
            printf("O");
        }
        else {
            printf("-");
        }
        printf("\n\n");

        // Check if either player has won
        if (board[0][0] + board[0][1] + board[0][2] == 3 || board[1][0] + board[1][1] + board[1][2] == 3 || board[2][0] + board[2][1] + board[2][2] == 3 ||
            board[0][0] + board[1][0] + board[2][0] == 3 || board[0][1] + board[1][1] + board[2][1] == 3 || board[0][2] + board[1][2] + board[2][2] == 3 ||
            board[0][0] + board[1][1] + board[2][2] == 3 || board[0][2] + board[1][1] + board[2][0] == 3) {
            printf("Player 1 wins!\n");
            break;
        }
        else if (board[0][0] + board[0][1] + board[0][2] == -3 || board[1][0] + board[1][1] + board[1][2] == -3 || board[2][0] + board[2][1] + board[2][2] == -3 ||
                 board[0][0] + board[1][0] + board[2][0] == -3 || board[0][1] + board[1][1] + board[2][1] == -3 || board[0][2] + board[1][2] + board[2][2] == -3 ||
                 board[0][0] + board[1][1] + board[2][2] == -3 || board[0][2] + board[1][1] + board[2][0] == -3) {
            printf("Player 2 wins!\n");
            break;
        }

        // Switch to the other player's turn
        if (player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }
    }

    if (moves == 9) {  // If all squares are filled and no one has won, it's a tie
        printf("It's a tie!\n");
    }

    return 0;
}