//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 5

int main() {
    int numbers[SIZE][SIZE] = {0};
    bool covered[SIZE][SIZE] = {false};
    int target = 1;

    // Randomize numbers in the bingo card
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num = rand() % 25 + 1;
            for (int k = 0; k < j; k++) {
                if (num == numbers[i][k]) {
                    num = rand() % 25 + 1;
                    k = -1;
                }
            }
            numbers[i][j] = num;
        }
    }

    while (true) {
        system("clear");   // clears console screen

        // Display the bingo card
        printf("B   I   N   G   O\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (numbers[i][j] == target) {
                    covered[i][j] = true;
                }
                printf("%2d%s", numbers[i][j], (covered[i][j] ? "x " : "  "));
            }
            printf("\n");
        }

        // Check for a winning card
        // Check rows
        for (int i = 0; i < SIZE; i++) {
            bool rowCovered = true;
            for (int j = 0; j < SIZE; j++) {
                if (!covered[i][j]) {
                    rowCovered = false;
                    break;
                }
            }
            if (rowCovered) {
                printf("BINGO! Row %d completed\n", i+1);
                return 0;
            }
        }

        // Check columns
        for (int j = 0; j < SIZE; j++) {
            bool colCovered = true;
            for (int i = 0; i < SIZE; i++) {
                if (!covered[i][j]) {
                    colCovered = false;
                    break;
                }
            }
            if (colCovered) {
                printf("BINGO! Column %d completed\n", j+1);
                return 0;
            }
        }

        // Check diagonals
        bool diagOneCovered = true;
        bool diagTwoCovered = true;
        for (int i = 0; i < SIZE; i++) {
            if (!covered[i][i]) {
                diagOneCovered = false;
            }
            if (!covered[i][SIZE-i-1]) {
                diagTwoCovered = false;
            }
        }
        if (diagOneCovered) {
            printf("BINGO! Diagonal completed\n");
            return 0;
        }
        if (diagTwoCovered) {
            printf("BINGO! Reverse diagonal completed\n");
            return 0;
        }

        // Prompt user for the next target number
        int input;
        printf("Enter next target number (1-25): ");
        scanf("%d", &input);
        if (input < 1 || input > 25) {
            printf("Invalid input\n");
        } else {
            target = input;
        }
    }

    return 0;
}