//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>

int main() {
    // Set up the game board
    int board[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    // Print the game board
    printf("Game Board:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    // Make a move
    int player = 1; // Player 1 starts
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (board[i][j] == 0) {
                board[i][j] = player;
                player = (player + 1) % 2;
                break;
            }
        }
    }
    
    // Print the updated game board
    printf("Updated Game Board:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    // Check if there is a winner
    if (board[0][0]!= 0 && board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][2] == board[0][3]) {
        printf("Player %d wins!\n", board[0][0]);
    }
    else if (board[0][9]!= 0 && board[0][9] == board[1][9] && board[1][9] == board[2][9] && board[2][9] == board[3][9]) {
        printf("Player %d wins!\n", board[0][9]);
    }
    else if (board[9][0]!= 0 && board[9][0] == board[9][1] && board[9][1] == board[9][2] && board[9][2] == board[9][3]) {
        printf("Player %d wins!\n", board[9][0]);
    }
    else if (board[9][9]!= 0 && board[9][9] == board[9][8] && board[9][8] == board[9][7] && board[9][7] == board[9][6]) {
        printf("Player %d wins!\n", board[9][9]);
    }
    else if (board[0][0]!= 0 && board[0][0] == board[3][0] && board[3][0] == board[6][0] && board[6][0] == board[9][0]) {
        printf("Player %d wins!\n", board[0][0]);
    }
    else if (board[0][9]!= 0 && board[0][9] == board[3][9] && board[3][9] == board[6][9] && board[6][9] == board[9][9]) {
        printf("Player %d wins!\n", board[0][9]);
    }
    else if (board[0][0]!= 0 && board[0][0] == board[4][0] && board[4][0] == board[8][0] && board[8][0] == board[12][0]) {
        printf("Player %d wins!\n", board[0][0]);
    }
    else if (board[0][9]!= 0 && board[0][9] == board[4][9] && board[4][9] == board[8][9] && board[8][9] == board[12][9]) {
        printf("Player %d wins!\n", board[0][9]);
    }
    else if (board[0][0]!= 0 && board[0][0] == board[5][0] && board[5][0] == board[10][0] && board[10][0] == board[15][0]) {
        printf("Player %d wins!\n", board[0][0]);
    }
    else if (board[0][9]!= 0 && board[0][9] == board[5][9] && board[5][9] == board[10][9] && board[10][9] == board[15][9]) {
        printf("Player %d wins!\n", board[0][9]);
    }
    else {
        printf("It's a tie!\n");
    }
    
    return 0;
}