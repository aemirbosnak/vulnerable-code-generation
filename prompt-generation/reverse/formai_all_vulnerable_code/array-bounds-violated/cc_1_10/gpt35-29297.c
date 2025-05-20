//FormAI DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

char board[ROWS][COLS];
char hidden_board[ROWS][COLS];
char symbols[] = "*#$%&@!^";
int score = 0;

// This function displays the game board
void display_board() {
    int i, j;
    
    printf("\n");
    printf("  BOARD     HIDDEN BOARD\n\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("   %c\t", board[i][j]);
        }
        printf("\t");
        for(j = 0; j < COLS; j++) {
            printf("   %c\t", hidden_board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// This function initializes the game board with random symbols
void set_board() {
    int i, j, index;
    
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            index = rand() % 7;
            board[i][j] = symbols[index];
            hidden_board[i][j] = '_';
        }
    }
}

// This function checks if two selected cells match
int is_match(int r1, int c1, int r2, int c2) {
    if(board[r1][c1] == board[r2][c2]) {
        return 1;
    }
    return 0;
}

// This function updates the hidden board and score after a successful match
void update_board(int r1, int c1, int r2, int c2) {
    hidden_board[r1][c1] = board[r1][c1];
    hidden_board[r2][c2] = board[r2][c2];
    score += 10;
}

// This function plays the game
void play_game() {
    int r1, c1, r2, c2, moves = 0;
    
    while(score < 80) {
        printf("Enter row and column numbers separated by space (ex: 1 2): ");
        scanf("%d %d", &r1, &c1);
        printf("Enter row and column numbers separated by space (ex: 1 2): ");
        scanf("%d %d", &r2, &c2);
        
        if(is_match(r1, c1, r2, c2)) {
            printf("You found a match!\n");
            update_board(r1, c1, r2, c2);
            display_board();
        } else {
            printf("Sorry, try again.\n");
            display_board();
        }
        moves++;
    }
    
    printf("Congratulations, you won in %d moves!", moves);
}

int main() {
    srand(time(NULL));
    set_board();
    display_board();
    play_game();
    
    return 0;
}