//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100     // maximum number of records
#define INDEX_SIZE 10 // size of index table

typedef struct Record {   // record structure
    int id;
    char name[20];
    char address[50];
    int age;
} Record;

typedef struct Index {   // index structure
    int key;
    int offset;
} Index;

int compare(const void *a, const void *b) {    // compare function for qsort
    return ((Index*)a)->key - ((Index*)b)->key;
}

void printRecord(Record record) {   // function to print a record
    printf("ID: %d\nName: %s\nAddress: %s\nAge: %d\n\n", record.id, record.name, record.address, record.age);
}

int main() {
    Record records[SIZE];   // array to store records
    Index indexTable[INDEX_SIZE];   // array to store index table
    FILE *fp;   // file pointer
    int i, j, k;
    
    // initialize index table
    for (i = 0; i < INDEX_SIZE; i++) {
        indexTable[i].key = -1;
        indexTable[i].offset = -1;
    }
    
    // read records from file and update index table
    fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 0;
    }
    for (i = 0; i < SIZE; i++) {
        fscanf(fp, "%d %s %s %d", &records[i].id, records[i].name, records[i].address, &records[i].age);
        if (i % (SIZE / INDEX_SIZE) == 0) {
            indexTable[i / (SIZE / INDEX_SIZE)].key = records[i].id;
            indexTable[i / (SIZE / INDEX_SIZE)].offset = ftell(fp) - 20;
        }
    }
    fclose(fp);
    
    // sort index table
    qsort(indexTable, INDEX_SIZE, sizeof(Index), compare);
    
    // search for a record
    int searchKey;
    printf("Enter ID to search: ");
    scanf("%d", &searchKey);
    int found = 0;
    for (i = 0; i < INDEX_SIZE; i++) {
        if (indexTable[i].key == searchKey) {
            fp = fopen("records.txt", "r");
            fseek(fp, indexTable[i].offset, SEEK_SET);
            fscanf(fp, "%d %s %s %d", &records[i].id, records[i].name, records[i].address, &records[i].age);
            printRecord(records[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Error: record not found\n");
    }
    
    return 0;
}