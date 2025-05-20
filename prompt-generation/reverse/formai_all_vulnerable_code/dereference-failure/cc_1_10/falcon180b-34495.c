//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field[MAX_FIELD_SIZE];
    int num_fields;
} Record;

Record *records = NULL;
int num_records = 0;

void add_record(char *fields[]) {
    Record *new_record = malloc(sizeof(Record));
    new_record->num_fields = 0;

    for (int i = 0; fields[i]!= NULL; i++) {
        char *field = strdup(fields[i]);
        new_record->field[new_record->num_fields++] = field;
    }

    records = realloc(records, sizeof(Record) * (num_records + 1));
    records[num_records++] = *new_record;
}

void print_records() {
    for (int i = 0; i < num_records; i++) {
        for (int j = 0; j < records[i].num_fields; j++) {
            printf("%s ", records[i].field[j]);
        }
        printf("\n");
    }
}

int main() {
    char *fields[] = {"John", "Doe", "25"};
    add_record(fields);

    fields[0] = "Jane";
    fields[1] = "Doe";
    fields[2] = "30";
    add_record(fields);

    print_records();

    return 0;
}