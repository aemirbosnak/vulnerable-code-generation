//FormAI DATASET v1.0 Category: Memory Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the array
void shuffle(int* array, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    printf("***Welcome to the C Memory Game!***\n\n");
    printf("Type in your name to begin: ");
    char name[20];
    scanf("%s", name);
    printf("\nHello %s, let's get started!\n", name);

    int size = 4;
    int matrix[4][4];
    int nums[16];

    // Generate an array with the numbers 1-8 twice
    for (int i = 0; i < 8; i++) {
        nums[i] = i + 1;
        nums[i + 8] = i + 1;
    }

    // Shuffle the array
    shuffle(nums, 16);

    // Fill the matrix with shuffled numbers
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = nums[k];
            k++;
        }
    }

    int score = 0;
    int pairs = 0;

    while (pairs < 8) {
        // Display the matrix
        printf("\nCurrent Score: %d\n", score);
        printf("-----------------\n");
        for (int i = 0; i < size; i++) {
            printf("| ");
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == -1) {
                    printf("  ");
                } else {
                    printf("%d ", matrix[i][j]);
                }
            }
            printf("|\n");
        }
        printf("-----------------\n");

        // Get user input
        int row1, col1, row2, col2;
        printf("Enter the row and column of the first card (separated by a space): ");
        scanf("%d%d", &row1, &col1);
        printf("Enter the row and column of the second card (separated by a space): ");
        scanf("%d%d", &row2, &col2);

        // Check if cards match
        if (matrix[row1][col1] == matrix[row2][col2]) {
            printf("You found a pair!\n");
            matrix[row1][col1] = -1;
            matrix[row2][col2] = -1;
            pairs++;
            score += 10;
        } else {
            printf("Sorry, those cards don't match.\n");
            score -= 2;
        }
    }

    printf("\nCongratulations, you found all the pairs!\n");
    printf("Final Score: %d\n", score);
    return 0;
}