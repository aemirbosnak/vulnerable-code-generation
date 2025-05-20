//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct CSVRow {
    char **data;
    int num_cols;
} CSVRow;

typedef struct CSVReader {
    FILE *file;
    char delimiter;
} CSVReader;

CSVReader *csv_reader_create(const char *filename, char delimiter) {
    CSVReader *reader = (CSVReader*) malloc(sizeof(CSVReader));
    if (reader == NULL) {
        return NULL;
    }
    reader->file = fopen(filename, "r");
    reader->delimiter = delimiter;
    if (reader->file == NULL) {
        free(reader);
        return NULL;
    }
    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    fclose(reader->file);
    free(reader);
}

CSVRow *csv_row_create(int num_cols) {
    CSVRow *row = (CSVRow*) malloc(sizeof(CSVRow));
    if (row == NULL) {
        return NULL;
    }
    row->data = (char**) malloc(num_cols * sizeof(char*));
    if (row->data == NULL) {
        free(row);
        return NULL;
    }
    row->num_cols = num_cols;
    return row;
}

void csv_row_destroy(CSVRow *row) {
    for (int i=0; i<row->num_cols; i++) {
        free(row->data[i]);
    }
    free(row->data);
    free(row);
}

CSVRow *csv_reader_next_row(CSVReader *reader) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, reader->file) == NULL) {
        return NULL;
    }
    int len = strlen(line);
    if (line[len-1] == '\n') {
        line[len-1] = '\0';
    }
    CSVRow *row = csv_row_create(1);
    char *token = strtok(line, &reader->delimiter);
    while (token != NULL) {
        row->data[row->num_cols] = (char*) malloc((strlen(token)+1) * sizeof(char));
        if (row->data[row->num_cols] == NULL) {
            csv_row_destroy(row);
            return NULL;
        }
        strcpy(row->data[row->num_cols], token);
        row->num_cols++;
        row->data = (char**) realloc(row->data, (row->num_cols+1) * sizeof(char*));
        if (row->data == NULL) {
            csv_row_destroy(row);
            return NULL;
        }
        token = strtok(NULL, &reader->delimiter);
    }
    return row;
}

int main() {
    CSVReader *reader = csv_reader_create("example.csv", ',');
    if (reader == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    CSVRow *row;
    while ((row = csv_reader_next_row(reader)) != NULL) {
        for (int i=0; i<row->num_cols; i++) {
            printf("%s\t", row->data[i]);
        }
        printf("\n");
        csv_row_destroy(row);
    }
    csv_reader_destroy(reader);
    return 0;
}