//FormAI DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define the structure of the record
struct Record {
    int id;
    char name[30];
    int age;
};

// Define the structure of the index entry
struct IndexEntry {
    int key;
    int offset;
};

// Define the structure of the index file
struct IndexFile {
    char* name;
    FILE* file;
    struct IndexEntry entries[MAX_RECORDS];
    int count;
};

// Function to print the menu
void print_menu() {
    printf("1. Create index file\n");
    printf("2. Add record to file\n");
    printf("3. Search record by ID\n");
    printf("4. Delete record by ID\n");
    printf("5. Exit\n");
}

// Function to create an index file
void create_index_file(struct IndexFile* index_file) {
    // Open the data file
    FILE* data_file = fopen("data.txt", "r");
    
    // Read records from the data file and add them to the index
    int offset = 0;
    struct Record record;
    while (fread(&record, sizeof(struct Record), 1, data_file) > 0) {
        index_file->entries[index_file->count].key = record.id;
        index_file->entries[index_file->count].offset = offset;
        index_file->count++;
        offset += sizeof(struct Record);
    }
    
    // Sort the index entries by ID
    for (int i = 0; i < index_file->count - 1; i++) {
        for (int j = i + 1; j < index_file->count; j++) {
            if (index_file->entries[i].key > index_file->entries[j].key) {
                struct IndexEntry temp = index_file->entries[i];
                index_file->entries[i] = index_file->entries[j];
                index_file->entries[j] = temp;
            }
        }
    }
    
    // Save the index file to disk
    fwrite(&index_file->count, sizeof(int), 1, index_file->file);
    fwrite(&index_file->entries, sizeof(struct IndexEntry), index_file->count, index_file->file);
    
    printf("Index file %s has been created\n", index_file->name);
    
    // Close the data file
    fclose(data_file);
}

// Function to add a record to the data file and index file
void add_record(struct IndexFile* index_file) {
    // Open the data file in append mode
    FILE* data_file = fopen("data.txt", "a");

    // Create the new record
    struct Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter name: ");
    scanf("%s", record.name);
    printf("Enter age: ");
    scanf("%d", &record.age);

    // Write the new record to the data file
    fwrite(&record, sizeof(struct Record), 1, data_file);

    // Update the index file
    index_file->entries[index_file->count].key = record.id;
    index_file->entries[index_file->count].offset = ftell(data_file) - sizeof(struct Record);
    index_file->count++;

    // Sort the index entries by ID
    for (int i = 0; i < index_file->count - 1; i++) {
        for (int j = i + 1; j < index_file->count; j++) {
            if (index_file->entries[i].key > index_file->entries[j].key) {
                struct IndexEntry temp = index_file->entries[i];
                index_file->entries[i] = index_file->entries[j];
                index_file->entries[j] = temp;
            }
        }
    }

    // Save the updated index file to disk
    fseek(index_file->file, 0, SEEK_SET);
    fwrite(&index_file->count, sizeof(int), 1, index_file->file);
    fwrite(&index_file->entries, sizeof(struct IndexEntry), index_file->count, index_file->file);

    printf("Record has been added to the file\n");

    // Close the data file
    fclose(data_file);
}

// Function to search for a record by ID
void search_record(struct IndexFile* index_file) {
    int id;
    printf("Enter ID to search for: ");
    scanf("%d", &id);

    // Binary Search Algorithm
    int lo = 0;
    int hi = index_file->count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (index_file->entries[mid].key == id) {
            // Open the data file and read the record
            FILE* data_file = fopen("data.txt", "r");
            fseek(data_file, index_file->entries[mid].offset, SEEK_SET);
            struct Record record;
            fread(&record, sizeof(struct Record), 1, data_file);
            printf("Record found: %d %s %d\n", record.id, record.name, record.age);
            fclose(data_file);
            return;
        }
        else if (index_file->entries[mid].key < id) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    printf("Record not found\n");
}

// Function to delete a record by ID
void delete_record(struct IndexFile* index_file) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    // Binary Search Algorithm
    int lo = 0;
    int hi = index_file->count - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (index_file->entries[mid].key == id) {
            // Open the data file and read the record
            FILE* data_file = fopen("data.txt", "r");
            fseek(data_file, index_file->entries[mid].offset, SEEK_SET);
            struct Record record;
            fread(&record, sizeof(struct Record), 1, data_file);
            fclose(data_file);

            // Open the data file in read-write mode and update it
            data_file = fopen("data.txt", "r+");
            fseek(data_file, index_file->entries[mid].offset, SEEK_SET);
            fwrite(&record, sizeof(struct Record), 1, data_file);
            fclose(data_file);

            // Remove the index entry from the index file
            for (int i = mid; i < index_file->count - 1; i++) {
                index_file->entries[i] = index_file->entries[i + 1];
            }
            index_file->count--;

            // Save the updated index file to disk
            fseek(index_file->file, 0, SEEK_SET);
            fwrite(&index_file->count, sizeof(int), 1, index_file->file);
            fwrite(&index_file->entries, sizeof(struct IndexEntry), index_file->count, index_file->file);

            printf("Record with ID %d has been deleted\n", id);
            return;
        }
        else if (index_file->entries[mid].key < id) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    printf("Record not found\n");
}

int main() {
    // Create the index file
    struct IndexFile index_file;
    index_file.name = "index.bin";
    index_file.file = fopen(index_file.name, "wb+");
    index_file.count = 0;
    create_index_file(&index_file);

    // Menu loop
    int choice;
    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_index_file(&index_file);
                break;
            case 2:
                add_record(&index_file);
                break;
            case 3:
                search_record(&index_file);
                break;
            case 4:
                delete_record(&index_file);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 5);

    // Close the index file
    fclose(index_file.file);

    return 0;
}