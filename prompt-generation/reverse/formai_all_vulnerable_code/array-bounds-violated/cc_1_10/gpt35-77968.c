//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Function to print the current state of the table
void printTable(char table[][3]) {
    printf("\n");
    // Traverse the 2D array
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", table[i][j]);
        }
        printf("\n");
    }
}

// Function to check if there is a winner or not
int checkWinner(char table[][3]) {
    // Traverse the rows
    for(int i=0; i<3; i++) {
        if((table[i][0] == table[i][1]) && (table[i][1] == table[i][2])) {
            return table[i][0];
        }
    }
    // Traverse the columns
    for(int i=0; i<3; i++) {
        if((table[0][i] == table[1][i]) && (table[1][i] == table[2][i])) {
            return table[0][i];
        }
    }
    // Traverse the diagonals
    if((table[0][0] == table[1][1]) && (table[1][1] == table[2][2])) {
            return table[0][0];
    }
    if((table[0][2] == table[1][1]) && (table[1][1] == table[2][0])) {
            return table[0][2];
    }
    // If none of the above condition satisfies
    return 0;
}

int main() {
    char table[3][3] = {
                        {'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}
                       };
    char player1 = 'X';
    char player2 = 'O';
    int turn = 0; // Turn counter
    int winner = 0; // Keeps track of winner
    
    printf("*** Welcome to the C Table Game! ***\n");
    printf("Here is your starting table:\n");
    printTable(table);
    
    while(turn < 9) {
        int row, col;
        if(turn%2 == 0) {
            printf("Player 1, please select your position(row column): ");
            scanf("%d %d", &row, &col);
            if(table[row-1][col-1] != player1 && table[row-1][col-1] != player2) {
                table[row-1][col-1] = player1;
                turn++;
                printf("\nCurrent table status: \n");
                printTable(table);
                winner = checkWinner(table);
                if(winner == player1) {
                    printf("\nCongratulations Player 1, you have won the game!\n");
                    exit(0);
                }
            } else {
                printf("\nPosition already occupied, please select another position.\n");
            }
        } else {
            printf("Player 2, please select your position(row column): ");
            scanf("%d %d", &row, &col);
            if(table[row-1][col-1] != player1 && table[row-1][col-1] != player2) {
                table[row-1][col-1] = player2;
                turn++;
                printf("\nCurrent table status: \n");
                printTable(table);
                winner = checkWinner(table);
                if(winner == player2) {
                    printf("\nCongratulations Player 2, you have won the game!\n");
                    exit(0);
                }
            } else {
                printf("\nPosition already occupied, please select another position.\n");
            }
        }
    }
    // If the game reaches the nth turn, that means no one wins
    printf("\nIt's a tie! Better luck next time...\n");
    return 0;
}