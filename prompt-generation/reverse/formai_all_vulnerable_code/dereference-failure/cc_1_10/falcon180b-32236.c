//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

Record records[MAX_RECORDS];
int num_records = 0;

void add_record(char **fields) {
    Record *record = &records[num_records++];
    int num_fields = 0;

    while (*fields!= NULL) {
        record->fields[num_fields++] = *fields;
        fields++;
    }

    record->num_fields = num_fields;
}

void print_records() {
    printf("Record ID\tFields\n");

    for (int i = 0; i < num_records; i++) {
        printf("%d\t", i + 1);

        for (int j = 0; j < records[i].num_fields; j++) {
            printf("%s\t", records[i].fields[j]);
        }

        printf("\n");
    }
}

int main() {
    // Example usage
    char *fields1[] = {"John", "Doe", "25", "Male"};
    char *fields2[] = {"Jane", "Doe", "30", "Female"};
    char *fields3[] = {"Bob", "Smith", "40", "Male"};

    add_record(fields1);
    add_record(fields2);
    add_record(fields3);

    print_records();

    return 0;
}