//Falcon-180B DATASET v1.0 Category: Data mining ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10000
#define MAX_COLS 100

// Function to generate random data
void generate_data(int rows, int cols, int **data) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = rand() % 100;
        }
    }
}

// Function to display data
void display_data(int rows, int cols, int **data) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;

    // Get user input for number of rows and columns
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for data
    int **data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        data[i] = (int *)malloc(cols * sizeof(int));
    }

    // Generate random data
    generate_data(rows, cols, data);

    // Display original data
    printf("Original Data:\n");
    display_data(rows, cols, data);

    // Perform data mining operations here...

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}