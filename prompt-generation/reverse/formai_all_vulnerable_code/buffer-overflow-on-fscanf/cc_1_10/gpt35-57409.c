//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct student {
    int id;
    char name[20];
    char major[20];
    float gpa;
};

struct index {
    char name[20];
    int offset;
};

int compare(const void *a, const void *b) {
    return strcmp(((struct index*)a)->name, ((struct index*)b)->name);
}

int main() {
    struct student records[MAX_RECORDS];
    struct index index_records[MAX_RECORDS];
    int num_records = 0;
    int num_index_records = 0;

    // Load data from file
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file data.txt\n");
        return 1;
    }

    while (!feof(fp) && num_records < MAX_RECORDS) {
        fscanf(fp, "%d %s %s %f", &records[num_records].id,
                                records[num_records].name,
                                records[num_records].major,
                                &records[num_records].gpa);
        num_records++;
    }
    fclose(fp);

    // Create index
    for (int i = 0; i < num_records; i++) {
        strcpy(index_records[num_index_records].name, records[i].name);
        index_records[num_index_records].offset = i;
        num_index_records++;
    }

    // Sort index
    qsort(index_records, num_index_records, sizeof(struct index), compare);

    // Search for records
    char search_name[20];
    printf("Enter a name to search for (or blank line to quit):\n");
    while (fgets(search_name, sizeof(search_name), stdin)) {
        if (search_name[0] == '\n') {
            break;
        }

        int left = 0;
        int right = num_index_records - 1;
        int found = 0;

        while (left <= right) {
            int middle = (left + right) / 2;
            int cmp_result = strcmp(search_name, index_records[middle].name);

            if (cmp_result == 0) {
                // Found index record
                found = 1;
                int offset = index_records[middle].offset;
                printf("%d %s %s %f\n", records[offset].id,
                                    records[offset].name,
                                    records[offset].major,
                                    records[offset].gpa);
                break;
            } else if (cmp_result < 0) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        if (!found) {
            printf("Error: could not find record for %s\n", search_name);
        }

        printf("Enter a name to search for (or blank line to quit):\n");
    }

    printf("Exiting program...\n");

    return 0;
}