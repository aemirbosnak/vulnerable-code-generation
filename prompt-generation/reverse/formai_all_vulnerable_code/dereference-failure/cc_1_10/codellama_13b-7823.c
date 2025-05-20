//Code Llama-13B DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a person
typedef struct {
    char name[50];
    char address[100];
    char phone[20];
} Person;

// Structure to represent a database
typedef struct {
    Person *people;
    int size;
    int capacity;
} Database;

// Function to create a new database
Database *create_database() {
    Database *db = malloc(sizeof(Database));
    db->people = malloc(sizeof(Person) * 10);
    db->size = 0;
    db->capacity = 10;
    return db;
}

// Function to add a person to the database
void add_person(Database *db, char *name, char *address, char *phone) {
    if (db->size == db->capacity) {
        db->capacity *= 2;
        db->people = realloc(db->people, sizeof(Person) * db->capacity);
    }
    Person *p = &db->people[db->size++];
    strcpy(p->name, name);
    strcpy(p->address, address);
    strcpy(p->phone, phone);
}

// Function to search for a person by name
Person *find_person(Database *db, char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->people[i].name, name) == 0) {
            return &db->people[i];
        }
    }
    return NULL;
}

// Function to remove a person from the database
void remove_person(Database *db, char *name) {
    int index = -1;
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->people[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;
    }
    for (int i = index; i < db->size - 1; i++) {
        db->people[i] = db->people[i + 1];
    }
    db->size--;
}

// Function to print all the people in the database
void print_database(Database *db) {
    for (int i = 0; i < db->size; i++) {
        Person *p = &db->people[i];
        printf("%s %s %s\n", p->name, p->address, p->phone);
    }
}

// Driver code
int main() {
    Database *db = create_database();
    add_person(db, "John Doe", "123 Main St", "555-1234");
    add_person(db, "Jane Doe", "456 Elm St", "555-5678");
    add_person(db, "Bob Smith", "789 Oak St", "555-9012");
    print_database(db);
    Person *p = find_person(db, "John Doe");
    if (p != NULL) {
        printf("Found %s\n", p->name);
    } else {
        printf("Person not found\n");
    }
    remove_person(db, "Jane Doe");
    print_database(db);
    return 0;
}