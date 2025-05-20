//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FIELDS 100
#define DELIMITER ','

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = NULL;
    char line[MAX_LINE_SIZE];
    char *token = NULL;
    int num_fields = 0;
    int field_size = 0;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        field_size = strlen(line) - 1;
        num_fields = 0;
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            num_fields++;
            field_size += strlen(token) + 1;
            token = strtok(NULL, DELIMITER);
        }
        row = realloc(row, sizeof(CSVRow) + num_fields * sizeof(char *));
        row->num_fields = num_fields;
        row->fields = (char **)realloc(row->fields, num_fields * sizeof(char *));
        token = strtok(line, DELIMITER);
        for (int i = 0; i < num_fields; i++) {
            row->fields[i] = strdup(token);
            token = strtok(NULL, DELIMITER);
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s\t", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    CSVRow *row = read_csv_file(fp);
    print_csv_row(row);

    free_csv_row(row);
    fclose(fp);

    return 0;
}