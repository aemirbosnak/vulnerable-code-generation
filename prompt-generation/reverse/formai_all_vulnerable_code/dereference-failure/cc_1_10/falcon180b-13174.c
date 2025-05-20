//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_CSV_COLUMNS 100

typedef struct {
    char **data;
    int row_count;
    int column_count;
} CSV;

CSV* csv_create() {
    CSV *csv = (CSV*) malloc(sizeof(CSV));
    csv->data = (char**) malloc(MAX_CSV_COLUMNS * sizeof(char*));
    csv->row_count = 0;
    csv->column_count = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        for (int j = 0; j < csv->column_count; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_read_file(CSV *csv, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char **row_data = (char**) malloc(MAX_CSV_COLUMNS * sizeof(char*));
        int column_count = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            row_data[column_count] = strdup(token);
            column_count++;
            token = strtok(NULL, ",");
        }
        csv->data[csv->row_count] = row_data;
        csv->column_count = column_count;
        csv->row_count++;
    }

    fclose(file);
    return 0;
}

void csv_print_data(CSV *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        for (int j = 0; j < csv->column_count; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    csv_read_file(csv, "data.csv");
    csv_print_data(csv);
    csv_destroy(csv);
    return 0;
}