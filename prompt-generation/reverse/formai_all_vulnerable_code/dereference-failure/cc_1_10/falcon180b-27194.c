//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} string_t;

typedef struct {
    string_t **lines;
    size_t num_lines;
    size_t capacity;
} csv_t;

csv_t *csv_create(void) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->lines = NULL;
    csv->num_lines = 0;
    csv->capacity = 0;
    return csv;
}

void csv_destroy(csv_t *csv) {
    for (size_t i = 0; i < csv->num_lines; i++) {
        free(csv->lines[i]->data);
        free(csv->lines[i]);
    }
    free(csv->lines);
    free(csv);
}

void csv_clear(csv_t *csv) {
    for (size_t i = 0; i < csv->num_lines; i++) {
        free(csv->lines[i]->data);
    }
    csv->num_lines = 0;
}

void csv_append_line(csv_t *csv, const char *line) {
    if (csv->num_lines >= csv->capacity) {
        csv->capacity += 16;
        csv->lines = realloc(csv->lines, csv->capacity * sizeof(string_t *));
    }
    csv->lines[csv->num_lines] = malloc(sizeof(string_t));
    csv->lines[csv->num_lines]->data = strdup(line);
    csv->lines[csv->num_lines]->size = strlen(line);
    csv->num_lines++;
}

void csv_print(const csv_t *csv) {
    for (size_t i = 0; i < csv->num_lines; i++) {
        printf("%s\n", csv->lines[i]->data);
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    csv_t *csv = csv_create();

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        csv_append_line(csv, line);
    }

    fclose(file);

    csv_print(csv);

    csv_destroy(csv);

    return 0;
}