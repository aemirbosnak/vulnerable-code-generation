//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *field1;
    char *field2;
    int field3;
} Record;

void createTable(Record *table) {
    strcpy(table[0].field1, "John");
    strcpy(table[0].field2, "Doe");
    table[0].field3 = 25;

    strcpy(table[1].field1, "Jane");
    strcpy(table[1].field2, "Doe");
    table[1].field3 = 30;

    strcpy(table[2].field1, "Bob");
    strcpy(table[2].field2, "Smith");
    table[2].field3 = 40;
}

int searchTable(Record *table, char *searchField, char *value) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(table[i].field1, value) == 0) {
            printf("Record found: %s %s %d\n", table[i].field1, table[i].field2, table[i].field3);
            return 1;
        }
    }
    printf("Record not found.\n");
    return 0;
}

int main() {
    Record table[MAX_RECORDS];
    createTable(table);

    char searchField[MAX_FIELD_SIZE];
    printf("Enter field to search: ");
    scanf("%s", searchField);

    char value[MAX_FIELD_SIZE];
    printf("Enter value to search: ");
    scanf("%s", value);

    searchTable(table, searchField, value);

    return 0;
}