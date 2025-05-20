//FormAI DATASET v1.0 Category: Table Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program creates a surreal C Table Game that is both confusing and fun at the same time */

int main() {

    srand(time(NULL)); // seed the random generator

    int board[4][4] = {0}; // create the board, initialize to all 0's

    printf("Welcome to the C Table Game!\n");
    printf("The goal is to fill the board with numbers from 1 to 16.\n");
    printf("But beware, the numbers will keep shifting around randomly!\n");
    printf("Press enter to start.\n");
    getchar(); // wait for user to press enter

    int done = 0; // flag to indicate if game is finished

    while (!done) {

        system("clear"); // clear the screen

        // print the board
        printf("---------------\n");
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                printf("| %2d ", board[row][col]);
            }
            printf("|\n");
            printf("---------------\n");
        }

        // check if game is finished
        int count = 1;
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (board[row][col] != count) {
                    done = 0;
                    break;
                }
                else {
                    done = 1;
                }
                count++;
            }
        }
        if (done) {
            printf("Congratulations, you have won!\n");
            break;
        }

        // randomly select a position to move the number
        int row = rand() % 4;
        int col = rand() % 4;

        // randomly select a direction (up, down, left, right)
        int dir = rand() % 4;

        // move the number in the selected direction
        switch (dir) {
            case 0: // up
                if (row > 0) {
                    board[row][col] = board[row-1][col];
                    board[row-1][col] = 0;
                }
                break;
            case 1: // down
                if (row < 3) {
                    board[row][col] = board[row+1][col];
                    board[row+1][col] = 0;
                }
                break;
            case 2: // left
                if (col > 0) {
                    board[row][col] = board[row][col-1];
                    board[row][col-1] = 0;
                }
                break;
            case 3: // right
                if (col < 3) {
                    board[row][col] = board[row][col+1];
                    board[row][col+1] = 0;
                }
                break;
        }

        // wait for a moment before moving on to next iteration
        clock_t start_time = clock();
        while (clock() < start_time + 500000) {}
    }

    return 0;
}