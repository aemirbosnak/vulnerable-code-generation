//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000 // maximum number of rows in the CSV file
#define MAX_COLS 1000 // maximum number of columns in the CSV file
#define MAX_CELL_SIZE 1000 // maximum size of a cell in the CSV file

typedef struct {
    char **data; // pointer to a 2D array of strings
    int rows; // number of rows in the CSV file
    int cols; // number of columns in the CSV file
} CSV;

CSV *read_csv(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (col >= MAX_COLS) {
                printf("Error: too many columns in row %d\n", row + 1);
                exit(1);
            }
            csv->data[row] = realloc(csv->data[row], (col + 1) * sizeof(char *));
            csv->data[row][col] = strdup(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    csv->rows = row;
    csv->cols = col;

    return csv;
}

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void free_csv(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    CSV *csv = read_csv(file);
    print_csv(csv);

    free_csv(csv);
    fclose(file);

    return 0;
}