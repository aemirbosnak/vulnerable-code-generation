//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: happy
// A unique C Database Indexing System example program in a happy style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure for a record in the database
struct Record {
    char name[20];
    int age;
    float height;
};

// Declare the structure for the database
struct Database {
    struct Record *records;
    int num_records;
};

// Declare the function to create a new database
void create_database(struct Database *db, int num_records) {
    db->records = (struct Record *)malloc(num_records * sizeof(struct Record));
    db->num_records = num_records;
}

// Declare the function to add a new record to the database
void add_record(struct Database *db, struct Record record) {
    db->records[db->num_records] = record;
    db->num_records++;
}

// Declare the function to search for a record in the database
struct Record *search_record(struct Database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];
        }
    }
    return NULL;
}

// Declare the function to print all records in the database
void print_all_records(struct Database *db) {
    for (int i = 0; i < db->num_records; i++) {
        printf("Name: %s, Age: %d, Height: %f\n", db->records[i].name, db->records[i].age, db->records[i].height);
    }
}

// Declare the function to delete a record from the database
void delete_record(struct Database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            for (int j = i; j < db->num_records - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->num_records--;
            return;
        }
    }
}

int main() {
    // Create a new database with 5 records
    struct Database db;
    create_database(&db, 5);

    // Add some records to the database
    struct Record record1 = {"John", 25, 1.75};
    struct Record record2 = {"Jane", 30, 1.65};
    struct Record record3 = {"Bob", 35, 1.85};
    struct Record record4 = {"Alice", 20, 1.55};
    struct Record record5 = {"Eve", 40, 1.70};
    add_record(&db, record1);
    add_record(&db, record2);
    add_record(&db, record3);
    add_record(&db, record4);
    add_record(&db, record5);

    // Search for a record in the database
    struct Record *record = search_record(&db, "Bob");
    if (record != NULL) {
        printf("Found record: %s, %d, %f\n", record->name, record->age, record->height);
    }

    // Print all records in the database
    print_all_records(&db);

    // Delete a record from the database
    delete_record(&db, "John");

    // Print all records in the database again
    print_all_records(&db);

    return 0;
}