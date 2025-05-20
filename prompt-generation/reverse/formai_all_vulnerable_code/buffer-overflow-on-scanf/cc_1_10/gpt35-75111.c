//FormAI DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100     // Maximum number of allowed records 
#define MAX_KEY_LEN 20      // Maximum length of key

// Structure for each record
typedef struct {
    char key[MAX_KEY_LEN];
    int value;
} Record;

// Structure for the index
typedef struct {
    char key[MAX_KEY_LEN];
    int offset;
} Index;

// Function to compare two keys
int compareKeys(const void *p1, const void *p2) {
    return strcmp(((Record*)p1)->key, ((Record*)p2)->key);
}

// Function to compare two index keys
int compareIndexKeys(const void *p1, const void *p2) {
    return strcmp(((Index*)p1)->key, ((Index*)p2)->key);
}

// Function to read record from file
Record readRecord(FILE *fp) {
    Record record;
    fscanf(fp, "%s %d", record.key, &record.value);
    return record;
}

// Function to write record to file
void writeRecord(FILE *fp, Record record) {
    fprintf(fp, "%s %d\n", record.key, record.value);
}

// Function to generate index from records
void generateIndex(Index *index, Record *records, int numRecords) {
    int i;
    for(i = 0; i < numRecords; i++) {
        strcpy(index[i].key, records[i].key);
        index[i].offset = i * sizeof(Record);
    }
    qsort(index, numRecords, sizeof(Index), compareIndexKeys);
}

// Function to search index for given key
int searchIndex(Index *index, char *key, int numRecords) {
    int lo = 0, hi = numRecords - 1, mid;
    while(lo <= hi) {
        mid = (lo + hi) / 2;
        if(strcmp(index[mid].key, key) == 0)
            return index[mid].offset;
        else if(strcmp(index[mid].key, key) < 0)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

void displayRecords(Record *records, int numRecords);

int main() {
    FILE *fp = fopen("records.txt", "r+");
    if(fp == NULL) {
        fprintf(stderr, "Error opening file");
        exit(1);
    }
    Record records[MAX_RECORDS];
    Index index[MAX_RECORDS];
    int numRecords = 0, choice, offset;
    char key[MAX_KEY_LEN];
    while(1) {
        printf("\n1 - Add Record\n2 - Search Record\n3 - Display All Records\n4 - Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(numRecords >= MAX_RECORDS) {
                    printf("Maximum limit of records exceeded\n");
                    continue;
                }
                printf("Enter record key: ");
                scanf("%s", records[numRecords].key);
                printf("Enter record value: ");
                scanf("%d", &records[numRecords].value);
                numRecords++;
                generateIndex(index, records, numRecords);
                fseek(fp, 0, SEEK_SET);
                qsort(records, numRecords, sizeof(Record), compareKeys);
                for(int i = 0; i < numRecords; i++) {
                    writeRecord(fp, records[i]);
                }
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%s", key);
                offset = searchIndex(index, key, numRecords);
                if(offset == -1) {
                    printf("Record not found\n");
                }
                else {
                    fseek(fp, offset, SEEK_SET);
                    Record record = readRecord(fp);
                    printf("Record found:\nKey: %s  Value: %d\n", record.key, record.value);
                }
                break;
            case 3:
                displayRecords(records, numRecords);
                break;
            case 4:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to display all records
void displayRecords(Record *records, int numRecords) {
    printf("Records:\n");
    for(int i = 0; i < numRecords; i++) {
        printf("Key: %s  Value: %d\n", records[i].key, records[i].value);
    }
}