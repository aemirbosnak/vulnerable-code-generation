//FormAI DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

// Structs
typedef struct Record {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct Index {
    char key[MAX_KEY_LENGTH];
    long offset;
} Index;

// Function declarations
void indexFile(char* filename);
void insertRecord(char* filename, Record* record);
Record* getRecord(char* filename, char* key);
void printRecord(Record* record);
void printIndexFile(char* filename);

int main() {
    char* filename = "records.dat";

    // Initialize file with sample data
    Record record1 = {"key1", "value1"};
    Record record2 = {"key2", "value2"};
    Record record3 = {"key3", "value3"};
    Record record4 = {"key4", "value4"};
    Record record5 = {"key5", "value5"};

    insertRecord(filename, &record1);
    insertRecord(filename, &record2);
    insertRecord(filename, &record3);
    insertRecord(filename, &record4);
    insertRecord(filename, &record5);

    // Add indexes
    indexFile(filename);

    // Get record by key
    char key[MAX_KEY_LENGTH];
    printf("Enter key to search: ");
    scanf("%s", key);
    printf("\n");

    Record* record = getRecord(filename, key);
    if (record != NULL) {
        printf("Record for key %s:\n", key);
        printRecord(record);
    } else {
        printf("Record not found for key %s.\n", key);
    }

    // Print index file
    printf("\nIndex file contents:\n");
    printIndexFile("index.dat");

    return 0;
}

// Indexes the records in the file and writes to index.dat
void indexFile(char* filename) {
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    FILE* indexFile = fopen("index.dat", "wb");

    if (indexFile == NULL) {
        printf("Error opening index file.\n");
        exit(1);
    }

    // Get number of records in file
    fseek(fp, 0L, SEEK_END);
    int numRecords = ftell(fp) / sizeof(Record);
    rewind(fp);

    // Create index array
    Index* indices = malloc(numRecords * sizeof(Index));
    if (indices == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    // Read records and build index array
    int i = 0;
    while (i < numRecords) {
        Record record;
        fread(&record, sizeof(Record), 1, fp);

        Index index;
        strcpy(index.key, record.key);
        index.offset = ftell(fp) - sizeof(Record);

        indices[i] = index;

        i++;
    }

    // Sort index array by key
    qsort(indices, numRecords, sizeof(Index), 
        (int (*)(const void*, const void*))strcmp);

    // Write indices to index file
    fwrite(&numRecords, sizeof(int), 1, indexFile);

    for (i = 0; i < numRecords; i++) {
        fwrite(&indices[i], sizeof(Index), 1, indexFile);
    }

    // Clean up
    free(indices);
    fclose(fp);
    fclose(indexFile);
}

// Inserts a record into the file
void insertRecord(char* filename, Record* record) {
    FILE* fp;

    if (fileExists(filename)) {
        fp = fopen(filename, "ab");
    } else {
        fp = fopen(filename, "wb");
    }

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fwrite(record, sizeof(Record), 1, fp);
    fclose(fp);
}

// Returns a record by key from the file
Record* getRecord(char* filename, char* key) {
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read number of records from index file
    FILE* indexFile = fopen("index.dat", "rb");

    if (indexFile == NULL) {
        printf("Error opening index file.\n");
        exit(1);
    }

    int numRecords;
    fread(&numRecords, sizeof(int), 1, indexFile);

    // Find key in index file
    Index* indices = malloc(numRecords * sizeof(Index));
    if (indices == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    fread(indices, sizeof(Index), numRecords, indexFile);

    int lo = 0;
    int hi = numRecords - 1;
    int mid;
    int cmp;

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        cmp = strcmp(indices[mid].key, key);

        if (cmp < 0) {
            lo = mid + 1;
        } else if (cmp > 0) {
            hi = mid - 1;
        } else {
            break;
        }
    }

    // Read record from file at offset
    if (cmp == 0) {
        fseek(fp, indices[mid].offset, SEEK_SET);
        Record* record = malloc(sizeof(Record));
        fread(record, sizeof(Record), 1, fp);

        // Clean up
        free(indices);
        fclose(fp);
        fclose(indexFile);

        return record;
    } else {
        // Clean up
        free(indices);
        fclose(fp);
        fclose(indexFile);

        return NULL;
    }
}

// Prints a record to stdout
void printRecord(Record* record) {
    printf("Key: %s\nValue: %s\n", record->key, record->value);
}

// Prints the contents of the index file to stdout
void printIndexFile(char* filename) {
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    int numRecords;
    fread(&numRecords, sizeof(int), 1, fp);

    printf("Number of records: %d\n", numRecords);

    Index index;
    int i;
    for (i = 0; i < numRecords; i++) {
        fread(&index, sizeof(Index), 1, fp);
        printf("Key: %s Offset: %ld\n", index.key, index.offset);
    }

    fclose(fp);
}

// Returns true if file exists, else false
int fileExists(char* filename) {
    FILE* file;
    if (file = fopen(filename, "r")) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}