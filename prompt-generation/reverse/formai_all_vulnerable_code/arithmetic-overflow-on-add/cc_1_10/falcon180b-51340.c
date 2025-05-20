//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

// Function to split a string into tokens using delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    return tokens;
}

// Function to read a CSV file and return a 2D array of strings
CSV read_csv(char *filename) {
    FILE *file = fopen(filename, "r");
    CSV csv;
    char line[1024];

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        char **row_data = split(line, ',');
        csv.data = realloc(csv.data, sizeof(char *) * (csv.rows + 1));
        csv.data[csv.rows] = row_data;
        csv.rows++;
    }

    csv.cols = strlen(csv.data[0]) / sizeof(char *);

    return csv;
}

// Function to print a CSV file in a formatted manner
void print_csv(CSV csv) {
    int i, j;

    for (i = 0; i < csv.rows; i++) {
        for (j = 0; j < csv.cols; j++) {
            printf("%s ", csv.data[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    CSV csv = read_csv(argv[1]);
    print_csv(csv);

    for (int i = 0; i < csv.rows; i++) {
        for (int j = 0; j < csv.cols; j++) {
            free(csv.data[i][j]);
        }
        free(csv.data[i]);
    }
    free(csv.data);

    return 0;
}