//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_CSV_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int row_count;
    int column_count;
} CSVData;

CSVData *read_csv(FILE *file) {
    char line[MAX_LINE_SIZE];
    CSVData *data = malloc(sizeof(CSVData));
    data->row_count = 0;
    data->column_count = 0;
    data->data = malloc(MAX_CSV_COLUMNS * sizeof(char *));

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int column_count = 0;
        while (token!= NULL) {
            data->data[column_count] = strdup(token);
            column_count++;
            token = strtok(NULL, DELIMITER);
        }
        data->column_count = column_count;
        data->row_count++;
    }

    return data;
}

void print_csv(CSVData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->column_count; j++) {
            printf("%s\t", data->data[j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSVData *data = read_csv(file);
    printf("CSV Data:\n");
    print_csv(data);

    fclose(file);

    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->column_count; j++) {
            free(data->data[j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);

    return 0;
}