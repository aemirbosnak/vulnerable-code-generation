//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','
#define QUOTE '"'

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVReader;

CSVReader *csv_reader_create() {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->data = NULL;
    reader->num_rows = 0;
    reader->num_columns = 0;
    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    if (reader->data!= NULL) {
        for (int i = 0; i < reader->num_rows; i++) {
            for (int j = 0; j < reader->num_columns; j++) {
                free(reader->data[i][j]);
            }
            free(reader->data[i]);
        }
        free(reader->data);
    }
    free(reader);
}

void csv_reader_read_file(CSVReader *reader, FILE *file) {
    char line[MAX_LINE_SIZE];
    char *token;
    int row = 0;
    int column = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        row++;
        if (row == 1 && strcmp(line, "") == 0) {
            continue;
        }
        column = 0;
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (column >= reader->num_columns) {
                reader->num_columns++;
            }
            if (reader->data == NULL) {
                reader->data = (char **)malloc(sizeof(char *) * reader->num_rows);
                for (int i = 0; i < reader->num_rows; i++) {
                    reader->data[i] = (char *)malloc(sizeof(char) * reader->num_columns);
                }
            }
            if (column == 0) {
                reader->data[row][column] = strdup(token);
            } else {
                char *quoted_token = strtok(NULL, DELIMITER);
                if (quoted_token!= NULL && strcmp(quoted_token, "")!= 0) {
                    reader->data[row][column] = strdup(quoted_token);
                } else {
                    reader->data[row][column] = strdup("");
                }
            }
            token = strtok(NULL, DELIMITER);
            column++;
        }
    }
    reader->num_rows = row;
}

void csv_reader_print_data(CSVReader *reader) {
    for (int i = 0; i < reader->num_rows; i++) {
        for (int j = 0; j < reader->num_columns; j++) {
            printf("%s\t", reader->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    CSVReader *reader = csv_reader_create();
    csv_reader_read_file(reader, file);
    csv_reader_print_data(reader);
    csv_reader_destroy(reader);
    fclose(file);
    return 0;
}