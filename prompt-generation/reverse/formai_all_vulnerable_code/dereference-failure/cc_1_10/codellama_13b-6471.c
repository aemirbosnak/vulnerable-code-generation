//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *field;
    char *value;
} field_value_pair;

typedef struct {
    field_value_pair *pairs;
    int num_pairs;
} csv_row;

csv_row *read_csv_row(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char *field, *value;
    csv_row *row = NULL;

    if (fgets(line, sizeof(line), fp) != NULL) {
        row = malloc(sizeof(csv_row));
        row->pairs = NULL;
        row->num_pairs = 0;

        field = strtok(line, ",");
        while (field != NULL) {
            value = strtok(NULL, ",");
            if (value != NULL) {
                row->pairs = realloc(row->pairs, (row->num_pairs + 1) * sizeof(field_value_pair));
                row->pairs[row->num_pairs].field = field;
                row->pairs[row->num_pairs].value = value;
                row->num_pairs++;
            }
            field = strtok(NULL, ",");
        }
    }

    return row;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    csv_row *row;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    while ((row = read_csv_row(fp)) != NULL) {
        for (int i = 0; i < row->num_pairs; i++) {
            printf("%s: %s\n", row->pairs[i].field, row->pairs[i].value);
        }
        free(row->pairs);
        free(row);
    }

    fclose(fp);
    return 0;
}