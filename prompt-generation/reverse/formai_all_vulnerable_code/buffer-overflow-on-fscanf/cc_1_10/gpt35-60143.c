//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

// structure to hold each record
typedef struct record {
    int id;
    char name[100];
    char email[100];
} Record;

// structure to hold each index entry
typedef struct index_entry {
    int key;
    int offset;
} IndexEntry;

// structure to hold the index table
typedef struct index_table {
    int size;
    IndexEntry *entries;
} IndexTable;

// function prototypes
void add_record(IndexTable *index_table, Record *record, FILE *fp_data, FILE *fp_index);
Record *search(IndexTable *index_table, int key, FILE *fp_data);

int main() {
    FILE *fp_data, *fp_index;
    IndexTable *index_table;
    Record *record;
    int choice, key;

    // allocate memory for the index table
    index_table = (IndexTable*) malloc(sizeof(IndexTable));

    // open the data file pointed by fp_data
    fp_data = fopen("data.txt", "r");

    // open the index file pointed by fp_index
    fp_index = fopen("index.txt", "w+");

    if (!fp_data || !fp_index) {
        printf("Error opening file!");
        exit(1);
    }

    // initialize the index table
    index_table->size = 0;
    index_table->entries = NULL;

    // read the records from the data file and add them to the database
    while (!feof(fp_data)) {
        // create a new record
        record = (Record*) malloc(sizeof(Record));
        if (!record) {
            printf("Memory allocation error!");
            exit(1);
        }

        // read the record from the file
        fscanf(fp_data, "%d,%[^,],%[^\n]", &record->id, record->name, record->email);

        // add the record to the database
        add_record(index_table, record, fp_data, fp_index);
    }

    do {
        // display the menu
        printf("\nDatabase Indexing System\n");
        printf("=========================\n");
        printf("1. Search\n");
        printf("2. Exit\n");

        // get the user's choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // get the key to search
                printf("\nEnter the key to search: ");
                scanf("%d", &key);

                // search the record using the index table
                record = search(index_table, key, fp_data);

                if (record) {
                    // display the record
                    printf("Record found!\n");
                    printf("ID: %d\nName: %s\nEmail: %s\n", record->id, record->name, record->email);
                } else {
                    // record not found
                    printf("Record not found!\n");
                }

                break;

            case 2:
                // exit the program
                printf("\nExiting program...\n");
                break;

            default:
                // invalid choice
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 2);

    // free the memory allocated for the index table
    free(index_table->entries);
    free(index_table);

    // close the files
    fclose(fp_data);
    fclose(fp_index);

    return 0;
}

void add_record(IndexTable *index_table, Record *record, FILE *fp_data, FILE *fp_index) {
    // add the record to the data file
    fseek(fp_data, 0, SEEK_END);
    fprintf(fp_data, "%d,%s,%s\n", record->id, record->name, record->email);

    // add the index entry to the index table
    index_table->size++;
    index_table->entries = (IndexEntry*) realloc(index_table->entries, index_table->size * sizeof(IndexEntry));
    index_table->entries[index_table->size - 1].key = record->id;
    index_table->entries[index_table->size - 1].offset = ftell(fp_data) - strlen(record->name) - strlen(record->email) - 3;

    // write the index entry to the index file
    fprintf(fp_index, "%d %d\n", index_table->entries[index_table->size - 1].key, index_table->entries[index_table->size - 1].offset);
}

Record *search(IndexTable *index_table, int key, FILE *fp_data) {
    int i, offset;
    Record *record = NULL;

    // perform binary search on the index table
    int left = 0;
    int right = index_table->size - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (index_table->entries[middle].key == key) {
            // record found
            offset = index_table->entries[middle].offset;
            break;
        } else if (index_table->entries[middle].key < key) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    if (left > right) {
        // record not found
        return NULL;
    }

    // seek to the offset of the record in the data file
    fseek(fp_data, offset, SEEK_SET);

    // create a new record
    record = (Record*) malloc(sizeof(Record));
    if (!record) {
        printf("Memory allocation error!");
        exit(1);
    }

    // read the record from the data file
    fscanf(fp_data, "%d,%[^,],%[^\n]", &record->id, record->name, record->email);

    return record;
}