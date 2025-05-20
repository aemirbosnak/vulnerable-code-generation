//Code Llama-13B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
/*
 * Building a CSV Reader example program in a single-threaded style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

typedef struct {
    char* field;
    int length;
} field_t;

typedef struct {
    field_t* fields;
    int num_fields;
} record_t;

record_t* parse_record(char* line) {
    record_t* record = malloc(sizeof(record_t));
    record->fields = malloc(MAX_FIELD_LENGTH * sizeof(field_t));
    record->num_fields = 0;

    char* token = strtok(line, ",");
    while (token != NULL) {
        record->fields[record->num_fields].field = strdup(token);
        record->fields[record->num_fields].length = strlen(token);
        record->num_fields++;
        token = strtok(NULL, ",");
    }

    return record;
}

void print_record(record_t* record) {
    printf("[");
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s", record->fields[i].field);
        if (i != record->num_fields - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
        record_t* record = parse_record(line);
        print_record(record);
        free(record->fields);
        free(record);
    }
    return 0;
}