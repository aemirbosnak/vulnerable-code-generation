//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CSVReader;

CSVReader *csv_reader_create(FILE *file) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->data = NULL;
    reader->rows = 0;
    reader->cols = 0;

    char line[MAX_LINE_LENGTH];
    char *delimiter = ",";
    char *token;
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int j = 0;
        token = strtok(line, delimiter);
        while (token!= NULL) {
            j++;
            if (i == 0) {
                reader->cols = j;
            }
            if (reader->data == NULL) {
                reader->data = malloc(sizeof(char *) * reader->cols);
            } else {
                reader->data = realloc(reader->data, sizeof(char *) * reader->cols);
            }
            reader->data[i] = malloc(strlen(token) + 1);
            strcpy(reader->data[i], token);
            token = strtok(NULL, delimiter);
            i++;
        }
        if (i > 0) {
            reader->rows++;
        }
    }

    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->rows; i++) {
        for (int j = 0; j < reader->cols; j++) {
            free(reader->data[i * reader->cols + j]);
        }
    }
    free(reader->data);
    free(reader);
}

char **csv_reader_get_data(CSVReader *reader) {
    return reader->data;
}

int csv_reader_get_rows(CSVReader *reader) {
    return reader->rows;
}

int csv_reader_get_cols(CSVReader *reader) {
    return reader->cols;
}

int main() {

    FILE *file = fopen("example.csv", "r");

    CSVReader *reader = csv_reader_create(file);

    char **data = csv_reader_get_data(reader);

    for (int i = 0; i < csv_reader_get_rows(reader); i++) {
        for (int j = 0; j < csv_reader_get_cols(reader); j++) {
            printf("%s\t", data[i * csv_reader_get_cols(reader) + j]);
        }
        printf("\n");
    }

    csv_reader_destroy(reader);

    return 0;
}