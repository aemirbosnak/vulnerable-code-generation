//FormAI DATASET v1.0 Category: Memory Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 4

int main() {
    int arr[ROWS][COLS] = {0}; //initialize all values to zero
    int i, j, count = 1;

    //insert random values from 1 to 6 in array
    srand(time(0));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int r = rand() % 6 + 1;
            arr[i][j] = r;
        }
    }

    printf("Welcome to Memory Game!\n");
    printf("*************************\n");

    //display the game grid
    printf("      ");
    for (j = 0; j < COLS; j++) {
        printf("COL%d   ", j+1);
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("ROW%d  ", i+1);
        for (j = 0; j < COLS; j++) {
            printf("%d      ", arr[i][j]);
        }
        printf("\n");
    }

    //play the game
    int selection[2] = {0}; //array to store selected coordinates
    while (1) {
        printf("\nEnter the first card coordinates (ROW COL): ");
        scanf("%d %d", &selection[0], &selection[1]);

        if (selection[0] < 1 || selection[0] > ROWS || selection[1] < 1 || selection[1] > COLS) {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }

        int row1 = selection[0]-1, col1 = selection[1]-1;
        if (arr[row1][col1] == 0) {
            printf("Card already matched! Try again.\n");
            continue;
        }

        printf("Enter the second card coordinates (ROW COL): ");
        scanf("%d %d", &selection[0], &selection[1]);

        if (selection[0] < 1 || selection[0] > ROWS || selection[1] < 1 || selection[1] > COLS) {
            printf("Invalid coordinates! Try again.\n");
            continue;
        }

        int row2 = selection[0]-1, col2 = selection[1]-1;
        if (arr[row2][col2] == 0) {
            printf("Card already matched! Try again.\n");
            continue;
        }

        //check if the selected cards are a match
        if (arr[row1][col1] == arr[row2][col2]) {
            printf("You found a match! Good job!\n");
            arr[row1][col1] = 0; //mark as matched
            arr[row2][col2] = 0; //mark as matched
        }
        else {
            printf("Sorry, try again!\n");
        }

        //check if all cards are matched
        count = 0;
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (arr[i][j] != 0) {
                    count++;
                }
            }
        }
        if (count == 0) {
            printf("\nCongratulations, you have matched all cards! Play again?\n");
            break;
        }
    }

    return 0;
}