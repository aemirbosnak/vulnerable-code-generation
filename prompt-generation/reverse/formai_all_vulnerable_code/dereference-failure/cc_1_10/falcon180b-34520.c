//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_CELL_SIZE 100

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->rows = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *p = line;
        while (*p!= '\n' && *p!= '\r') {
            if (*p == ',') {
                csv->num_cols++;
            }
            p++;
        }
        *p = '\0';

        char **row = malloc(csv->num_cols * sizeof(char *));
        int i = 0;
        p = strtok(line, ",");
        while (p!= NULL) {
            row[i] = malloc(strlen(p) + 1);
            strcpy(row[i], p);
            p = strtok(NULL, ",");
            i++;
        }
        csv->rows = realloc(csv->rows, csv->num_rows + 1 * sizeof(char *));
        csv->rows[csv->num_rows] = row;
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->rows[i][j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->rows[i][j]);
        }
        free(csv->rows[i]);
    }
    free(csv->rows);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    if (csv == NULL) {
        return 1;
    }

    csv_print(csv);

    csv_close(csv);

    return 0;
}