//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    char **data;
    int row;
    int col;
} csv_data;

void init_csv_data(csv_data *csv) {
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(MAX_COL * sizeof(char));
        memset(csv->data[i], 0, MAX_COL);
    }
}

void free_csv_data(csv_data *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
}

void csv_read_file(csv_data *csv, FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            csv->row++;
            csv->col = 0;
        } else if (ch == ',') {
            csv->col++;
        } else {
            if (csv->row >= MAX_ROW || csv->col >= MAX_COL) {
                printf("Error: CSV data exceeds maximum size.\n");
                exit(1);
            }
            csv->data[csv->row][csv->col] = ch;
            csv->col++;
        }
    }
}

void csv_print_data(csv_data *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    csv_data csv;
    init_csv_data(&csv);

    csv_read_file(&csv, fp);

    fclose(fp);

    csv_print_data(&csv);

    free_csv_data(&csv);

    return 0;
}