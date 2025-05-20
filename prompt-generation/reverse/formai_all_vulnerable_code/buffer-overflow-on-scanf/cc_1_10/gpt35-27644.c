//FormAI DATASET v1.0 Category: Database Indexing System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 1000 // Maximum number of records supported by the system
#define MAX_NAME_LENGTH 50 // Maximum length of record name
#define MAX_PHONE_LENGTH 15 // Maximum length of phone number string

// Data structure representing a single record
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} record_t;

// Data structure representing the database index
typedef struct {
    char name[MAX_NAME_LENGTH];
    long offset; // offset of the record in the file
} index_t;

// Function to add a new record to the database
void addRecord(FILE* fp, index_t* index, int* numRecords) {
    record_t record;
    printf("Enter name: ");
    fgets(record.name, MAX_NAME_LENGTH, stdin);
    record.name[strcspn(record.name, "\n")] = 0; // Remove newline character
    printf("Enter phone number: ");
    fgets(record.phone, MAX_PHONE_LENGTH, stdin);
    record.phone[strcspn(record.phone, "\n")] = 0; // Remove newline character
    
    // Write record to file
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp);
    fwrite(&record, sizeof(record_t), 1, fp);
    
    // Add new index entry
    strcpy(index[*numRecords].name, record.name);
    index[*numRecords].offset = offset;
    *numRecords = (*numRecords) + 1;
}

// Function to search for a record by name
void searchByName(FILE* fp, index_t* index, int numRecords) {
    char query[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(query, MAX_NAME_LENGTH, stdin);
    query[strcspn(query, "\n")] = 0; // Remove newline character
    
    // Binary search through the index
    int lo = 0, hi = numRecords - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cmp = strcmp(index[mid].name, query);
        if (cmp == 0) {
            fseek(fp, index[mid].offset, SEEK_SET);
            record_t record;
            fread(&record, sizeof(record_t), 1, fp);
            printf("Name: %s\nPhone: %s\n", record.name, record.phone);
            return;
        } else if (cmp < 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("Record not found.\n");
}

// Main function
int main() {
    // Open data file and index file
    FILE* fp = fopen("data.bin", "wb+");
    FILE* indexFile = fopen("index.bin", "wb+");
    if (fp == NULL || indexFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }
    
    // Initialize index
    index_t index[MAX_RECORDS];
    int numRecords = 0;

    // Menu loop
    while (1) {
        printf("\n1. Add record\n2. Search by name\n3. Exit\nEnter choice: ");
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                addRecord(fp, index, &numRecords);
                break;
            case 2:
                searchByName(fp, index, numRecords);
                break;
            case 3:
                fclose(fp);
                fclose(indexFile);
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Write index to file after every operation
        fseek(indexFile, 0, SEEK_SET);
        fwrite(index, sizeof(index_t), numRecords, indexFile);
    }
}