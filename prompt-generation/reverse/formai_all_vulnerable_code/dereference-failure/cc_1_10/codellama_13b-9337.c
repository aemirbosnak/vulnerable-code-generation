//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: imaginative
// Building a CSV Reader in C
// Imaginary Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CSV_ROWS 100
#define MAX_CSV_COLS 10

typedef struct {
    char *data[MAX_CSV_ROWS][MAX_CSV_COLS];
    int rows;
    int cols;
} csv_data_t;

csv_data_t *csv_read(char *filename) {
    csv_data_t *data = malloc(sizeof(csv_data_t));
    data->rows = 0;
    data->cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    char line[MAX_CSV_COLS];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *p = strtok(line, ",");
        while (p != NULL) {
            data->data[data->rows][data->cols] = p;
            data->cols++;
            p = strtok(NULL, ",");
        }
        data->rows++;
        data->cols = 0;
    }

    fclose(fp);
    return data;
}

void csv_print(csv_data_t *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            printf("%s,", data->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    csv_data_t *data = csv_read("data.csv");
    if (data == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    csv_print(data);

    free(data);
    return 0;
}