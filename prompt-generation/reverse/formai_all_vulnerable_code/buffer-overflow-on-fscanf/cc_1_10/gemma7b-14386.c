//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 10
#define MAX_ROWS 100

typedef struct CSV_DATA {
    char **data;
    int num_cols;
    int num_rows;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the number of columns and rows
    fscanf(fp, "Number of columns: %d\n", &csv_data->num_cols);
    fscanf(fp, "Number of rows: %d\n", &csv_data->num_rows);

    // Allocate memory for the data
    csv_data->data = malloc(csv_data->num_rows * sizeof(char *) + MAX_COLS);
    for (int i = 0; i < csv_data->num_rows; i++) {
        csv_data->data[i] = malloc(MAX_COLS * sizeof(char));
    }

    // Read the CSV data
    int row = 0;
    while (fscanf(fp, "%s\n", csv_data->data[row]) != EOF) {
        row++;
    }

    fclose(fp);

    return csv_data;
}

int main() {
    char *filename = "test.csv";
    CSV_DATA *csv_data = read_csv(filename);

    // Print the CSV data
    for (int row = 0; row < csv_data->num_rows; row++) {
        for (int col = 0; col < csv_data->num_cols; col++) {
            printf("%s, ", csv_data->data[row][col]);
        }
        printf("\n");
    }

    free(csv_data->data);
    free(csv_data);

    return 0;
}