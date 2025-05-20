//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_FIELDS 1000

typedef struct {
    char **fields;
    int num_fields;
} csv_row_t;

typedef struct {
    FILE *fp;
    char *delimiter;
    int header_read;
} csv_t;

csv_row_t *csv_read_row(csv_t *csv) {
    char line[MAX_LINE_SIZE];
    char *token;
    char *saveptr = NULL;
    csv_row_t *row = (csv_row_t *)malloc(sizeof(csv_row_t));
    row->fields = (char **)malloc(MAX_NUM_FIELDS * sizeof(char *));
    row->num_fields = 0;

    if (fgets(line, MAX_LINE_SIZE, csv->fp) == NULL) {
        if (feof(csv->fp)) {
            printf("End of file reached.\n");
        } else {
            perror("fgets");
        }
        return NULL;
    }

    if (csv->header_read == 0) {
        csv->header_read = 1;
        return row;
    }

    token = strtok_r(line, csv->delimiter, &saveptr);
    while (token!= NULL) {
        row->fields[row->num_fields] = strdup(token);
        row->num_fields++;
        token = strtok_r(NULL, csv->delimiter, &saveptr);
    }

    return row;
}

void csv_close(csv_t *csv) {
    fclose(csv->fp);
    free(csv);
}

int main() {
    csv_t csv;
    csv.fp = fopen("example.csv", "r");
    if (csv.fp == NULL) {
        perror("fopen");
        exit(1);
    }

    csv.delimiter = ",";
    csv.header_read = 0;

    while ((csv_row_t *)csv_read_row(&csv)!= NULL) {
        for (int i = 0; i < ((csv_row_t *)csv_read_row(&csv))->num_fields; i++) {
            printf("%s ", ((csv_row_t *)csv_read_row(&csv))->fields[i]);
        }
        printf("\n");
    }

    csv_close(&csv);

    return 0;
}