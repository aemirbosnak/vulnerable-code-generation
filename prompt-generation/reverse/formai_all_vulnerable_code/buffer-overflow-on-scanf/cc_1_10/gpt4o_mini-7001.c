//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_STRING_LENGTH 100

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    double value;
} Record;

typedef struct {
    int id;
    int record_index;
} IndexEntry;

typedef struct {
    IndexEntry entries[MAX_RECORDS];
    int count;
} Index;

// Function to create sample records
void create_sample_records(Record records[], int *record_count) {
    *record_count = 5;
    records[0] = (Record){1, "Alpha", 12.5};
    records[1] = (Record){2, "Beta", 15.0};
    records[2] = (Record){3, "Gamma", 14.0};
    records[3] = (Record){4, "Delta", 20.5};
    records[4] = (Record){5, "Epsilon", 11.75};
}

// Function to build the index
void build_index(Record records[], int record_count, Index *index) {
    index->count = 0;
    for (int i = 0; i < record_count; i++) {
        index->entries[index->count++] = (IndexEntry){records[i].id, i};
    }
}

// Comparison function for sorting index entries
int compare_index_entries(const void *a, const void *b) {
    IndexEntry *entry_a = (IndexEntry *)a;
    IndexEntry *entry_b = (IndexEntry *)b;
    return entry_a->id - entry_b->id;
}

// Function to sort the index
void sort_index(Index *index) {
    qsort(index->entries, index->count, sizeof(IndexEntry), compare_index_entries);
}

// Function to query a record by its ID using the index
Record* query_index(Index *index, Record records[], int target_id) {
    for (int i = 0; i < index->count; i++) {
        if (index->entries[i].id == target_id) {
            return &records[index->entries[i].record_index];
        }
    }
    return NULL; // Not found
}

int main() {
    Record records[MAX_RECORDS];
    int record_count = 0;

    // Step 1: Create sample records
    create_sample_records(records, &record_count);
    
    // Step 2: Build the index
    Index index;
    build_index(records, record_count, &index);
    
    // Step 3: Sort the index
    sort_index(&index);

    // Step 4: Query the records
    int query_id;
    printf("Enter ID to query (1 - 5): ");
    scanf("%d", &query_id);
    
    Record *queried_record = query_index(&index, records, query_id);
    if (queried_record != NULL) {
        printf("Record Found: ID = %d, Name = %s, Value = %.2f\n", 
               queried_record->id, queried_record->name, queried_record->value);
    } else {
        printf("Record not found for ID = %d\n", query_id);
    }

    // Program summary
    printf("\nSummary of Records:\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID = %d, Name = %s, Value = %.2f\n", 
               records[i].id, records[i].name, records[i].value);
    }
    
    return 0;
}