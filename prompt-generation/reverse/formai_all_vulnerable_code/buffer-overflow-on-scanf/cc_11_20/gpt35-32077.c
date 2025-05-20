//FormAI DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the user input is valid
int isValidInput(int input, int limit) {
    if (input < 1 || input > limit) {
        printf("Invalid input! Please try again.\n");
        return 0;
    }
    return 1;
}

int main() {
    
    int table[3][3] = { // Initialize the table with blank squares
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    // Print the game instructions
    printf("Welcome to the Sherlock Holmes Table Game!\n");
    printf("The game is played on a 3x3 square table.\n");
    printf("You are playing as Sherlock Holmes, and Moriarty is your opponent.\n");
    printf("The first player to get three in a row vertically, horizontally, or diagonally wins!\n\n");
    
    // Variables to keep track of the game state
    int turn = 1; // Turn 1: Sherlock's turn, Turn 2: Moriarty's turn
    int gameEnd = 0; // 1: Game ended, 0: Game still ongoing
    
    // Game loop
    while (!gameEnd) {
        
        // Print the current table state
        printf("Current Table:\n");
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                printf("%c ", table[i][j]);
            }
            printf("\n");
        }

        // Get the player's input
        int row, col;
        if (turn == 1) {
            printf("Sherlock's turn. Enter row and column (separated by space): ");
        } else {
            printf("Moriarty's turn. Enter row and column (separated by space): ");
        }
        scanf("%d %d", &row, &col);
        
        // Check if the input is valid
        if (!isValidInput(row, 3) || !isValidInput(col, 3)) { // Check if input is within bounds
            continue;
        }
        if (table[row-1][col-1] != ' ') { // Check if square is already occupied
            printf("That square is already occupied! Please try again.\n");
            continue;
        }
        
        // Update the table
        if (turn == 1) {
            table[row-1][col-1] = 'X'; // Sherlock's symbol is X
        } else {
            table[row-1][col-1] = 'O'; // Moriarty's symbol is O
        }
        
        // Check if the game has ended
        int hasWon = 0;
        for (int i=0; i<3; i++) { // Check rows
            if (table[i][0] == table[i][1] && table[i][1] == table[i][2] && table[i][0] != ' ') {
                hasWon = 1;
                break;
            }
        }
        if (!hasWon) {
            for (int i=0; i<3; i++) { // Check columns
                if (table[0][i] == table[1][i] && table[1][i] == table[2][i] && table[0][i] != ' ') {
                    hasWon = 1;
                    break;
                }
            }
        }
        if (!hasWon) { // Check diagonals
            if (table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != ' ') {
                hasWon = 1;
            } else if (table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != ' ') {
                hasWon = 1;
            }
        }
        if (hasWon) { // End the game if someone has won
            printf("Congratulations! ");
            if (turn == 1) {
                printf("Sherlock wins!\n");
            } else {
                printf("Moriarty wins!\n");
            }
            gameEnd = 1;
        } else { // Move on to the next turn
            turn = turn == 1 ? 2 : 1;
            printf("\n");
        }
        
        // Check if the game ended in a tie
        int isTie = 1;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (table[i][j] == ' ') {
                    isTie = 0;
                    break;
                }
            }
            if (!isTie) {
                break;
            }
        }
        if (isTie) { // End the game if it's a tie
            printf("It's a tie!\n");
            gameEnd = 1;
        }
        
    }

    return 0;
}