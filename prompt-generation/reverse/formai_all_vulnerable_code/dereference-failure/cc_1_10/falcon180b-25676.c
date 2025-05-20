//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_COLUMNS 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CSVData;

CSVData *read_csv(FILE *fp) {
    CSVData *data = malloc(sizeof(CSVData));
    data->rows = 0;
    data->columns = 0;
    data->data = malloc(MAX_LINES * sizeof(char *));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int column_count = 0;
        while (token!= NULL) {
            data->data[data->rows] = malloc(strlen(token) + 1);
            strcpy(data->data[data->rows], token);
            data->columns = (data->columns > column_count)? data->columns : column_count;
            column_count++;
            data->rows++;
            token = strtok(NULL, ",");
        }
    }

    return data;
}

void print_csv(CSVData *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            printf("%s ", data->data[i]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename.csv>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    CSVData *data = read_csv(fp);
    fclose(fp);

    printf("CSV Data:\n");
    print_csv(data);

    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->columns; j++) {
            free(data->data[i]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);

    return 0;
}