//Falcon-180B DATASET v1.0 Category: Database querying ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records in the database
#define MAX_RECORDS 100

// Define the maximum length of a field in the database
#define MAX_FIELD_LENGTH 50

// Define the structure of a record in the database
typedef struct {
    char *id;
    char *name;
    int age;
} Record;

// Define the structure of the database
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

// Function to initialize the database
void init_database(Database *db) {
    db->num_records = 0;
}

// Function to add a record to the database
void add_record(Database *db, char *id, char *name, int age) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: Database is full\n");
        return;
    }
    Record record;
    record.id = strdup(id);
    record.name = strdup(name);
    record.age = age;
    db->records[db->num_records++] = record;
}

// Function to query the database
void query_database(Database *db, char *query) {
    char *tokens[MAX_FIELD_LENGTH];
    int num_tokens = 0;
    char *delimiters = " ";
    char *token = strtok(query, delimiters);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, delimiters);
    }
    switch (num_tokens) {
        case 1:
            printf("All records:\n");
            for (int i = 0; i < db->num_records; i++) {
                printf("%s\n", db->records[i].id);
            }
            break;
        case 2:
            printf("Record with ID %s:\n", tokens[1]);
            for (int i = 0; i < db->num_records; i++) {
                if (strcmp(db->records[i].id, tokens[1]) == 0) {
                    printf("ID: %s\n", db->records[i].id);
                    printf("Name: %s\n", db->records[i].name);
                    printf("Age: %d\n", db->records[i].age);
                }
            }
            break;
        default:
            printf("Invalid query\n");
            break;
    }
}

// Main function
int main() {
    Database db;
    init_database(&db);
    add_record(&db, "1", "John", 30);
    add_record(&db, "2", "Jane", 25);
    add_record(&db, "3", "Bob", 40);
    query_database(&db, "1");
    query_database(&db, "2 Jane");
    query_database(&db, "3 Bob 40");
    return 0;
}