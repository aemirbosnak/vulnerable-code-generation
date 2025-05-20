//FormAI DATASET v1.0 Category: Graph representation ; Style: multivariable
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

int main() {
    int i, j, rows, cols;
    int graph[MAX_ROWS][MAX_COLS];

    // Getting input for the number of rows and columns
    printf("Enter the number of rows in the graph: ");
    scanf("%d", &rows);

    printf("Enter the number of columns in the graph: ");
    scanf("%d", &cols);

    // Getting input for the graph
    printf("Enter the graph matrix:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Printing the graph matrix
    printf("The graph matrix is:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Finding the maximum and minimum values in the graph matrix
    int min_value = graph[0][0];
    int max_value = graph[0][0];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (graph[i][j] < min_value) {
                min_value = graph[i][j];
            }
            if (graph[i][j] > max_value) {
                max_value = graph[i][j];
            }
        }
    }

    // Printing the maximum and minimum values in the graph matrix
    printf("\nThe maximum value in the graph is: %d\n", max_value);
    printf("The minimum value in the graph is: %d\n", min_value);

    // Calculating the average value of the graph matrix
    int total = 0;
    int num_values = rows * cols;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            total += graph[i][j];
        }
    }

    double avg_value = (double) total / num_values;

    // Printing the average value of the graph matrix
    printf("\nThe average value in the graph is: %f\n", avg_value);

    // Finding the location of the maximum value in the graph matrix
    int max_row, max_col;
    max_value = graph[0][0];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (graph[i][j] > max_value) {
                max_value = graph[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    // Printing the location of the maximum value in the graph matrix
    printf("\nThe maximum value in the graph is located at row %d, column %d\n", max_row+1, max_col+1);

    return 0;
}