//Falcon-180B DATASET v1.0 Category: Database querying ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char field1[MAX_FIELD_SIZE];
    char field2[MAX_FIELD_SIZE];
    int field3;
} Record;

void read_records(Record* records) {
    FILE* file = fopen("records.txt", "r");
    if (file == NULL) {
        printf("Error: could not open records file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d\n", records[count].field1, records[count].field2, &records[count].field3) == 3 && count < MAX_RECORDS) {
        count++;
    }

    fclose(file);
}

void write_records(Record* records) {
    FILE* file = fopen("records.txt", "w");
    if (file == NULL) {
        printf("Error: could not open records file.\n");
        exit(1);
    }

    for (int i = 0; i < MAX_RECORDS; i++) {
        if (records[i].field1[0]!= '\0') {
            fprintf(file, "%s %s %d\n", records[i].field1, records[i].field2, records[i].field3);
        }
    }

    fclose(file);
}

void sort_records(Record* records) {
    for (int i = 0; i < MAX_RECORDS - 1; i++) {
        for (int j = i + 1; j < MAX_RECORDS; j++) {
            if (strcmp(records[i].field1, records[j].field1) > 0) {
                Record temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
}

int main() {
    Record records[MAX_RECORDS];

    read_records(records);

    printf("Sorted records:\n");
    sort_records(records);
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%s %s %d\n", records[i].field1, records[i].field2, records[i].field3);
    }

    write_records(records);

    return 0;
}