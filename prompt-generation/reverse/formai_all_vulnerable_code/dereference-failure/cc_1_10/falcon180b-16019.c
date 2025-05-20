//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVData;

CSVData *read_csv(FILE *file) {
    CSVData *csv_data = malloc(sizeof(CSVData));
    csv_data->data = malloc(MAX_ROWS * sizeof(char *));
    csv_data->num_rows = 0;
    csv_data->num_columns = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            if (i >= MAX_COLUMNS) {
                printf("Error: Too many columns in line.\n");
                exit(1);
            }
            csv_data->data[csv_data->num_rows] = malloc(strlen(token) + 1);
            strcpy(csv_data->data[csv_data->num_rows], token);
            csv_data->num_columns = i + 1;
            csv_data->num_rows++;
            token = strtok(NULL, ",");
            i++;
        }
    }

    return csv_data;
}

void print_csv(CSVData *csv_data) {
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_columns; j++) {
            printf("%s ", csv_data->data[i]);
        }
        printf("\n");
    }
}

void free_csv_data(CSVData *csv_data) {
    for (int i = 0; i < csv_data->num_rows; i++) {
        free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    CSVData *csv_data = read_csv(file);
    print_csv(csv_data);

    free_csv_data(csv_data);
    fclose(file);

    return 0;
}