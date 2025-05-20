//Code Llama-13B DATASET v1.0 Category: Data mining ; Style: scalable
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <time.h>

    #define MAX_ROWS 10000
    #define MAX_COLS 100

    typedef struct {
        int row;
        int col;
        char value;
    } data_t;

    data_t* data;

    int main() {
        int rows = 0;
        int cols = 0;
        int row_index = 0;
        int col_index = 0;
        int value = 0;
        int i = 0;
        int j = 0;

        // Initialize the data array
        data = (data_t*)malloc(MAX_ROWS * MAX_COLS * sizeof(data_t));

        // Read the data from the file
        FILE* file = fopen("data.txt", "r");
        while (fscanf(file, "%d %d %d", &row_index, &col_index, &value) != EOF) {
            data[i].row = row_index;
            data[i].col = col_index;
            data[i].value = value;
            i++;
        }
        fclose(file);

        // Print the data
        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                printf("%d ", data[i * cols + j].value);
            }
            printf("\n");
        }

        // Free the memory
        free(data);

        return 0;
    }