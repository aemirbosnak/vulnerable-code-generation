//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *field1;
    char *field2;
    char *field3;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(char *field1, char *field2, char *field3) {
    if (num_records >= MAX_RECORDS) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    Record *r = &records[num_records];
    r->field1 = strdup(field1);
    r->field2 = strdup(field2);
    r->field3 = strdup(field3);

    num_records++;
}

void print_records() {
    for (int i = 0; i < num_records; i++) {
        printf("Record %d:\n", i+1);
        printf("Field 1: %s\n", records[i].field1);
        printf("Field 2: %s\n", records[i].field2);
        printf("Field 3: %s\n", records[i].field3);
        printf("\n");
    }
}

void search_records(char *field1, char *field2, char *field3) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].field1, field1) == 0 && strcmp(records[i].field2, field2) == 0 && strcmp(records[i].field3, field3) == 0) {
            printf("Record found:\n");
            printf("Field 1: %s\n", records[i].field1);
            printf("Field 2: %s\n", records[i].field2);
            printf("Field 3: %s\n", records[i].field3);
            printf("\n");
            return;
        }
    }

    printf("Record not found.\n");
}

int main() {
    add_record("John", "Doe", "25");
    add_record("Jane", "Doe", "30");
    add_record("Bob", "Smith", "40");

    print_records();

    search_records("John", "Doe", "25");
    search_records("Jane", "Doe", "30");
    search_records("Bob", "Smith", "40");

    return 0;
}