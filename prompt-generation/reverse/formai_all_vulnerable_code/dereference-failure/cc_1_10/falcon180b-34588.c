//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10000 // Maximum number of rows in the CSV file
#define MAX_COLS 100 // Maximum number of columns in the CSV file
#define MAX_CHARS 100 // Maximum number of characters in a cell

typedef struct {
    char **data; // Pointer to an array of strings
    int rows; // Number of rows in the CSV file
    int cols; // Number of columns in the CSV file
} CSV;

CSV *csv_read(FILE *file) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CHARS];
    while (fgets(line, MAX_CHARS, file)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            csv->cols++;
            csv->data = (char **)realloc(csv->data, sizeof(char *) * csv->cols);
            csv->data[cols] = (char *)malloc(MAX_CHARS * sizeof(char));
            strcpy(csv->data[cols], token);
            cols++;
            token = strtok(NULL, ",");
        }
        csv->rows++;
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s\t", csv->data[j * csv->rows + i]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSV *csv = csv_read(file);
    fclose(file);

    csv_print(csv);

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[j * csv->rows + i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);

    return 0;
}