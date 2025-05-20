//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

typedef struct {
    char *data;
    int len;
} Field;

typedef struct {
    int num_fields;
    Field fields[MAX_FIELDS];
} Row;

typedef struct {
    int num_rows;
    Row rows[MAX_FIELDS];
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        int num_fields = 0;
        char *token = strtok(line, ",");
        while (token!= NULL) {
            Field field = {.data = token,.len = strlen(token)};
            csv->rows[csv->num_rows].fields[num_fields++] = field;
            token = strtok(NULL, ",");
        }
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            printf("%s ", csv->rows[i].fields[j].data);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}