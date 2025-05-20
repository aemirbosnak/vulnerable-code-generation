//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_read(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (cols > csv->cols) {
            csv->cols = cols;
        }

        csv->rows++;
    }

    csv->data = malloc(sizeof(char *) * csv->rows);
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(sizeof(char) * (csv->cols * MAX_CELL_SIZE));
    }

    rewind(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    CSV *csv = csv_read(fp_in);
    fclose(fp_in);

    FILE *fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Error: Could not open output file.\n");
        csv_free(csv);
        return 1;
    }

    csv_print(csv);

    fclose(fp_out);
    csv_free(csv);

    printf("Done!\n");
    return 0;
}