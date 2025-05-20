//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FIELDS 100
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} CSVRow;

CSVRow *csv_row_new() {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    return row;
}

void csv_row_free(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row);
}

int csv_row_add_field(CSVRow *row, char *field) {
    if (row->num_fields >= MAX_FIELDS) {
        return -1;
    }

    row->fields[row->num_fields++] = field;
    return 0;
}

char *csv_row_get_field(CSVRow *row, int index) {
    if (index < 0 || index >= row->num_fields) {
        return NULL;
    }

    return row->fields[index];
}

int csv_read_line(FILE *file, CSVRow *row) {
    char line[MAX_LINE_LENGTH];

    if (fgets(line, sizeof(line), file) == NULL) {
        return -1;
    }

    // Remove trailing newline character
    line[strlen(line) - 1] = '\0';

    char *field;
    char *start = line;
    while ((field = strtok(start, ",")) != NULL) {
        if (csv_row_add_field(row, field) != 0) {
            return -1;
        }

        start = NULL;
    }

    return 0;
}

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    CSVRow *row = csv_row_new();

    while (csv_read_line(file, row) == 0) {
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s ", csv_row_get_field(row, i));
        }
        printf("\n");
    }

    csv_row_free(row);
    fclose(file);

    return EXIT_SUCCESS;
}