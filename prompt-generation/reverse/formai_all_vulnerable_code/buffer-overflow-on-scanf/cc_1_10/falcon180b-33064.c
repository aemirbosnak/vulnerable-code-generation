//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DIMENSIONS 100
#define MAX_VALUE 1000000
#define MAX_ALIENS 10000

// Function to generate random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a 2D array
void print_array(int arr[][MAX_DIMENSIONS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Get dimensions from user
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Check if dimensions are valid
    if (rows <= 0 || cols <= 0 || rows > MAX_DIMENSIONS || cols > MAX_DIMENSIONS) {
        printf("Invalid dimensions!\n");
        return 1;
    }

    // Initialize array with random values
    int arr[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand_int(1, MAX_VALUE);
        }
    }

    // Get number of aliens from user
    int num_aliens;
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    // Check if number of aliens is valid
    if (num_aliens <= 0 || num_aliens > MAX_ALIENS) {
        printf("Invalid number of aliens!\n");
        return 1;
    }

    // Initialize alien positions and scores
    int pos_x, pos_y;
    int score = 0;

    // Loop until all aliens are placed or no more can be placed
    while (num_aliens > 0) {
        // Generate random position
        pos_x = rand_int(0, rows - 1);
        pos_y = rand_int(0, cols - 1);

        // Check if position is valid
        if (arr[pos_x][pos_y] == 0) {
            // Place alien and update score
            arr[pos_x][pos_y] = 1;
            score++;
            num_aliens--;
        }
    }

    // Calculate probability of invasion
    float prob = (float)score / (rows * cols);

    // Print results
    printf("Alien Invasion Probability: %.2f%%\n", prob * 100);
    printf("Alien Score: %d\n", score);
    printf("Array:\n");
    print_array(arr, rows, cols);

    return 0;
}