//Code Llama-13B DATASET v1.0 Category: Database querying ; Style: ephemeral
// A unique C Database querying example program in an ephemeral style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a single record
struct Record {
    int id;
    char name[50];
    char email[50];
    char phone[15];
};

// Struct for a database
struct Database {
    struct Record *records;
    int num_records;
};

// Function to add a new record to the database
void addRecord(struct Database *db, struct Record new_record) {
    db->records = realloc(db->records, (db->num_records + 1) * sizeof(struct Record));
    db->records[db->num_records] = new_record;
    db->num_records++;
}

// Function to find a record in the database
struct Record *findRecord(struct Database *db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Function to update a record in the database
void updateRecord(struct Database *db, int id, struct Record new_record) {
    struct Record *record = findRecord(db, id);
    if (record) {
        *record = new_record;
    }
}

// Function to delete a record from the database
void deleteRecord(struct Database *db, int id) {
    struct Record *record = findRecord(db, id);
    if (record) {
        for (int i = 0; i < db->num_records; i++) {
            if (db->records[i].id == id) {
                memcpy(&db->records[i], &db->records[i + 1], (db->num_records - i - 1) * sizeof(struct Record));
                db->num_records--;
                break;
            }
        }
    }
}

// Function to print all records in the database
void printRecords(struct Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("%d: %s %s %s\n", db->records[i].id, db->records[i].name, db->records[i].email, db->records[i].phone);
    }
}

int main() {
    struct Database db;
    db.records = NULL;
    db.num_records = 0;

    // Add some records to the database
    addRecord(&db, (struct Record){1, "John", "john@example.com", "123-456-7890"});
    addRecord(&db, (struct Record){2, "Jane", "jane@example.com", "234-567-8901"});
    addRecord(&db, (struct Record){3, "Bob", "bob@example.com", "345-678-9012"});

    // Find a record by ID
    struct Record *record = findRecord(&db, 2);
    if (record) {
        printf("Found record: %d %s %s %s\n", record->id, record->name, record->email, record->phone);
    }

    // Update a record
    updateRecord(&db, 2, (struct Record){2, "Jane Doe", "jane.doe@example.com", "234-567-8901"});

    // Delete a record
    deleteRecord(&db, 3);

    // Print all records in the database
    printRecords(&db);

    return 0;
}