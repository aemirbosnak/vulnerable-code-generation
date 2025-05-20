//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_CSV_SIZE 1000000

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->row = 0;
    csv->col = 0;
    csv->data = (char **)malloc(sizeof(char *) * MAX_ROW);
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(sizeof(char) * MAX_COL);
    }
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read(CSV *csv, const char *file) {
    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", file);
        exit(EXIT_FAILURE);
    }
    char ch;
    int row = 0;
    int col = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else if (ch == ',') {
            col++;
        } else {
            if (row >= MAX_ROW || col >= MAX_COL) {
                printf("Error: CSV data exceeds maximum size\n");
                fclose(fp);
                csv_destroy(csv);
                exit(EXIT_FAILURE);
            }
            csv->data[row][col] = ch;
            col++;
        }
    }
    csv->row = row;
    csv->col = col;
    fclose(fp);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    csv_read(csv, "data.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}