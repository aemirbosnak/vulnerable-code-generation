//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define CENTER 13

void print_board(int board[][COLS], int called[]);
void check_bingo(int board[][COLS], int called[]);
void call_number(int board[][COLS], int called[]);
void delay();

int main() {
    // Initialize board and randomly assign numbers
    int board[ROWS][COLS] = {0};
    int num = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS / 2 && j == COLS / 2) {
                board[i][j] = CENTER;
            } else {
                board[i][j] = num;
                num++;
            }
        }
    }

    // Initialize list of called numbers
    int called[ROWS * COLS] = {0};
    int index = 0;

    // Print initial board and call first number
    print_board(board, called);
    call_number(board, called);

    // Continuously call numbers until there is a bingo
    while (1) {
        check_bingo(board, called);
        call_number(board, called);
        delay();
    }

    return 0;
}

// Print current state of bingo board
void print_board(int board[][COLS], int called[]) {
    system("clear");
    printf("BINGO BOARD\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (called[board[i][j]] == 1) {
                printf("| X ");
            } else {
                printf("| %2d", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\n");
}

// Check to see if there is a bingo
void check_bingo(int board[][COLS], int called[]) {
    int count;
    
    // Check rows for bingo
    for (int i = 0; i < ROWS; i++) {
        count = 0;
        for (int j = 0; j < COLS; j++) {
            if (called[board[i][j]] == 1) {
                count++;
            }
        }
        if (count == COLS) {
            printf("BINGO! ROW %d\n", i+1);
            exit(0);
        }
    }

    // Check columns for bingo
    for (int j = 0; j < COLS; j++) {
        count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (called[board[i][j]] == 1) {
                count++;
            }
        }
        if (count == ROWS) {
            printf("BINGO! COLUMN %d\n", j+1);
            exit(0);
        }
    }

    // Check diagonal from top left to bottom right for bingo
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        if (called[board[i][i]] == 1) {
            count++;
        }
    }
    if (count == ROWS) {
        printf("BINGO! DIAGONAL TOP LEFT TO BOTTOM RIGHT\n");
        exit(0);
    }

    // Check diagonal from bottom left to top right for bingo
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        int j = COLS - 1 - i;
        if (called[board[i][j]] == 1) {
            count++;
        }
    }
    if (count == ROWS) {
        printf("BINGO! DIAGONAL BOTTOM LEFT TO TOP RIGHT\n");
        exit(0);
    }
}

// Call a random number and mark it as called
void call_number(int board[][COLS], int called[]) {
    int num;
    do {
        num = rand() % (ROWS * COLS) + 1;
    } while (called[num] == 1);
    called[num] = 1;
    printf("Number called: %d\n", num);
}

// Delay the program for one second
void delay() {
    time_t start = time(NULL);
    time_t end = start + 1;
    while (time(NULL) < end);
}