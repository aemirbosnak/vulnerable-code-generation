//FormAI DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// constant declarations
#define MAX_RECORDS 100

// structure for a single record in the database
typedef struct {
    int id;
    char name[20];
    int age;
} Record;

// structure for the index table
typedef struct {
    int key;
    int pos;
} IndexTableEntry;

// global variables
Record database[MAX_RECORDS]; // array of all records in the database
int num_records = 0; // total number of records in the database
IndexTableEntry index_table[MAX_RECORDS]; // array of index table entries
int num_index_entries = 0; // total number of index table entries

// function declarations
void add_record(int id, char *name, int age);
void print_database();
void create_index_table();
int binary_search(int key);
void search_database();

// function to add a record to the database
void add_record(int id, char *name, int age) {
    Record new_record;
    new_record.id = id;
    strcpy(new_record.name, name);
    new_record.age = age;
    database[num_records] = new_record;
    num_records++;
}

// function to print all records in the database
void print_database() {
    printf("%-10s %-20s %-10s\n", "ID", "Name", "Age");
    printf("------------------------------\n");
    for (int i = 0; i < num_records; i++) {
        printf("%-10d %-20s %-10d\n", database[i].id, database[i].name, database[i].age);
    }
    printf("------------------------------\n");
}

// function to create the index table
void create_index_table() {
    for (int i = 0; i < num_records; i++) {
        IndexTableEntry entry;
        entry.key = database[i].id;
        entry.pos = i;
        index_table[num_index_entries] = entry;
        num_index_entries++;
    }
}

// function to perform binary search on the index table
int binary_search(int key) {
    int lo = 0;
    int hi = num_index_entries - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (index_table[mid].key == key) {
            return index_table[mid].pos;
        } else if (index_table[mid].key < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -1;
}

// function to search the database using the index table
void search_database() {
    int id;
    printf("Enter the ID to search for: ");
    scanf("%d", &id);
    int pos = binary_search(id);
    if (pos == -1) {
        printf("Record not found.\n");
    } else {
        Record r = database[pos];
        printf("Record found:\n");
        printf("ID: %d\nName: %s\nAge: %d\n", r.id, r.name, r.age);
    }
}

// main function
int main() {
    // add some sample records to the database
    add_record(1001, "John Doe", 25);
    add_record(1002, "Jane Smith", 30);
    add_record(1003, "Bob Johnson", 40);
    add_record(1004, "Alice Kim", 35);

    // create the index table
    create_index_table();

    // search the database using the index table
    search_database();

    // print all records in the database
    print_database();

    return 0;
}