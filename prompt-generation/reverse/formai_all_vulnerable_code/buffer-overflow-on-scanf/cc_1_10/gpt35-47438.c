//FormAI DATASET v1.0 Category: Database Indexing System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for record
typedef struct {
    int id;
    char name[20];
    char occupation[20];
    char location[20];
} Record;

// Define structure for index entry
typedef struct {
    int id;
    int offset;
} IndexEntry;

// Define structure for index
typedef struct {
    IndexEntry* entries;
    int size;
} Index;

// Function to create new index
Index* createIndex(int capacity) {
    Index* index = (Index*)malloc(sizeof(Index));
    index->entries = (IndexEntry*)malloc(sizeof(IndexEntry) * capacity);
    index->size = 0;
    return index;
}

// Function to add entry to index
void addToIndex(Index* index, int id, int offset) {
    IndexEntry entry = { id, offset };
    index->entries[index->size++] = entry;
}

// Function to get offset from index using id
int getOffsetFromIndex(Index* index, int id) {
    for (int i = 0; i < index->size; i++) {
        if (index->entries[i].id == id) {
            return index->entries[i].offset;
        }
    }
    return -1; // Not found
}

// Function to print record
void printRecord(Record* record) {
    printf("ID: %d, Name: %s, Occupation: %s, Location: %s\n", record->id, record->name, record->occupation, record->location);
}

// Main function
int main() {
    Index* index = createIndex(10); // Create index with capacity of 10 entries
    
    FILE* file = fopen("records.dat", "wb+"); // Open binary file for read/write
    
    // Add some sample records
    Record record1 = { 1, "John", "Blacksmith", "Castle" };
    Record record2 = { 2, "Jane", "Weaver", "Town" };
    Record record3 = { 3, "Edward", "Farmer", "Village" };
    
    fwrite(&record1, sizeof(Record), 1, file);
    addToIndex(index, record1.id, ftell(file) - sizeof(Record));
    
    fwrite(&record2, sizeof(Record), 1, file);
    addToIndex(index, record2.id, ftell(file) - sizeof(Record));
    
    fwrite(&record3, sizeof(Record), 1, file);
    addToIndex(index, record3.id, ftell(file) - sizeof(Record));
    
    // User interface
    int choice = 0;
    do {
        printf("Enter ID to search (0 to quit): ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice != 0) {
            int offset = getOffsetFromIndex(index, choice);
            if (offset != -1) {
                fseek(file, offset, SEEK_SET);
                Record record;
                fread(&record, sizeof(Record), 1, file);
                printRecord(&record);
            }
            else {
                printf("Record not found\n");
            }
        }
    } while (choice != 0);
    
    fclose(file);
    free(index->entries);
    free(index);
    
    return 0;
}