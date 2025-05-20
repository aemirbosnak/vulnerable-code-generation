//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CsvData;

CsvData* csv_read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: failed to open file %s\n", filename);
        exit(1);
    }

    CsvData* data = malloc(sizeof(CsvData));
    data->data = NULL;
    data->rows = data->cols = 0;

    char line[MAX_ROW];
    while (fgets(line, MAX_ROW, file)!= NULL) {
        char* row_data = strdup(line);
        char* token = strtok(row_data, ",");

        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (cols > data->cols) {
            data->cols = cols;
            data->data = realloc(data->data, sizeof(char*) * data->rows * data->cols);
            memset(&data->data[data->rows * data->cols - data->cols], 0, sizeof(char*) * data->cols);
        }

        data->data[data->rows * data->cols - data->cols] = row_data;
        data->rows++;
    }

    fclose(file);
    return data;
}

void csv_print_data(CsvData* data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            printf("%s\t", data->data[i * data->cols + j]);
        }
        printf("\n");
    }
}

void csv_free_data(CsvData* data) {
    for (int i = 0; i < data->rows; i++) {
        free(data->data[i * data->cols]);
    }
    free(data->data);
    free(data);
}

int main() {
    CsvData* data = csv_read_file("example.csv");
    csv_print_data(data);
    csv_free_data(data);

    return 0;
}