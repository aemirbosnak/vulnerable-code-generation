//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5 // number of rows in Bingo board
#define COLS 5 // number of columns in Bingo board
#define NUMBERS_PER_LETTER 15 // number of different numbers per letter (B, I, N, G, O)
#define MAX_NUM 75 // maximum number in Bingo game

/* Function to initialize Bingo board with random numbers */
void initialize_board(int board[ROWS][COLS]) {
    int nums[NUMBERS_PER_LETTER] = {0}; // array to track used numbers
    srand(time(NULL)); // seed random number generator

    // loop through each column
    for (int col = 0; col < COLS; col++) {
        // generate random numbers for each letter
        for (int i = 0; i < NUMBERS_PER_LETTER; i++) {
            int num = rand() % MAX_NUM + 1; // generate random number
            // check if number has already been generated
            while (nums[num-1]) {
                num = rand() % MAX_NUM + 1;
            }
            nums[num-1] = 1; // mark number as used
            // assign number to board position
            board[i][col] = num;
        }
    }
    // free memory allocated to nums array
    free(nums);
}

/* Function to print Bingo board */
void print_board(int board[ROWS][COLS]) {
    printf("\nBINGO BOARD\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("   "); // print blank for free space
            } else {
                printf("%2d ", board[i][j]); // print number
            }
        }
        printf("\n");
    }
}

/* Function to check if player has a Bingo */
int check_bingo(int board[ROWS][COLS]) {
    int bingo = 0;
    // check for horizontal Bingo
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1 || board[i][j] == 0) {
                count++;
            }
        }
        if (count == COLS) {
            bingo = 1;
        }
    }
    // check for vertical Bingo
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (board[i][j] == -1 || board[i][j] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            bingo = 1;
        }
    }
    // check for diagonal Bingo (top-left to bottom-right)
    int count = 0;
    for (int i = 0, j = 0; i < ROWS && j < COLS; i++, j++) {
        if (board[i][j] == -1 || board[i][j] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        bingo = 1;
    }
    // check for diagonal Bingo (top-right to bottom-left)
    count = 0;
    for (int i = 0, j = COLS-1; i < ROWS && j >=0; i++, j--) {
        if (board[i][j] == -1 || board[i][j] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        bingo = 1;
    }
    return bingo;
}

int main() {
    int board[ROWS][COLS] = {{0}}; // initialize board with zeros
    initialize_board(board); // generate random numbers for board
    board[2][2] = -1; // mark center square as free space

    printf("Welcome to BINGO!\n");
    printf("Instructions: The program will generate a BINGO board for you.\n");
    printf("You will then be prompted to enter numbers until you get a BINGO or run out of numbers.\n");
    printf("Good luck!\n");

    int num_guesses = 0;
    int bingo = 0;
    int chosen[NUMBERS_PER_LETTER*5] = {0}; // array to track chosen numbers
    // loop until player gets Bingo or runs out of numbers
    while (!bingo && num_guesses < NUMBERS_PER_LETTER*5) {
        int num;
        printf("\nEnter a number (1-75): ");
        scanf("%d", &num);
        while (chosen[num-1]) {
            printf("Number already chosen. Please enter a different number: ");
            scanf("%d", &num);
        }
        chosen[num-1] = 1; // mark number as chosen
        // check if number is on board
        int found = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == num) {
                    board[i][j] = 0; // mark number as found
                    found = 1;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        num_guesses++; // increment number of guesses
        print_board(board); // print updated board
        bingo = check_bingo(board); // check for Bingo
    }
    // print game over message
    if (bingo) {
        printf("\nBINGO!\n");
        printf("You got a Bingo in %d guesses!\n", num_guesses);
    } else {
        printf("\nGame over. You did not get a Bingo.\n");
    }
    
    return 0;
}