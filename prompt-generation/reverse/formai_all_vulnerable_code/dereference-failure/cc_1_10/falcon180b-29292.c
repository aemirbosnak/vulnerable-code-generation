//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000
#define MAX_FIELD_LEN 100
#define MAX_FIELDS 100
#define DELIM_CHAR ','

typedef struct {
    char *data[MAX_FIELDS];
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = NULL;
    char line[MAX_LINE_LEN];

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, DELIM_CHAR);
        int num_fields = 0;

        while (token!= NULL && num_fields < MAX_FIELDS) {
            row = (CSVRow *) realloc(row, sizeof(CSVRow) + (num_fields + 1) * sizeof(char *));
            row->data[num_fields] = strdup(token);
            num_fields++;

            token = strtok(NULL, DELIM_CHAR);
        }

        if (row!= NULL) {
            row->num_fields = num_fields;
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->data[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp;
    CSVRow *row = NULL;

    fp = fopen("data.csv", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    row = read_csv_file(fp);

    if (row == NULL) {
        printf("No data found in file\n");
        exit(1);
    }

    print_csv_row(row);

    free(row->data[0]);
    free(row->data);
    free(row);

    fclose(fp);

    return 0;
}