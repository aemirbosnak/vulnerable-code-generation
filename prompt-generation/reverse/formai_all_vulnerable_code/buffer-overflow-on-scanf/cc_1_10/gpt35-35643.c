//FormAI DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

// The game board
int board[ROWS][COLS];

// The current and previous cell choices
int curr[2] = { -1,-1 };
int prev[2] = { -1,-1 };

// The number of pairs of matched cells
int pairs = 0;

// Function to display the board
void display_board() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            if(i == curr[0] && j == curr[1]) 
                printf("|%d|", board[i][j]);
            else if(i == prev[0] && j == prev[1])
                printf("|%d|", board[i][j]);
            else 
                printf("| |");
        }
        printf("\n");
    }
}

// Function to initialize the game board
void init_board() {
    // Initialize the board with random numbers
    srand(time(NULL));
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            board[i][j] = rand() % 10;
        }
    }
}

// Function to check for a match
int check_match() {
    if(curr[0] == prev[0] && curr[1] == prev[1])
        return 0;
    if(board[curr[0]][curr[1]] == board[prev[0]][prev[1]])
        return 1;
    return 0;
}

int main(void) {
    init_board();
    display_board();
    while(pairs != ROWS * COLS / 2) {
        printf("\nChoose a row and column: ");
        scanf("%d%d", &curr[0], &curr[1]);
        if(curr[0] < 0 || curr[0] >= ROWS || curr[1] < 0 || curr[1] >= COLS) {
            printf("Invalid input. Please enter the row and column indices between 0 and 3.\n");
            continue;
        }
        if(prev[0] == -1 && prev[1] == -1) {
            prev[0] = curr[0];
            prev[1] = curr[1];
        } else {
            display_board();
            if(check_match()) {
                printf("Match found!\n");
                board[curr[0]][curr[1]] = -1;
                board[prev[0]][prev[1]] = -1;
                pairs++;
            } else {
                printf("No match.\n");
            }
            prev[0] = -1;
            prev[1] = -1;
        }
    }
    printf("Congratulations, you won!\n");
    return 0;
}