//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_columns = 0;
    csv->data = malloc(MAX_COLUMNS * sizeof(char*));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, DELIMITER);
        int i = 0;
        while (token!= NULL) {
            csv->data[i] = strdup(token);
            i++;
            token = strtok(NULL, DELIMITER);
        }
        csv->num_columns = i;
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[i*csv->num_columns + j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            free(csv->data[i*csv->num_columns + j]);
        }
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("data.csv");
    csv_print(csv);
    csv_close(csv);
    return 0;
}