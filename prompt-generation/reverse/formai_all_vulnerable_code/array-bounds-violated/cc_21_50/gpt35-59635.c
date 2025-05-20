//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 5

int main() {
    int board[SIZE][SIZE];
    bool marked[SIZE][SIZE];

    // Initialize board with random numbers between 1 and 25
    srand(time(NULL));
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            int num = rand() % 25 + 1;
            board[i][j] = num;

            // Check for duplicates in column
            for(int k=0; k<i; k++) {
                if(board[k][j] == num) {
                    i--;
                    break;
                }
            }

            // Check for duplicates in row
            for(int k=0; k<j; k++) {
                if(board[i][k] == num) {
                    i--;
                    break;
                }
            }
        }
    }

    // Initialize marked array to false
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            marked[i][j] = false;
        }
    }

    // Print board
    printf("Welcome to Bingo Simulator! Here is your board:\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }

    // Play game!
    int count = 0;
    while(count < SIZE*SIZE) {
        int num = rand() % 25 + 1;
        printf("\nDrawing number: %d\n", num);

        // Mark numbers on board
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                if(board[i][j] == num) {
                    marked[i][j] = true;
                    count++;
                }
            }
        }

        // Print marked board
        printf("Here is your updated board:\n");
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                if(marked[i][j]) {
                    printf("X\t");
                } else {
                    printf("%d\t", board[i][j]);
                }
            }
            printf("\n");
        }

        // Check for winner
        bool winner = false;
        for(int i=0; i<SIZE; i++) {
            // Check rows
            bool row = true;
            for(int j=0; j<SIZE; j++) {
                if(!marked[i][j]) {
                    row = false;
                    break;
                }
            }
            if(row) {
                printf("Bingo! Row %d\n", i+1);
                winner = true;
                break;
            }

            // Check columns
            bool column = true;
            for(int j=0; j<SIZE; j++) {
                if(!marked[j][i]) {
                    column = false;
                    break;
                }
            }
            if(column) {
                printf("Bingo! Column %d\n", i+1);
                winner = true;
                break;
            }
        }

        // Check diagonal
        bool diagonal1 = true;
        bool diagonal2 = true;
        for(int i=0; i<SIZE; i++) {
            if(!marked[i][i]) {
                diagonal1 = false;
            }
            if(!marked[i][SIZE-i-1]) {
                diagonal2 = false;
            }
        }
        if(diagonal1) {
            printf("Bingo! Diagonal (top left to bottom right)\n");
            winner = true;
        }
        if(diagonal2) {
            printf("Bingo! Diagonal (top right to bottom left)\n");
            winner = true;
        }

        if(winner) {
            printf("Congratulations, you have won!\n");
            break;
        }
    }
    if(count == SIZE*SIZE) {
        printf("Game over, no more numbers left to draw.\n");
    }

    return 0;
}