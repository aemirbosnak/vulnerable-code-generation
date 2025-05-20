//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program demonstrates matrix operations using dynamic memory allocation
// This program also has a "shape shifting" feature, where the user can modify the shape of the matrix during runtime

int main() {
    int rows = 3; // default rows of matrix
    int cols = 3; // default columns of matrix
    
    srand(time(NULL)); // seed random number generator with current time
    
    // generate the initial matrix
    int **matrix = malloc(rows * sizeof(int*)); 
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int)); 
    }
    
    // populate the matrix with random numbers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // print the initial matrix
    printf("Initial Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int choice;
    
    do {
        // menu for shape shifting operations
        printf("\nSelect an operation:\n");
        printf("1. Add a row\n");
        printf("2. Add a column\n");
        printf("3. Remove a row\n");
        printf("4. Remove a column\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                rows++; 
                matrix = realloc(matrix, rows * sizeof(int*)); // add a row to the matrix
                matrix[rows-1] = calloc(cols, sizeof(int)); // initialize the new row to 0
                printf("Row added!\n");
                break;
            case 2:
                cols++;
                for (int i = 0; i < rows; i++) {
                    matrix[i] = realloc(matrix[i], cols * sizeof(int)); // add a column to each row of the matrix
                    matrix[i][cols-1] = 0; // initialize the new column to 0
                }
                printf("Column added!\n");
                break;
            case 3:
                if (rows == 1) {
                    printf("Cannot remove row! Matrix must have at least one row.\n");
                }
                else {
                    rows--;
                    free(matrix[rows]); // remove the last row of the matrix
                    matrix = realloc(matrix, rows * sizeof(int*));
                    printf("Row removed!\n");
                }
                break;
            case 4:
                if (cols == 1) {
                    printf("Cannot remove column! Matrix must have at least one column.\n");
                }
                else {
                    cols--;
                    for (int i = 0; i < rows; i++) {
                        matrix[i] = realloc(matrix[i], cols * sizeof(int)); // remove the last column from each row of the matrix
                    }
                    printf("Column removed!\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
        
        // print the modified matrix
        printf("Modified Matrix:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    } while(choice != 5);
    
    // free memory allocated for matrix
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}