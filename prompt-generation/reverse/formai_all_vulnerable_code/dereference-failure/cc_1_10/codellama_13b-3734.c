//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char** columns;
    int num_columns;
    int num_rows;
} CSV_Data;

void csv_reader_init(CSV_Data* data) {
    data->columns = malloc(MAX_COLUMNS * sizeof(char*));
    data->num_columns = 0;
    data->num_rows = 0;
}

void csv_reader_free(CSV_Data* data) {
    for (int i = 0; i < data->num_columns; i++) {
        free(data->columns[i]);
    }
    free(data->columns);
}

void csv_reader_read(CSV_Data* data, const char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        char* token = strtok(line, ",");
        while (token != NULL) {
            data->columns[data->num_columns++] = token;
            token = strtok(NULL, ",");
        }
        data->num_rows++;
    }

    fclose(file);
}

void csv_reader_print(CSV_Data* data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s, ", data->columns[j]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    CSV_Data data;
    csv_reader_init(&data);
    csv_reader_read(&data, "example.csv");
    csv_reader_print(&data);
    csv_reader_free(&data);
    return 0;
}