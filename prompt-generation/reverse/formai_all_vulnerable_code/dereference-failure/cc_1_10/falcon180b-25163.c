//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    int row;
    int col;
} Cell;

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp;
    CSV *csv;
    char ch;
    int row = 0;
    int col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(sizeof(char *) * MAX_ROW);
    csv->row = 0;
    csv->col = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else if (ch == ',') {
            col++;
        } else {
            if (row >= MAX_ROW) {
                printf("Error: Too many rows\n");
                exit(1);
            }
            if (col >= MAX_COL) {
                printf("Error: Too many columns\n");
                exit(1);
            }
            csv->data[row] = (char *)realloc(csv->data[row], strlen(csv->data[row]) + 2);
            csv->data[row][strlen(csv->data[row])] = ch;
            csv->data[row][strlen(csv->data[row]) + 1] = '\0';
        }
    }

    fclose(fp);

    return csv;
}

void csv_close(CSV *csv) {
    int i;

    for (i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv;

    csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}