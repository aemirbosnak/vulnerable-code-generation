//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: multivariable
/*
 * C Database Simulation Example Program
 *
 * This program simulates a database that stores information about customers.
 * It allows the user to add, delete, and update customer records.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a customer record
struct customer {
    int id;
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
};

// Define the structure for the database
struct database {
    struct customer *records;
    int num_records;
};

// Function to add a customer record to the database
void add_record(struct database *db, struct customer record) {
    // Check if the database is full
    if (db->num_records == 100) {
        printf("Database is full, unable to add record.\n");
        return;
    }

    // Add the record to the database
    db->records[db->num_records] = record;
    db->num_records++;
}

// Function to delete a customer record from the database
void delete_record(struct database *db, int id) {
    // Check if the record exists
    int index = find_record(db, id);
    if (index == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }

    // Remove the record from the database
    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->num_records--;
}

// Function to update a customer record in the database
void update_record(struct database *db, int id, struct customer record) {
    // Check if the record exists
    int index = find_record(db, id);
    if (index == -1) {
        printf("Record with ID %d not found.\n", id);
        return;
    }

    // Update the record in the database
    db->records[index] = record;
}

// Function to find a customer record in the database
int find_record(struct database *db, int id) {
    // Check if the record exists
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Initialize the database
    struct database db;
    db.records = (struct customer*) malloc(100 * sizeof(struct customer));
    db.num_records = 0;

    // Add some records to the database
    struct customer record1 = {1, "John Doe", "123 Main St", "555-1234", "johndoe@example.com"};
    add_record(&db, record1);

    struct customer record2 = {2, "Jane Doe", "456 Elm St", "555-5678", "janedoe@example.com"};
    add_record(&db, record2);

    // Delete a record from the database
    delete_record(&db, 2);

    // Update a record in the database
    struct customer record3 = {3, "Bob Smith", "789 Oak St", "555-9012", "bobsmith@example.com"};
    update_record(&db, 1, record3);

    // Print the records in the database
    for (int i = 0; i < db.num_records; i++) {
        printf("%d: %s, %s, %s, %s\n", db.records[i].id, db.records[i].name, db.records[i].address, db.records[i].phone, db.records[i].email);
    }

    // Free the memory allocated for the database
    free(db.records);

    return 0;
}