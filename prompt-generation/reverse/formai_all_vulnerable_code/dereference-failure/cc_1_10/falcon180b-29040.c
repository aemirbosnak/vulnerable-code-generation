//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a database record
typedef struct {
    int id;
    char name[100];
} Record;

// Define the structure of a database index
typedef struct {
    int num_records;
    Record *records;
} Index;

// Function to compare two records by ID
int compare_records(const void *a, const void *b) {
    Record *record_a = (Record *)a;
    Record *record_b = (Record *)b;
    return (record_a->id - record_b->id);
}

// Function to create a new index
Index *create_index(int num_records) {
    Index *index = (Index *)malloc(sizeof(Index));
    index->num_records = num_records;
    index->records = (Record *)malloc(num_records * sizeof(Record));
    return index;
}

// Function to add a record to an index
void add_record(Index *index, Record *record) {
    int i;
    for (i = 0; i < index->num_records; i++) {
        if (record->id < index->records[i].id) {
            memmove(&(index->records[i]), &(index->records[i+1]), (index->num_records - i - 1) * sizeof(Record));
            break;
        }
    }
    memcpy(&(index->records[i]), record, sizeof(Record));
    index->num_records++;
}

// Function to search an index for a record by ID
Record *search_index(Index *index, int id) {
    int i = 0;
    while (i < index->num_records) {
        if (id == index->records[i].id) {
            return &(index->records[i]);
        }
        i++;
    }
    return NULL;
}

// Main function to demonstrate the indexing system
int main() {
    // Create a new index
    Index *index = create_index(10);

    // Add some records to the index
    Record record1 = {1, "John"};
    Record record2 = {2, "Jane"};
    Record record3 = {3, "Bob"};
    add_record(index, &record1);
    add_record(index, &record2);
    add_record(index, &record3);

    // Search the index for a record by ID
    Record *result = search_index(index, 2);
    if (result!= NULL) {
        printf("Found record: %s\n", result->name);
    } else {
        printf("Record not found.\n");
    }

    // Free the memory used by the index
    free(index->records);
    free(index);

    return 0;
}