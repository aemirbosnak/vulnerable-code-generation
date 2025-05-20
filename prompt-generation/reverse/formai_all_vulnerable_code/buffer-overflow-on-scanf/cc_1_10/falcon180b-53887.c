//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int rand_num() {
    return rand() % 100;
}

// Function to print the game board
void print_board(int board[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check for a win condition
int check_win(int board[3][3]) {
    // Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return 1;
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));

    // Initialize game board
    int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

    // Loop until game is won
    while(1) {
        // Print game board
        print_board(board);

        // Get player input
        int choice;
        printf("Enter your move (0-8): ");
        scanf("%d", &choice);

        // Check if input is valid
        if(choice < 0 || choice > 8) {
            printf("Invalid move!\n");
            continue;
        }

        // Check if game is won
        if(check_win(board)) {
            printf("Congratulations! You win!\n");
            break;
        }

        // Check if game is a tie
        int count = 0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 0) {
                    count++;
                }
            }
        }
        if(count == 0) {
            printf("Game is a tie!\n");
            break;
        }

        // Update game board
        board[choice/3][choice%3] = 1;
    }

    return 0;
}