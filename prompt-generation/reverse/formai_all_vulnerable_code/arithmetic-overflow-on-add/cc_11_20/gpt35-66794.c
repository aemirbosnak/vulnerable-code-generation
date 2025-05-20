//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j;
    int board[3][3];
    srand(time(NULL));
    
    // initialize board with random numbers:
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = rand() % 10;
        }
    }
    
    // display initial board:
    printf("    1 2 3\n");
    printf("  +-------+\n");
    for (i = 0; i < 3; i++) {
        printf("%d |", i+1);
        for (j = 0; j < 3; j++) {
            printf(" %d", board[i][j]);
        }
        printf(" |\n");
    }
    printf("  +-------+\n");
    
    // game loop:
    int turn_count = 0;
    int player_score = 0;
    int computer_score = 0;
    int row_choice, col_choice;
    while (turn_count < 9) {
        // player turn:
        printf("Your turn: ");
        scanf("%d %d", &row_choice, &col_choice);
        while (board[row_choice-1][col_choice-1] == -1) {
            printf("That spot is already taken, choose again: ");
            scanf("%d %d", &row_choice, &col_choice);
        }
        player_score += board[row_choice-1][col_choice-1];
        board[row_choice-1][col_choice-1] = -1;
        turn_count++;
        
        // check for winner:
        if (player_score >= 15) {
            printf("Congratulations, you win!\n");
            return 0;
        }
        
        // computer turn:
        int computer_row = rand() % 3;
        int computer_col = rand() % 3;
        while (board[computer_row][computer_col] == -1) {
            computer_row = rand() % 3;
            computer_col = rand() % 3;
        }
        computer_score += board[computer_row][computer_col];
        board[computer_row][computer_col] = -1;
        turn_count++;
        
        // check for winner:
        if (computer_score >= 15) {
            printf("Sorry, the computer wins.\n");
            return 0;
        }
        
        // display updated board:
        printf("    1 2 3\n");
        printf("  +-------+\n");
        for (i = 0; i < 3; i++) {
            printf("%d |", i+1);
            for (j = 0; j < 3; j++) {
                if (board[i][j] == -1) {
                    printf(" X");
                } else {
                    printf(" %d", board[i][j]);
                }
            }
            printf(" |\n");
        }
        printf("  +-------+\n");
    }
    
    // tie game:
    printf("Sorry, it's a tie.\n");
    
    return 0;
}