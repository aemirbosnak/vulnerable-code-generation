//FormAI DATASET v1.0 Category: Table Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void printTable(int arr[][3]);
void playerTurn(int arr[][3], int player);
int checkWinner(int arr[][3]);

int main()
{
    int arr[3][3] = {0}; // initializing 3x3 table with 0's
    int player = 1; // player 1 starts the game
    int winner = 0; // winner status, initially 0

    srand(time(NULL)); // seeding the random function with current time

    printf("Welcome to the C Table Game!\n");
    printf("Instructions: Players take turns placing X's and O's on the table.\n");
    printf("The first player to get three in a row (horizontally, vertically, or diagonally) wins!\n");
    printf("Player 1 is X and Player 2 is O.\n");

    // print the initial table
    printTable(arr);

    // game loop
    while (winner == 0) {
        // player's turn
        playerTurn(arr, player);

        // check if there is a winner
        winner = checkWinner(arr);

        // switch to the other player
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }

    // print the final table
    printTable(arr);

    // print the winner
    if (winner == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}

// function to print the table
void printTable(int arr[][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0) {
                printf("_ ");
            } else if (arr[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function for player's turn
void playerTurn(int arr[][3], int player)
{
    int row, col;

    // repeat until a valid move is made
    while (1) {
        printf("Player %d's turn: \n", player);
        printf("Row (1-3): ");
        scanf("%d", &row);
        printf("Column (1-3): ");
        scanf("%d", &col);

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input!\n");
        } else if (arr[row-1][col-1] != 0) {
            printf("That spot is already taken!\n");
        } else {
            arr[row-1][col-1] = player;
            break;
        }
    }
}

// function to check for a winner
int checkWinner(int arr[][3])
{
    // check horizontally
    for (int i = 0; i < 3; i++) {
        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != 0) {
            return arr[i][0];
        }
    }

    // check vertically
    for (int i = 0; i < 3; i++) {
        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != 0) {
            return arr[0][i];
        }
    }

    // check diagonally
    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != 0) {
        return arr[0][0];
    }
    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != 0) {
        return arr[0][2];
    }

    // check if there is a tie
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    if (count == 9) {
        return -1; // tie
    }

    return 0; // no winner yet
}