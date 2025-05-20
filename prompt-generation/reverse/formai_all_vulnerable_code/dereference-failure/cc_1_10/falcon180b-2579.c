//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int num_columns = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            num_columns++;
            token = strtok(NULL, ",");
        }

        if (csv->num_columns == 0) {
            csv->num_columns = num_columns;
            csv->data = malloc(sizeof(char *) * csv->num_columns);
        } else if (num_columns!= csv->num_columns) {
            printf("Error: Mismatched number of columns.\n");
            exit(1);
        }

        int i = 0;
        while ((token = strtok(line, ","))!= NULL) {
            csv->data[i] = strdup(token);
            i++;
        }

        csv->num_rows++;
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s ", csv->data[j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    CSV *csv = csv_create(fp);
    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}