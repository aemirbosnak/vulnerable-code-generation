//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_RECORDS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

int compare_names(const void* a, const void* b) {
    const char* name1 = ((const Record*)a)->name;
    const char* name2 = ((const Record*)b)->name;
    return strcmp(name1, name2);
}

int compare_ages(const void* a, const void* b) {
    const Record* record1 = (const Record*)a;
    const Record* record2 = (const Record*)b;
    return record1->age - record2->age;
}

void sort_records(Record* records, int num_records, int (*comparator)(const void*, const void*)) {
    qsort(records, num_records, sizeof(Record), comparator);
}

int main() {
    Record records[MAX_NUM_RECORDS];
    int num_records = 0;

    while (num_records < MAX_NUM_RECORDS && fgets(records[num_records].name, MAX_NAME_LENGTH, stdin)!= NULL) {
        sscanf(records[num_records].name, "%s %d", records[num_records].name, &records[num_records].age);
        num_records++;
    }

    sort_records(records, num_records, compare_names);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s %d\n", records[i].name, records[i].age);
    }

    sort_records(records, num_records, compare_ages);

    printf("\nSorted by age:\n");
    for (int i = 0; i < num_records; i++) {
        printf("%s %d\n", records[i].name, records[i].age);
    }

    return 0;
}