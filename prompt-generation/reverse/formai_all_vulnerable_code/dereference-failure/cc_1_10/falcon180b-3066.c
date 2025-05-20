//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char delimiter;
    FILE *fp;
    int num_rows;
    int num_cols;
    char **data;
} CSVReader;

CSVReader *create_csv_reader(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char delimiter = ',';
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fp;
    reader->delimiter = delimiter;
    reader->num_rows = 0;
    reader->num_cols = 0;
    reader->data = NULL;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        int num_fields = 0;
        char *token = strtok(line, &delimiter);
        while (token!= NULL) {
            num_fields++;
            token = strtok(NULL, &delimiter);
        }
        if (num_fields > 0) {
            reader->num_cols = num_fields;
            break;
        }
    }

    rewind(fp);
    return reader;
}

void destroy_csv_reader(CSVReader *reader) {
    if (reader == NULL) {
        return;
    }

    fclose(reader->fp);
    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_cols; j++) {
            free(reader->data[i][j]);
        }
        free(reader->data[i]);
    }
    free(reader->data);
    free(reader);
}

int read_csv_row(CSVReader *reader, int row_num, char ***data) {
    if (row_num < 0 || row_num >= reader->num_rows) {
        printf("Error: Invalid row number %d\n", row_num);
        return -1;
    }

    *data = reader->data[row_num];
    return 0;
}

int main() {
    CSVReader *reader = create_csv_reader("example.csv");

    int num_rows = reader->num_rows;
    int num_cols = reader->num_cols;

    char **data = malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        data[i] = malloc(sizeof(char) * MAX_CELL_SIZE);
    }

    for (int i = 0; i < num_rows; i++) {
        if (read_csv_row(reader, i, &data[i])!= 0) {
            destroy_csv_reader(reader);
            exit(1);
        }
    }

    destroy_csv_reader(reader);

    return 0;
}