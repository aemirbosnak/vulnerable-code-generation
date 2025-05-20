//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} csv_file;

csv_file *csv_open(const char *filename) {
    csv_file *csv = (csv_file *)malloc(sizeof(csv_file));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_cols = 0;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->data[csv->num_rows] = (char *)malloc(strlen(token) + 1);
            strcpy(csv->data[csv->num_rows], token);
            csv->num_cols = csv->num_cols > strlen(token)? csv->num_cols : strlen(token);
            csv->num_rows++;
            token = strtok(NULL, ",");
        }
    }
    fclose(file);
    return csv;
}

void csv_print(csv_file *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_close(csv_file *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    csv_file *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);
    return 0;
}