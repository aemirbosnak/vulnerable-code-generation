//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->columns = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i;
    for (i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_add_row(CSV *csv, char *line) {
    int i;
    char *token;
    char **new_data = malloc((csv->rows + 1) * sizeof(char *));
    for (i = 0; i < csv->rows; i++) {
        new_data[i] = csv->data[i];
    }
    new_data[csv->rows] = line;
    csv->data = new_data;
    csv->rows++;

    token = strtok(line, DELIMITER);
    while (token!= NULL) {
        csv->columns++;
        token = strtok(NULL, DELIMITER);
    }
}

int csv_get_rows(CSV *csv) {
    return csv->rows;
}

int csv_get_columns(CSV *csv) {
    return csv->columns;
}

char **csv_get_data(CSV *csv) {
    return csv->data;
}

int main() {
    FILE *file;
    char line[MAX_LINE_SIZE];
    CSV *csv = csv_create();

    file = fopen("example.csv", "r");

    if (file == NULL) {
        fprintf(stderr, "Error: could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        csv_add_row(csv, line);
    }

    fclose(file);

    int rows = csv_get_rows(csv);
    int columns = csv_get_columns(csv);

    printf("CSV file has %d rows and %d columns.\n", rows, columns);

    char **data = csv_get_data(csv);

    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%s ", data[i]);
        }
        printf("\n");
    }

    csv_destroy(csv);
    return 0;
}