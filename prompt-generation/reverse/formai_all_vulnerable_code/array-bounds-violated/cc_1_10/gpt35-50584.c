//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Function that reads in rows of a CSV file and returns a two-dimensional array*/
char** read_csv(char* filename, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        *rows = 0;
        *cols = 0;
        return NULL;
    }

    int row_size = 1024; //initial row size
    int max_rows = 1024; //initial max rows
    char** data = (char**)malloc(max_rows * sizeof(char*));
    char line[row_size];

    *rows = 0;
    *cols = 0;

    while (fgets(line, row_size, file)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') line[--len] = '\0'; //remove newline character
        char* token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            if (*rows == 0) (*cols)++; //count number of columns in first row
            if (col >= *cols) break; //ignore columns after the first row that exceed the number of columns in the first row
            if (*rows >= max_rows) { //expand rows if necessary
                max_rows *= 2;
                data = (char**)realloc(data, max_rows * sizeof(char*));
            }
            if (col == 0) data[*rows] = (char*)malloc(row_size * sizeof(char)); //allocate memory for row
            strcpy(data[*rows] + col * row_size, token); //store value in row
            col++;
            token = strtok(NULL, ","); //get next value in row
        }
        (*rows)++;
    }

    fclose(file);

    return data;
}

int main() {
    int rows, cols;
    char** data = read_csv("data.csv", &rows, &cols);

    if (data) {
        printf("Rows: %d, Cols: %d\n", rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%s, ", data[i] + j * 1024);
            }
            printf("\n");
        }
    }

    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}