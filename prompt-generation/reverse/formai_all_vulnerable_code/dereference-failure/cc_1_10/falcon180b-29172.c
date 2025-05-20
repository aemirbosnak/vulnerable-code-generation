//Falcon-180B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;
    int i, j;
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Dynamically allocate memory for the array
    arr = (int **)malloc(rows * sizeof(int *));

    if (arr == NULL) {
        printf("Memory could not be allocated!\n");
        return 0;
    }

    // Dynamically allocate memory for each row
    for (i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));

        if (arr[i] == NULL) {
            printf("Memory could not be allocated!\n");
            return 0;
        }
    }

    // Fill the array with random values
    srand(time(NULL));

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    // Print the array
    printf("\nThe array:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the array
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }

    free(arr);

    return 0;
}