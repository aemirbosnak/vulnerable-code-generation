//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_LENGTH 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    if (csv->data!= NULL) {
        free(csv->data);
    }
    free(csv);
}

int csv_read_file(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    csv->data = malloc(MAX_CELL_LENGTH);
    if (csv->data == NULL) {
        fclose(fp);
        return -2;
    }

    char c;
    int row = 0;
    int col = 0;
    while ((c = fgetc(fp))!= EOF) {
        if (c == '\n') {
            row++;
            col = 0;
        } else if (c == ',') {
            col++;
        } else {
            if (col >= MAX_CELL_LENGTH) {
                fprintf(stderr, "Error: cell length exceeded %d\n", MAX_CELL_LENGTH);
                csv_destroy(csv);
                fclose(fp);
                return -3;
            }
            csv->data[row * MAX_CELL_LENGTH + col] = c;
            col++;
        }
    }

    csv->rows = row + 1;
    csv->cols = col;

    fclose(fp);
    return 0;
}

void csv_print(CSV *csv) {
    int row, col;
    for (row = 0; row < csv->rows; row++) {
        for (col = 0; col < csv->cols; col++) {
            printf("%c", csv->data[row * MAX_CELL_LENGTH + col]);
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