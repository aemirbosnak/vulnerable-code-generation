//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024 // Maximum length of a line
#define MAX_COLUMNS 100 // Maximum number of columns
#define DELIMITER ',' // Delimiter character

typedef struct {
    char **values; // Array of column values
    int num_columns; // Number of columns
} CsvRow;

CsvRow *read_csv_file(FILE *file) {
    CsvRow *row = NULL;
    char line[MAX_LINE_LENGTH];
    char *token = NULL;
    int num_columns = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (row == NULL) {
            row = malloc(sizeof(CsvRow));
            row->values = NULL;
            row->num_columns = 0;
        }

        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            num_columns++;
            if (num_columns > MAX_COLUMNS) {
                printf("Error: Too many columns\n");
                exit(1);
            }

            if (row->values == NULL) {
                row->values = malloc(sizeof(char *) * num_columns);
            } else {
                row->values = realloc(row->values, sizeof(char *) * num_columns);
            }

            row->values[num_columns - 1] = strdup(token);

            token = strtok(NULL, DELIMITER);
        }

        if (num_columns > 0) {
            row->num_columns = num_columns;
        }
    }

    return row;
}

void print_csv_row(CsvRow *row) {
    int i;

    for (i = 0; i < row->num_columns; i++) {
        printf("%s%c", row->values[i], DELIMITER);
    }

    printf("\n");
}

void free_csv_row(CsvRow *row) {
    int i;

    for (i = 0; i < row->num_columns; i++) {
        free(row->values[i]);
    }

    free(row->values);
    free(row);
}

int main() {
    FILE *file;
    CsvRow *row;

    file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    row = read_csv_file(file);
    if (row == NULL) {
        printf("Error: Invalid CSV format\n");
        exit(1);
    }

    print_csv_row(row);

    free_csv_row(row);

    fclose(file);

    return 0;
}