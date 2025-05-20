//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random move for AI player
int generateRandomMove(int board[3][3])
{
    int row, col;

    srand(time(NULL)); // seed for random number generator

    row = rand() % 3;
    col = rand() % 3;

    // check if the generated move is valid
    while (board[row][col] != 0) {
        row = rand() % 3;
        col = rand() % 3;
    }

    return (row * 3 + col + 1);
}

// function to print the game board
void printBoard(int board[3][3])
{
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf("\t");

        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            }
            else if (board[i][j] == 1) {
                printf("X");
            }
            else if (board[i][j] == 2) {
                printf("O");
            }

            if (j != 2) {
                printf(" | ");
            }
        }

        printf("\n");

        if (i != 2) {
            printf("\t----------\n");
        }
    }
}

// function to check if the game has ended
int isGameOver(int board[3][3])
{
    // check if there is a winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != 0) {
            return board[i][0];
        }
        else if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != 0) {
            return board[0][i];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0) {
        return board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        return board[0][2];
    }

    // check if the game has ended in a tie
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 0) {
                count++;
            }
        }
    }

    if (count == 9) {
        return 3;
    }

    // game is not over yet
    return 0;
}

int main()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int player = 1;

    printf("Welcome to Tic Tac Toe!\n\n");

    while (1) {
        // print the current board
        printBoard(board);

        // check if the game has ended
        int gameResult = isGameOver(board);

        if (gameResult != 0) {
            if (gameResult == 3) {
                printf("\nGame Over: Tie!\n");
            }
            else {
                printf("\nGame Over: Player %d Wins!\n", gameResult);
            }

            break;
        }

        // get the move from the player
        if (player == 1) {
            int move;

            printf("\nPlayer 1 (X), enter your move (1-9): ");
            scanf("%d", &move);

            // check if the move is valid
            while (move < 1 || move > 9 || board[(move-1)/3][(move-1)%3] != 0) {
                printf("Invalid Move. Please try again: ");
                scanf("%d", &move);
            }

            board[(move-1)/3][(move-1)%3] = 1;
        }
        // generate the move for the AI player
        else {
            int move = generateRandomMove(board);

            printf("\nAI (O) played: %d\n", move);

            board[(move-1)/3][(move-1)%3] = 2;
        }

        // switch to the other player
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}