//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_DATA 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_ROWS];
    char *token = strtok(line, ",");

    while (token!= NULL) {
        csv->cols++;
        token = strtok(NULL, ",");
    }

    csv->data = malloc(csv->cols * sizeof(char *));
    rewind(fp);

    int row = 0;
    while (fgets(line, MAX_ROWS, fp)!= NULL) {
        csv->rows++;
        char *cell_data = strtok(line, ",");
        for (int col = 0; col < csv->cols; col++) {
            csv->data[col] = realloc(csv->data[col], strlen(cell_data) + 1);
            strcpy(csv->data[col], cell_data);
            cell_data = strtok(NULL, ",");
        }
        row++;
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int row = 0; row < csv->rows; row++) {
        for (int col = 0; col < csv->cols; col++) {
            printf("%s\t", csv->data[col]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    CSV *csv = csv_create(fp);
    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}