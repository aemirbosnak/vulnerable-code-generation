//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a record in the database
typedef struct record {
    int id;
    char name[50];
    int age;
} record;

// Structure to store an index entry
typedef struct index_entry {
    int id;
    int offset;
} index_entry;

// Create a new database
int create_database(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }

    // Write the header to the database file
    int header[2] = {0, 0};
    fwrite(header, sizeof(int), 2, fp);

    // Close the database file
    fclose(fp);

    return 0;
}

// Open an existing database
FILE *open_database(char *filename) {
    FILE *fp = fopen(filename, "rb+");
    if (fp == NULL) {
        return NULL;
    }

    // Read the header from the database file
    int header[2];
    fread(header, sizeof(int), 2, fp);

    // Return the database file pointer
    return fp;
}

// Close a database
void close_database(FILE *fp) {
    fclose(fp);
}

// Insert a record into the database
int insert_record(FILE *fp, record *record) {
    // Get the current position in the database file
    int offset = ftell(fp);

    // Write the record to the database file
    fwrite(record, sizeof(record), 1, fp);

    // Update the header of the database file
    int header[2];
    fseek(fp, 0, SEEK_SET);
    fread(header, sizeof(int), 2, fp);
    header[0]++;
    header[1] = offset;
    fseek(fp, 0, SEEK_SET);
    fwrite(header, sizeof(int), 2, fp);

    return 0;
}

// Search for a record in the database using an index
int search_record_by_index(FILE *fp, int id) {
    // Read the header from the database file
    int header[2];
    fread(header, sizeof(int), 2, fp);

    // Read the index from the database file
    index_entry *index = malloc(sizeof(index_entry) * header[0]);
    fseek(fp, header[1], SEEK_SET);
    fread(index, sizeof(index_entry), header[0], fp);

    // Search for the record in the index
    int i;
    for (i = 0; i < header[0]; i++) {
        if (index[i].id == id) {
            return index[i].offset;
        }
    }

    // Record not found
    return -1;
}

// Search for a record in the database using a linear search
int search_record_by_linear_search(FILE *fp, int id) {
    // Read the header from the database file
    int header[2];
    fread(header, sizeof(int), 2, fp);

    // Search for the record in the database file
    int i;
    for (i = 0; i < header[0]; i++) {
        record record;
        fseek(fp, header[1] + i * sizeof(record), SEEK_SET);
        fread(&record, sizeof(record), 1, fp);

        if (record.id == id) {
            return i;
        }
    }

    // Record not found
    return -1;
}

// Delete a record from the database
int delete_record(FILE *fp, int id) {
    // Get the offset of the record in the database file
    int offset = search_record_by_index(fp, id);
    if (offset == -1) {
        return -1;
    }

    // Overwrite the record with empty data
    record empty_record = {0, "", 0};
    fseek(fp, offset, SEEK_SET);
    fwrite(&empty_record, sizeof(record), 1, fp);

    // Update the header of the database file
    int header[2];
    fseek(fp, 0, SEEK_SET);
    fread(header, sizeof(int), 2, fp);
    header[0]--;
    fseek(fp, 0, SEEK_SET);
    fwrite(header, sizeof(int), 2, fp);

    return 0;
}

// Print the database to the console
void print_database(FILE *fp) {
    // Read the header from the database file
    int header[2];
    fread(header, sizeof(int), 2, fp);

    // Print the records from the database file
    int i;
    for (i = 0; i < header[0]; i++) {
        record record;
        fseek(fp, header[1] + i * sizeof(record), SEEK_SET);
        fread(&record, sizeof(record), 1, fp);

        printf("Record %d: %d, %s, %d\n", i + 1, record.id, record.name, record.age);
    }
}

// Main function
int main() {
    // Create a new database
    if (create_database("database.dat") != 0) {
        printf("Error creating database\n");
        return 1;
    }

    // Open the database
    FILE *fp = open_database("database.dat");
    if (fp == NULL) {
        printf("Error opening database\n");
        return 1;
    }

    // Insert some records into the database
    record record1 = {1, "John Doe", 20};
    insert_record(fp, &record1);
    record record2 = {2, "Jane Doe", 25};
    insert_record(fp, &record2);
    record record3 = {3, "Jack Doe", 30};
    insert_record(fp, &record3);

    // Search for a record in the database using an index
    int id = 2;
    int offset = search_record_by_index(fp, id);
    if (offset == -1) {
        printf("Record not found\n");
    } else {
        printf("Record found at offset %d\n", offset);
    }

    // Search for a record in the database using a linear search
    id = 3;
    int index = search_record_by_linear_search(fp, id);
    if (index == -1) {
        printf("Record not found\n");
    } else {
        printf("Record found at index %d\n", index);
    }

    // Delete a record from the database
    id = 2;
    if (delete_record(fp, id) != 0) {
        printf("Error deleting record\n");
    }

    // Print the database to the console
    print_database(fp);

    // Close the database
    close_database(fp);

    return 0;
}