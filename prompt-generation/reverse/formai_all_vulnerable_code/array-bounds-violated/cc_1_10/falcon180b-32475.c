//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CsvRow;

CsvRow *read_csv_file(FILE *fp) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->num_fields = 0;
    row->fields = malloc(MAX_FIELDS * sizeof(char*));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        int len = strlen(line);
        if (len == 0 || line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char *token = strtok(line, ",");
        while (token!= NULL) {
            if (row->num_fields >= MAX_FIELDS) {
                printf("Error: Too many fields in row.\n");
                exit(1);
            }
            row->fields[row->num_fields++] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    return row;
}

void print_csv_row(CsvRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    CsvRow *row = read_csv_file(fp);

    printf("CSV Data:\n");
    print_csv_row(row);

    free(row->fields);
    free(row);

    fclose(fp);
    return 0;
}