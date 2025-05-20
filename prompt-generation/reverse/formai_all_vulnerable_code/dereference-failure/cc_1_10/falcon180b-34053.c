//Falcon-180B DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_ROWS 100
#define MAX_NUM_COLS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_rows;
    int num_cols;
    int **data;
} Table;

int main() {
    // Create a table
    Table my_table = {"my_table", 3, 3, NULL};
    my_table.data = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        my_table.data[i] = (int *)malloc(3 * sizeof(int));
    }

    // Populate the table
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            my_table.data[i][j] = i + j;
        }
    }

    // Print the table
    printf("Table:\n");
    for (int i = 0; i < my_table.num_rows; i++) {
        for (int j = 0; j < my_table.num_cols; j++) {
            printf("%d ", my_table.data[i][j]);
        }
        printf("\n");
    }

    // Query the table
    int sum = 0;
    for (int i = 0; i < my_table.num_rows; i++) {
        for (int j = 0; j < my_table.num_cols; j++) {
            sum += my_table.data[i][j];
        }
    }
    printf("Sum of all elements: %d\n", sum);

    // Free memory
    for (int i = 0; i < my_table.num_rows; i++) {
        free(my_table.data[i]);
    }
    free(my_table.data);
    free(my_table.name);

    return 0;
}