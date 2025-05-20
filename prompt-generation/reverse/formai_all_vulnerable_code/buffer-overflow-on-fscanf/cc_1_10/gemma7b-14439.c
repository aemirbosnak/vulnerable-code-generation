//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

int main() {
    char **csv_data = NULL;
    int num_rows = 0;
    int num_cols = 0;
    FILE *csv_file = NULL;

    // Open the CSV file
    csv_file = fopen("data.csv", "r");
    if (csv_file == NULL) {
        return EXIT_FAILURE;
    }

    // Read the number of rows and columns
    fscanf(csv_file, "%d, %d", &num_rows, &num_cols);

    // Allocate memory for the CSV data
    csv_data = (char**)malloc(num_rows * sizeof(char*));
    for (int r = 0; r < num_rows; r++) {
        csv_data[r] = (char*)malloc(num_cols * sizeof(char));
    }

    // Read the CSV data
    int i = 0;
    char line[MAX_ROWS];
    while (fgets(line, MAX_ROWS, csv_file) != NULL) {
        char *token = strtok(line, ",");
        while (token) {
            strcpy(csv_data[i], token);
            token = strtok(NULL, ",");
            i++;
        }
    }

    // Print the CSV data
    for (int r = 0; r < num_rows; r++) {
        for (int c = 0; c < num_cols; c++) {
            printf("%s ", csv_data[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for (int r = 0; r < num_rows; r++) {
        free(csv_data[r]);
    }
    free(csv_data);

    // Close the CSV file
    fclose(csv_file);

    return EXIT_SUCCESS;
}