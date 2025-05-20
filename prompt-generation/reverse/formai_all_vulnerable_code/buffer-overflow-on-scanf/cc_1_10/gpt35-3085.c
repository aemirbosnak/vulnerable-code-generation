//FormAI DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Function to print the table
void printTable(int table[10][10], int player1Score, int player2Score, char player1[], char player2[]) {
    int i, j;

    // Print the table
    printf("\n");
    printf("\t\t   %s: %d\n", player1, player1Score);
    printf("\t\t|");
    for (i = 0; i < 10; i++) {
        printf(" %d |", i+1);
    }
    printf("\n\t\t+");
    for (i = 0; i < 10; i++) {
        printf("---+");
    }
    printf("\n");
    for (i = 0; i < 10; i++) {
        printf("\t\t%d|", i+1);
        for (j = 0; j < 10; j++) {
            printf(" %d |", table[i][j]);
        }
        printf("\n\t\t+");
        for (j = 0; j < 10; j++) {
            printf("---+");
        }
        printf("\n");
    }
    printf("\t\t   %s: %d\n", player2, player2Score);
    printf("\n");
}

int main() {
    int table[10][10];
    int i, j;
    int player1Score = 0, player2Score = 0;

    char player1[20], player2[20]; // for the player's name
    printf("Enter Player 1's name: ");
    scanf("%s", &player1); // taking input from user of the player's name

    printf("Enter Player 2's name: ");
    scanf("%s", &player2); // taking input from user of the player's name

    // Set all elements of table to 0
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            table[i][j] = 0;
        }
    }

    int turn = 1;
    int x, y;

    // Game loop
    while (player1Score + player2Score < 100) { // loop until one of the players scores 100 points
        printTable(table, player1Score, player2Score, player1, player2); // print table
        printf("%s's turn:\n", turn == 1 ? player1 : player2);
        printf("Enter X coordinate: ");
        scanf("%d", &x);
        printf("Enter Y coordinate: ");
        scanf("%d", &y);

        // Check if the cell is already occupied
        if (table[x-1][y-1] != 0) {
            printf("The cell is already occupied! Try again.\n");
            continue;
        }

        // Update table
        table[x-1][y-1] = turn;
        if (turn == 1) {
            player1Score++;
        }
        else {
            player2Score++;
        }

        // Switch turns
        if (turn == 1) {
            turn = 2;
        }
        else {
            turn = 1;
        }
    }

    // Game over
    printf("%s wins!\n", player1Score > player2Score ? player1 : player2);

    return 0;
}