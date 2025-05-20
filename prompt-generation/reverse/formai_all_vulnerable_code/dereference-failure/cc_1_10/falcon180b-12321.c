//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVData;

CSVData *read_csv(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    CSVData *data = malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_columns = 0;
    data->data = malloc(sizeof(char *) * MAX_COLUMNS);

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        int num_fields = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            num_fields++;
            if (num_fields >= MAX_COLUMNS) {
                fprintf(stderr, "Too many columns in row\n");
                exit(1);
            }
            data->data[num_fields] = strdup(token);
            token = strtok(NULL, ",");
        }
        data->num_columns = num_fields;
        data->num_rows++;
    }

    if (data->num_columns == 0) {
        fprintf(stderr, "No columns found in file\n");
        exit(1);
    }

    return data;
}

void print_csv(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s ", data->data[j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    CSVData *data = read_csv(argv[1]);
    print_csv(data);

    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            free(data->data[j]);
        }
        free(data->data);
    }
    free(data);

    return 0;
}