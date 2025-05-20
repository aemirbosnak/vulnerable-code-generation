//FormAI DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

struct record {
    int id;
    char name[20];
    int age;
};

struct index {
    int id;
    int offset;
};

int cmpfunc(const void* a, const void* b) {
    // Compare two index entries by their IDs
    const struct index* i = (const struct index*)a;
    const struct index* j = (const struct index*)b;
    return i->id - j->id;
}

int main() {
    FILE* fp;
    struct record records[MAX_RECORDS];
    struct index index[MAX_RECORDS];
    int num_records = 0;
    char buffer[100];

    // Open the data file for reading
    fp = fopen("data.txt", "r");
    if (!fp) {
        printf("Error: could not open data file\n");
        return 1;
    }

    // Read in the records from the data file
    while (fgets(buffer, sizeof(buffer), fp)) {
        sscanf(buffer, "%d %s %d", &records[num_records].id, records[num_records].name, &records[num_records].age);
        num_records++;
        if (num_records == MAX_RECORDS) {
            break;
        }
    }

    // Close the data file
    fclose(fp);

    // Create an index of the records
    for (int i = 0; i < num_records; i++) {
        index[i].id = records[i].id;
        index[i].offset = i;
    }

    // Sort the index by ID
    qsort(index, num_records, sizeof(index[0]), cmpfunc);

    // Search for a record by ID
    int search_id = 3;
    int lo = 0;
    int hi = num_records - 1;
    int mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (index[mid].id == search_id) {
            // Found the record, print it out
            printf("Record found:\n");
            printf("ID: %d\n", records[index[mid].offset].id);
            printf("Name: %s\n", records[index[mid].offset].name);
            printf("Age: %d\n", records[index[mid].offset].age);
            break;
        } else if (index[mid].id < search_id) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return 0;
}