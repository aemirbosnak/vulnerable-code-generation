//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(MAX_COL * sizeof(char));
        memset(csv->data[i], 0, MAX_COL);
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

void csv_read_file(CSV *csv, FILE *fp) {
    char ch;
    int in_quote = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == ',' &&!in_quote) {
            csv->data[csv->row][csv->col] = 0;
            csv->col++;
        } else if (ch == '\"') {
            in_quote =!in_quote;
        } else if (ch == '\n' || ch == '\r') {
            csv->row++;
            csv->col = 0;
        } else {
            if (csv->col >= MAX_COL - 1) {
                printf("Error: Column limit reached.\n");
                exit(1);
            }
            csv->data[csv->row][csv->col++] = ch;
        }
    }
    csv->data[csv->row][csv->col] = 0;
    csv->col++;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    csv_read_file(csv, fp);
    fclose(fp);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}