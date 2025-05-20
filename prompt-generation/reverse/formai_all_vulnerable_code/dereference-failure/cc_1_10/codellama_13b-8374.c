//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
/*
 * A medieval CSV reader program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

struct csv_row {
    char* fields[MAX_FIELD_LENGTH];
    int num_fields;
};

struct csv_row* csv_read_row(FILE* file) {
    struct csv_row* row = malloc(sizeof(struct csv_row));
    char line[MAX_LINE_LENGTH];
    char* field;
    int i = 0;

    if (!fgets(line, MAX_LINE_LENGTH, file)) {
        return NULL;
    }

    field = strtok(line, ",");
    while (field != NULL) {
        row->fields[i] = strdup(field);
        i++;
        field = strtok(NULL, ",");
    }

    row->num_fields = i;
    return row;
}

int main(void) {
    FILE* file = fopen("data.csv", "r");
    struct csv_row* row;

    while ((row = csv_read_row(file)) != NULL) {
        printf("Row %d: ", row->num_fields);
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s, ", row->fields[i]);
        }
        printf("\n");
    }

    return 0;
}