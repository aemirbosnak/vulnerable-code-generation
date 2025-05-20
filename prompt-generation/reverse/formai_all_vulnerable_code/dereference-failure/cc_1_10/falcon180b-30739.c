//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 1000

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *fp) {
    CSVRow *row = malloc(sizeof(CSVRow));
    char line[MAX_LINE_LEN];
    char *token;
    int num_fields = 0;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            row->fields[num_fields] = strdup(token);
            num_fields++;
            token = strtok(NULL, ",");
        }
        row->num_fields = num_fields;
        num_fields = 0;
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSVRow *row = read_csv_file(fp);
    if (row == NULL || row->num_fields == 0) {
        printf("No data found in file.\n");
        free(row);
        fclose(fp);
        return 1;
    }

    print_csv_row(row);

    free(row->fields);
    free(row);
    fclose(fp);

    return 0;
}