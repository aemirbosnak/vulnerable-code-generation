//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 100
#define MAX_VALUE_SIZE 1000

typedef struct {
    char name[MAX_NAME_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

void read_records(Record* records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Enter record %d name: ", i+1);
        scanf("%s", records[i].name);
        printf("Enter record %d value: ", i+1);
        scanf("%s", records[i].value);
    }
}

void print_records(Record* records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        printf("Record %d: %s = %s\n", i+1, records[i].name, records[i].value);
    }
}

void query_records(Record* records, int num_records, char* query) {
    int num_matches = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, query) == 0) {
            printf("Record %d: %s = %s\n", i+1, records[i].name, records[i].value);
            num_matches++;
        }
    }
    if (num_matches == 0) {
        printf("No records found.\n");
    }
}

int main() {
    int num_records;
    printf("Enter number of records: ");
    scanf("%d", &num_records);

    Record records[num_records];
    read_records(records, num_records);

    char query[MAX_NAME_SIZE];
    printf("Enter query: ");
    scanf("%s", query);

    query_records(records, num_records, query);

    return 0;
}