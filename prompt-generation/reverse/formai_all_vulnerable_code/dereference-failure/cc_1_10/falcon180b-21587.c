//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int num_rows;
    int num_cols;
    char delimiter;
    char **data;
} CSV;

CSV *csv_create(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->delimiter = ',';
    csv->data = NULL;

    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (csv->num_rows >= MAX_ROWS) {
            printf("Error: Maximum number of rows exceeded.\n");
            exit(1);
        }

        char *token = strtok(line, csv->delimiter);
        int cols = 0;

        while (token!= NULL) {
            if (csv->num_cols >= MAX_COLS) {
                printf("Error: Maximum number of columns exceeded.\n");
                exit(1);
            }

            csv->data[csv->num_rows][cols] = malloc(strlen(token) + 1);
            strcpy(csv->data[csv->num_rows][cols], token);

            cols++;
            token = strtok(NULL, csv->delimiter);
        }

        csv->num_rows++;
    }

    csv->data = realloc(csv->data, sizeof(char *) * csv->num_rows);

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }

    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CSV *csv = csv_create(file);
    csv_print(csv);

    csv_destroy(csv);

    fclose(file);

    return 0;
}