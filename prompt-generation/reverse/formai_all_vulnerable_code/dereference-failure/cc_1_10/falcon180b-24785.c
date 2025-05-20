//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_COLUMN 1000

typedef struct {
    char **row;
    int row_count;
    int column_count;
} CSVReader;

CSVReader *csv_reader_create() {
    CSVReader *reader = (CSVReader *)malloc(sizeof(CSVReader));
    reader->row = (char **)malloc(MAX_ROW_COLUMN * sizeof(char *));
    reader->row_count = 0;
    reader->column_count = 0;
    return reader;
}

void csv_reader_destroy(CSVReader *reader) {
    for (int i = 0; i < reader->row_count; i++) {
        free(reader->row[i]);
    }
    free(reader->row);
    free(reader);
}

int csv_reader_read_file(CSVReader *reader, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return -1;
    }

    char line[MAX_ROW_COLUMN];
    char *token = NULL;
    int row = 0;
    int column = 0;

    while (fgets(line, MAX_ROW_COLUMN, file)!= NULL) {
        if (row >= MAX_ROW_COLUMN) {
            printf("Error: Too many rows in the CSV file.\n");
            csv_reader_destroy(reader);
            fclose(file);
            return -1;
        }

        reader->row[row] = (char *)malloc((strlen(line) + 1) * sizeof(char));
        strcpy(reader->row[row], line);

        token = strtok(line, ",");
        while (token!= NULL) {
            column++;
            if (column >= MAX_ROW_COLUMN) {
                printf("Error: Too many columns in the CSV file.\n");
                csv_reader_destroy(reader);
                fclose(file);
                return -1;
            }

            reader->row[row][column] = token;

            token = strtok(NULL, ",");
        }

        row++;
    }

    fclose(file);
    reader->row_count = row;
    reader->column_count = column;

    return 0;
}

char *csv_reader_get_value(CSVReader *reader, int row, int column) {
    if (row < 0 || row >= reader->row_count || column < 0 || column >= reader->column_count) {
        return NULL;
    }

    return reader->row[row][column];
}

int main() {
    CSVReader *reader = csv_reader_create();
    csv_reader_read_file(reader, "example.csv");

    int row_count = reader->row_count;
    int column_count = reader->column_count;

    printf("Row count: %d\n", row_count);
    printf("Column count: %d\n", column_count);

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < column_count; j++) {
            char *value = csv_reader_get_value(reader, i, j);
            if (value!= NULL) {
                printf("%s ", value);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }

    csv_reader_destroy(reader);

    return 0;
}