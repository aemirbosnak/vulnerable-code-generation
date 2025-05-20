//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100
#define MAX_LINE 1024

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_append_row(CSV *csv, char *line) {
    char *token = strtok(line, ",");
    while (token!= NULL) {
        int col = csv->col;
        while (col >= csv->row) {
            csv->data[col] = realloc(csv->data[col], strlen(token) + 1);
        }
        strcpy(csv->data[col], token);
        csv->col++;
        token = strtok(NULL, ",");
    }
    csv->row++;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Error: Please provide a CSV file as an argument.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    CSV *csv = csv_create();
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, file)!= NULL) {
        csv_append_row(csv, line);
    }

    csv_print(csv);

    csv_destroy(csv);
    fclose(file);

    return 0;
}