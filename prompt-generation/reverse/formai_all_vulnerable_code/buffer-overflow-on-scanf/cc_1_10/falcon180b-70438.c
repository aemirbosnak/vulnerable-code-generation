//Falcon-180B DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_VALUE_LEN 256

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

void read_records(Record *records, int num_records) {
    FILE *fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("Error opening records file\n");
        exit(1);
    }

    for (int i = 0; i < num_records; i++) {
        Record record;
        if (fscanf(fp, "%s %s\n", record.name, record.value)!= 2) {
            printf("Error reading record %d\n", i+1);
            exit(1);
        }
        records[i] = record;
    }

    fclose(fp);
}

int main() {
    int num_records;
    printf("Enter number of records: ");
    scanf("%d", &num_records);

    Record records[num_records];
    read_records(records, num_records);

    printf("Enter query:\n");
    char query[MAX_VALUE_LEN];
    fgets(query, MAX_VALUE_LEN, stdin);

    int num_matches = 0;
    for (int i = 0; i < num_records; i++) {
        if (strstr(records[i].value, query)!= NULL) {
            printf("%s\n", records[i].name);
            num_matches++;
        }
    }

    if (num_matches == 0) {
        printf("No matches found\n");
    }

    return 0;
}