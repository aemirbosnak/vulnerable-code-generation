//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 9

char table[TABLE_SIZE][TABLE_SIZE];

void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the table with empty spaces
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            table[i][j] = ' ';
        }
    }

    // Place the players' pieces on the table
    table[0][0] = 'X';
    table[0][2] = 'X';
    table[2][0] = 'X';
    table[2][2] = 'X';
    table[4][0] = 'O';
    table[4][2] = 'O';
    table[6][0] = 'O';
    table[6][2] = 'O';

    // Print the initial table
    printTable();

    // Get the first player's move
    int player1Row, player1Column;
    printf("Player 1, enter your move (row, column): ");
    scanf("%d %d", &player1Row, &player1Column);

    // Place the player's piece on the table
    table[player1Row][player1Column] = 'X';

    // Print the updated table
    printTable();

    // Get the second player's move
    int player2Row, player2Column;
    printf("Player 2, enter your move (row, column): ");
    scanf("%d %d", &player2Row, &player2Column);

    // Place the player's piece on the table
    table[player2Row][player2Column] = 'O';

    // Print the updated table
    printTable();

    // Check if there is a winner
    int winner = checkWinner();

    // Print the winner
    if (winner == 1) {
        printf("Player 1 wins!\n");
    } else if (winner == 2) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}

int checkWinner() {
    // Check if there is a horizontal winner
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != ' ') {
            return (table[i][0] == 'X') ? 1 : 2;
        }
    }

    // Check if there is a vertical winner
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != ' ') {
            return (table[0][i] == 'X') ? 1 : 2;
        }
    }

    // Check if there is a diagonal winner
    if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != ' ') {
        return (table[0][0] == 'X') ? 1 : 2;
    }

    if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != ' ') {
        return (table[0][2] == 'X') ? 1 : 2;
    }

    // No winner yet
    return 0;
}