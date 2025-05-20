//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

typedef struct {
    char delimiter;
    char *fields[MAX_FIELDS];
    int field_count;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = NULL;
    char line[MAX_LINE_LEN];
    char *token = NULL;
    int field_count = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (row == NULL) {
            row = malloc(sizeof(CSVRow));
            row->delimiter = line[0];
            strcpy(row->fields[0], &line[1]);
            field_count = 1;
        } else {
            token = strtok(&line[0], row->delimiter);
            while (token!= NULL) {
                strcpy(row->fields[field_count], token);
                field_count++;
                token = strtok(NULL, row->delimiter);
            }
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        printf("%s%c", row->fields[i], i < row->field_count - 1? row->delimiter : '\n');
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSVRow *row = read_csv_file(fp);

    if (row!= NULL) {
        print_csv_row(row);
        free(row->fields[0]);
        free(row->fields);
        free(row);
    }

    fclose(fp);
    return 0;
}