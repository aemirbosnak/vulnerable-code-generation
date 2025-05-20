//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
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

CSV *csv_create(void) {
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
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            csv->row++;
            csv->col = 0;
        } else if (ch == ',') {
            csv->col++;
        } else {
            int row = csv->row;
            int col = csv->col;
            while (col >= MAX_COL) {
                col -= MAX_COL;
                row++;
            }
            csv->data[row][col] = ch;
            csv->col++;
        }
    }
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "r");
    if (fp_in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    CSV *csv = csv_create();
    csv_read_file(csv, fp_in);

    FILE *fp_out = fopen(argv[2], "w");
    if (fp_out == NULL) {
        printf("Error opening output file.\n");
        csv_destroy(csv);
        fclose(fp_in);
        return 1;
    }

    csv_print(csv);

    fprintf(fp_out, "Row: %d\n", csv->row);
    fprintf(fp_out, "Col: %d\n", csv->col);

    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            fprintf(fp_out, "%c", csv->data[i][j]);
        }
        fprintf(fp_out, "\n");
    }

    fclose(fp_in);
    fclose(fp_out);
    csv_destroy(csv);

    return 0;
}