//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *address;
} Record;

typedef struct {
    Record *records;
    int size;
    int capacity;
} Database;

void init_database(Database *db) {
    db->records = (Record *)malloc(MAX_SIZE * sizeof(Record));
    db->size = 0;
    db->capacity = MAX_SIZE;
}

void destroy_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        free(db->records[i].name);
        free(db->records[i].address);
    }
    free(db->records);
}

void add_record(Database *db, char *name, int age, char *address) {
    if (db->size >= db->capacity) {
        printf("Error: Database is full.\n");
        return;
    }

    db->records[db->size].name = strdup(name);
    db->records[db->size].age = age;
    db->records[db->size].address = strdup(address);

    db->size++;
}

void search_record(Database *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            printf("Name: %s\n", db->records[i].name);
            printf("Age: %d\n", db->records[i].age);
            printf("Address: %s\n", db->records[i].address);
        }
    }
}

int main() {
    Database db;
    init_database(&db);

    add_record(&db, "John", 25, "123 Main St.");
    add_record(&db, "Jane", 30, "456 Maple Ave.");

    search_record(&db, "John");
    search_record(&db, "Jane");

    destroy_database(&db);

    return 0;
}