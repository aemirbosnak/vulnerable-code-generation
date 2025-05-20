//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 10
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(char **fields) {
    Record *record = &records[num_records];
    int i;

    for (i = 0; i < MAX_FIELDS && fields[i]!= NULL; i++) {
        record->fields[i] = strdup(fields[i]);
        record->num_fields++;
    }

    num_records++;
}

void print_records() {
    int i, j;

    for (i = 0; i < num_records; i++) {
        Record *record = &records[i];
        for (j = 0; j < record->num_fields; j++) {
            printf("%s ", record->fields[j]);
        }
        printf("\n");
    }
}

int main() {
    char *fields[MAX_FIELDS];
    int i, j;

    add_record(fields);
    add_record(fields);
    add_record(fields);

    print_records();

    return 0;
}