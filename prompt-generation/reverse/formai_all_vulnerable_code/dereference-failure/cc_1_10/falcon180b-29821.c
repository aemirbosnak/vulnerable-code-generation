//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_RECORD_LEN 100

typedef struct {
    char name[MAX_RECORD_LEN];
    int age;
    char address[MAX_RECORD_LEN];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

Database* create_database() {
    Database* db = (Database*)malloc(sizeof(Database));
    db->num_records = 0;
    return db;
}

void add_record(Database* db, char* name, int age, char* address) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    strcpy(db->records[db->num_records].name, name);
    db->records[db->num_records].age = age;
    strcpy(db->records[db->num_records].address, address);
    db->num_records++;
}

void print_record(Record* record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Address: %s\n", record->address);
}

void print_database(Database* db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
    }
}

int main() {
    Database* db = create_database();
    add_record(db, "John Doe", 25, "123 Main St");
    add_record(db, "Jane Doe", 30, "456 Maple Ave");
    print_database(db);
    return 0;
}