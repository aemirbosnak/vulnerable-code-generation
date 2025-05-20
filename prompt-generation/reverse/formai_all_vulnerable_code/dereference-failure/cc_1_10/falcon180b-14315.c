//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: immersive
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

    records[num_records].field1 = strdup(field1);
    records[num_records].field2 = strdup(field2);
    records[num_records].field3 = strdup(field3);

    num_records++;
}

void display_records() {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%s\n", i + 1, records[i].field1, records[i].field2);
    }
}

void search_records(char *key) {
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].field1, key) == 0) {
            printf("Record found:\n");
            printf("ID: %s\n", records[i].field1);
            printf("Name: %s\n", records[i].field2);
            printf("Age: %s\n", records[i].field3);
        }
    }
}

int main() {
    add_record("John", "Doe", "30");
    add_record("Jane", "Doe", "25");
    add_record("Bob", "Smith", "40");

    display_records();

    search_records("John");

    return 0;
}