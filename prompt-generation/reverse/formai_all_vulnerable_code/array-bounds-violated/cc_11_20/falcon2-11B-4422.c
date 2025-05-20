//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    printf("Welcome to the C Bingo Simulator!\n\n");

    // Initialize the Bingo board
    int board[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Create a list of possible numbers to be drawn
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

    // Generate random numbers to be drawn
    for (int i = 0; i < 25; i++) {
        int drawnNumber = numbers[rand() % 100];
        printf("%d ", drawnNumber);
        board[drawnNumber - 1][i] = 1;
    }

    printf("\n");

    // Check for Bingo
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 5) {
                count++;
                printf("%d ", count);
            }
        }
        printf("\n");
    }

    printf("\n");

    // Print the Bingo board
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 0) {
                printf("- ");
            } else if (board[i][j] == 1) {
                printf("1 ");
            } else if (board[i][j] == 2) {
                printf("2 ");
            } else if (board[i][j] == 3) {
                printf("3 ");
            } else if (board[i][j] == 4) {
                printf("4 ");
            } else if (board[i][j] == 5) {
                printf("5 ");
            } else {
                printf("Error ");
            }
        }
        printf("\n");
    }

    return 0;
}