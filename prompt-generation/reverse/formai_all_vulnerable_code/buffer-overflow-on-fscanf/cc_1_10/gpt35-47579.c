//FormAI DATASET v1.0 Category: Database Indexing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define maximum size for indexing array
#define MAX_SIZE 100

// Define structure for database records
struct Record {
    int id;
    char name[20];
    int age;
};

// Define structure for index key
struct Key {
    int id;
    int position;
};

// Function to compare two keys
int compareKeys(const void* a, const void* b) {
    return ((struct Key*)a)->id - ((struct Key*)b)->id;
}

// Main function
int main() {
    // Define variables
    struct Record records[MAX_SIZE];
    struct Key keys[MAX_SIZE];
    int numRecords, numKeys, i, j, k;
    FILE* inputFile, * indexFile;

    // Read records from input file
    inputFile = fopen("input.dat", "r");
    if (inputFile == NULL) {
        printf("Error: input file not found.\n");
        exit(1);
    }
    numRecords = 0;
    while (fscanf(inputFile, "%d%s%d", &records[numRecords].id, records[numRecords].name, &records[numRecords].age) != EOF) {
        numRecords++;
    }

    // Generate index keys and sort them
    numKeys = 0;
    for (i = 0; i < numRecords; i++) {
        keys[numKeys].id = records[i].id;
        keys[numKeys].position = i;
        numKeys++;
    }
    qsort(keys, numKeys, sizeof(struct Key), compareKeys);

    // Write index to file
    indexFile = fopen("index.dat", "w");
    if (indexFile == NULL) {
        printf("Error: cannot create index file.\n");
        exit(1);
    }
    fprintf(indexFile, "%d\n", numKeys);
    for (i = 0; i < numKeys; i++) {
        fprintf(indexFile, "%d %d\n", keys[i].id, keys[i].position);
    }
    fclose(indexFile);

    // Search for record by key
    int searchKey;
    printf("Enter search key: ");
    scanf("%d", &searchKey);
    // Binary search for key in index
    int lo = 0, hi = numKeys - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (keys[mid].id == searchKey) {
            printf("Record found:\n");
            printf("ID: %d\nName: %s\nAge: %d\n", records[keys[mid].position].id, records[keys[mid].position].name, records[keys[mid].position].age);
            break;
        }
        else if (keys[mid].id < searchKey) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    if (lo > hi) {
        printf("Record not found.\n");
    }

    return 0;
}