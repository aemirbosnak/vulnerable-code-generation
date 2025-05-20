//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 10000
#define MAX_CELL_SIZE 100

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVData;

CSVData *readCSV(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_columns = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        int len = strlen(line);
        if (len == 0 || line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char **rowData = malloc(sizeof(char *) * (data->num_columns + 1));
        int colIndex = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            rowData[colIndex++] = strdup(token);
            token = strtok(NULL, ",");
        }
        rowData[colIndex] = NULL;

        if (data->num_rows == 0) {
            data->num_columns = colIndex;
        } else if (colIndex!= data->num_columns) {
            printf("Error: number of columns does not match previous rows.\n");
            exit(1);
        }

        data->data = realloc(data->data, sizeof(char *) * (data->num_rows + 1));
        data->data[data->num_rows++] = rowData;
    }

    return data;
}

void printCSV(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s\t", data->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    CSVData *data = readCSV(file);
    if (data == NULL) {
        exit(1);
    }

    printCSV(data);

    free(data->data[0]);
    free(data->data);
    free(data);

    return 0;
}