//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_LEN 1000

typedef struct {
    int num_rows;
    int num_cols;
    char delimiter;
    char **data;
} CSV;

CSV *csv_init(FILE *fp) {
    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->delimiter = ',';
    csv->data = NULL;

    char line[MAX_DATA_LEN];
    char *token = NULL;
    int i = 0;

    while (fgets(line, MAX_DATA_LEN, fp)!= NULL) {
        csv->num_rows++;
        csv->data = (char **) realloc(csv->data, sizeof(char *) * csv->num_rows);
        csv->data[csv->num_rows - 1] = (char *) malloc(MAX_DATA_LEN);
        strcpy(csv->data[csv->num_rows - 1], line);

        token = strtok(line, ",");
        while (token!= NULL) {
            csv->num_cols = i + 1;
            csv->data[csv->num_rows - 1][i] = token;
            token = strtok(NULL, ",");
            i++;
        }
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    int i, j;

    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_init(fp);
    csv_print(csv);
    csv_destroy(csv);

    return 0;
}