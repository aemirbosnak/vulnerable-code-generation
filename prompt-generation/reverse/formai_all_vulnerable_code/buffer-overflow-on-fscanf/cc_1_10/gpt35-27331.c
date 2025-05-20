//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REC_SIZE 100
#define MAX_NUM_RECS 100

// Structure defining a record
typedef struct {
    int id;
    char name[MAX_REC_SIZE];
    char address[MAX_REC_SIZE];
} Record;

// Structure defining an index entry
typedef struct {
    int key;
    int rec_no;
} Index;

// Function to compare two index entries by their keys
int CompareIndexEntries(const void* a, const void* b) {
    Index* x = (Index*)a;
    Index* y = (Index*)b;
    return x->key - y->key;
}

// Function to build the index from the records
void BuildIndex(Record records[], int num_recs, Index index[]) {
    int i;
    for (i = 0; i < num_recs; i++) {
        index[i].key = records[i].id;
        index[i].rec_no = i;
    }
    qsort(index, num_recs, sizeof(Index), CompareIndexEntries);
}

// Function to search for a record in the database
void SearchDatabase(Record records[], int num_recs, Index index[]) {
    int key, i;
    printf("Enter the ID of the record you want to search for: ");
    scanf("%d", &key);
    
    // Binary search
    int low = 0, high = num_recs - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (index[mid].key == key) {
            printf("Record found:\n");
            printf("ID: %d\nName: %s\nAddress: %s\n", records[index[mid].rec_no].id, records[index[mid].rec_no].name, records[index[mid].rec_no].address);
            return;
        } else if (index[mid].key < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Record not found.\n");
}

int main() {
    Record records[MAX_NUM_RECS];
    Index index[MAX_NUM_RECS];
    int num_recs, i;
    
    // Read records from file
    FILE* fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    num_recs = 0;
    while (fscanf(fp, "%d %s %s", &records[num_recs].id, records[num_recs].name, records[num_recs].address) == 3) {
        num_recs++;
    }
    fclose(fp);
    
    // Build index
    BuildIndex(records, num_recs, index);
    
    // Search database
    SearchDatabase(records, num_recs, index);
    
    return 0;
}