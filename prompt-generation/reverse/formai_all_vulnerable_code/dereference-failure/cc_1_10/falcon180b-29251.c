//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read_file(CSV *csv, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (csv->cols == 0) {
            csv->cols = cols;
            csv->data = (char **) malloc(sizeof(char *) * csv->cols);
        } else if (cols!= csv->cols) {
            printf("Error: Inconsistent number of columns\n");
            exit(1);
        }

        csv->data[csv->rows] = (char *) malloc(sizeof(char) * (strlen(line) + 1));
        strcpy(csv->data[csv->rows], line);
        csv->rows++;
    }

    fclose(file);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    csv_read_file(csv, "example.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}