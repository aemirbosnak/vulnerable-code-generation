//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_FIELD_COUNT 100
#define MAX_FIELD_LENGTH 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    int count;
    field_t fields[MAX_FIELD_COUNT];
} record_t;

record_t *parse_line(char *line) {
    record_t *record = malloc(sizeof(record_t));
    memset(record, 0, sizeof(record_t));

    char *token = strtok(line, ",");
    int count = 0;

    while (token!= NULL && count < MAX_FIELD_COUNT) {
        field_t *field = malloc(sizeof(field_t));
        memset(field, 0, sizeof(field_t));

        field->name = strdup(token);
        field->value = strdup(strtok(NULL, ","));

        record->fields[count++] = *field;
        free(field);

        token = strtok(NULL, ",");
    }

    return record;
}

void print_record(record_t *record) {
    printf("{\n");
    for (int i = 0; i < record->count; i++) {
        printf("  \"%s\": \"%s\",\n", record->fields[i].name, record->fields[i].value);
    }
    printf("}\n");
}

int main() {
    char line[MAX_LINE];

    while (fgets(line, MAX_LINE, stdin)!= NULL) {
        record_t *record = parse_line(line);
        print_record(record);
        free(record);
    }

    return 0;
}