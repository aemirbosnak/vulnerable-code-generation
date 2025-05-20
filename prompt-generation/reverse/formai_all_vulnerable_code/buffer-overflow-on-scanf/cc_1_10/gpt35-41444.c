//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current table
void printTable(int table[]) {
    printf("Current Table:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", table[i]);
        if ((i+1) % 3 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to check if there is a winner
int checkWin(int table[]) {
    // Check for horizontal wins
    for (int row = 0; row < 9; row += 3) {
        if (table[row] == table[row+1] && table[row] == table[row+2]) {
            return table[row];
        }
    }
    // Check for vertical wins
    for (int col = 0; col < 3; col++) {
        if (table[col] == table[col+3] && table[col] == table[col+6]) {
            return table[col];
        }
    }
    // Check for diagonal wins
    if (table[0] == table[4] && table[0] == table[8]) {
        return table[0];
    }
    if (table[2] == table[4] && table[2] == table[6]) {
        return table[2];
    }
    // No winner yet
    return 0;
}

int main() {
    int table[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int player = 1;
    int input;
    int winner = 0;
    srand(time(NULL));

    // Print the current table
    printTable(table);

    // Main game loop
    while (winner == 0) {
        // Get input from the current player
        printf("Player %d's turn: ", player);
        scanf("%d", &input);

        // Check if the input is valid
        if (input < 1 || input > 9) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        if (table[input-1] == 'X' || table[input-1] == 'O') {
            printf("That spot is already taken. Please try again.\n");
            continue;
        }

        // Update the table
        if (player == 1) {
            table[input-1] = 'X';
        }
        else {
            table[input-1] = 'O';
        }

        // Print the updated table
        printTable(table);

        // Check for a winner
        winner = checkWin(table);

        // Switch to the other player
        if (player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }

        // If there is no more empty slot
        if(winner==0){
            int full=1;
            for(int i=0;i<9;i++){
                if(table[i]!='X' && table[i]!='O'){
                    full=0;
                    break;
                }
            }
            if(full==1){
                printf("Game is over. Both player lose. Better luck next time.\n");
                break;
            }
        }       
    }

    // Print the winner
    if (winner == 'X') {
        printf("Player 1 wins!\n");
    }
    else if (winner == 'O') {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Game is over. It's a tie!\n");
    }

    return 0;
}