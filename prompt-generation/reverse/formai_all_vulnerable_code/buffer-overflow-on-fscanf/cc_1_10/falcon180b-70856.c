//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 32
#define MAX_VALUE_LEN 1024

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} Record;

void read_records(Record* records, int num_records) {
    FILE* fp = fopen("records.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open records file.\n");
        exit(1);
    }

    int i = 0;
    while (i < num_records && fscanf(fp, "%s %s\n", records[i].name, records[i].value) == 2) {
        i++;
    }

    fclose(fp);
}

void write_records(Record* records, int num_records) {
    FILE* fp = fopen("records.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open records file.\n");
        exit(1);
    }

    for (int i = 0; i < num_records; i++) {
        fprintf(fp, "%s %s\n", records[i].name, records[i].value);
    }

    fclose(fp);
}

int compare_names(const void* a, const void* b) {
    const Record* ra = (const Record*)a;
    const Record* rb = (const Record*)b;
    return strcmp(ra->name, rb->name);
}

int compare_values(const void* a, const void* b) {
    const Record* ra = (const Record*)a;
    const Record* rb = (const Record*)b;
    return strcmp(ra->value, rb->value);
}

int main() {
    int num_records;
    printf("Enter the number of records: ");
    scanf("%d", &num_records);

    Record records[num_records];
    read_records(records, num_records);

    qsort(records, num_records, sizeof(Record), compare_names);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s: %s\n", records[i].name, records[i].value);
    }

    qsort(records, num_records, sizeof(Record), compare_values);

    printf("\nSorted by value:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s: %s\n", records[i].name, records[i].value);
    }

    write_records(records, num_records);

    return 0;
}