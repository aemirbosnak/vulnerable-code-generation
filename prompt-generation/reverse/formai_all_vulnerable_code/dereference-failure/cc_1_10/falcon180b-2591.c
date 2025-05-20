//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_create(FILE *file) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_columns = 0;
    csv->data = (char **) malloc(MAX_COLUMNS * sizeof(char *));
    for (int i = 0; i < MAX_COLUMNS; i++) {
        csv->data[i] = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
        memset(csv->data[i], 0, MAX_LINE_LENGTH);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int column_index = 0;
        while (token!= NULL) {
            if (column_index >= MAX_COLUMNS) {
                printf("Warning: Maximum number of columns reached. Data may be truncated.\n");
                break;
            }
            strcpy(csv->data[column_index], token);
            column_index++;
            token = strtok(NULL, DELIMITER);
        }
        csv->num_columns = column_index;
        csv->num_rows++;
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CSV *csv = csv_create(file);

    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }

    csv_destroy(csv);
    fclose(file);

    return 0;
}