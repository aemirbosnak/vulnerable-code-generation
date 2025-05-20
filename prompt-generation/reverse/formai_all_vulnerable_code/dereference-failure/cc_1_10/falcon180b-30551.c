//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 1000

typedef struct {
    char delimiter;
    int num_fields;
    char **fields;
} csv_t;

csv_t *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    csv_t *csv = malloc(sizeof(csv_t));
    csv->delimiter = ',';
    csv->num_fields = 0;
    csv->fields = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->num_fields++;
            csv->fields = realloc(csv->fields, sizeof(char *) * csv->num_fields);
            csv->fields[csv->num_fields - 1] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    csv->fields = realloc(csv->fields, sizeof(char *) * csv->num_fields);

    fclose(fp);

    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->num_fields; i++) {
        free(csv->fields[i]);
    }
    free(csv->fields);
    free(csv);
}

int main() {
    csv_t *csv = csv_open("data.csv");

    for (int i = 0; i < csv->num_fields; i++) {
        printf("%s\n", csv->fields[i]);
    }

    csv_close(csv);

    return 0;
}