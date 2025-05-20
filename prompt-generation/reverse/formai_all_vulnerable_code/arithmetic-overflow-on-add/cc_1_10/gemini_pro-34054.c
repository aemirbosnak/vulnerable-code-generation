//GEMINI-pro DATASET v1.0 Category: Database simulation ; Style: protected
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[31];
    int age;
    char gender;
    char address[101];
    char city[31];
    char state[3];
    char zip[6];
    char phone[11];
    char email[51];
} person_t;

typedef struct {
    person_t *people;
    int count;
    int capacity;
} database_t;

database_t *create_database(int initial_capacity) {
    database_t *db = malloc(sizeof(database_t));
    if (db == NULL) {
        return NULL;
    }

    db->people = malloc(initial_capacity * sizeof(person_t));
    if (db->people == NULL) {
        free(db);
        return NULL;
    }

    db->count = 0;
    db->capacity = initial_capacity;

    return db;
}

void destroy_database(database_t *db) {
    free(db->people);
    free(db);
}

int add_person(database_t *db, person_t *person) {
    if (db->count >= db->capacity) {
        db->people = realloc(db->people, db->capacity * 2 * sizeof(person_t));
        if (db->people == NULL) {
            return -1;
        }

        db->capacity *= 2;
    }

    db->people[db->count] = *person;
    db->count++;

    return 0;
}

int remove_person(database_t *db, char *name) {
    int i;

    for (i = 0; i < db->count; i++) {
        if (strcmp(db->people[i].name, name) == 0) {
            break;
        }
    }

    if (i == db->count) {
        return -1;
    }

    db->count--;
    db->people[i] = db->people[db->count];

    return 0;
}

person_t *find_person(database_t *db, char *name) {
    int i;

    for (i = 0; i < db->count; i++) {
        if (strcmp(db->people[i].name, name) == 0) {
            return &db->people[i];
        }
    }

    return NULL;
}

void print_database(database_t *db) {
    int i;

    for (i = 0; i < db->count; i++) {
        printf("%s, %d, %c, %s, %s, %s, %s, %s, %s\n",
            db->people[i].name,
            db->people[i].age,
            db->people[i].gender,
            db->people[i].address,
            db->people[i].city,
            db->people[i].state,
            db->people[i].zip,
            db->people[i].phone,
            db->people[i].email);
    }
}

int main() {
    database_t *db = create_database(10);

    person_t person1 = {
        "John Smith",
        30,
        'M',
        "123 Main Street",
        "Anytown",
        "CA",
        "12345",
        "555-1212",
        "john.smith@example.com"
    };

    person_t person2 = {
        "Jane Doe",
        25,
        'F',
        "456 Elm Street",
        "Anytown",
        "CA",
        "67890",
        "555-1213",
        "jane.doe@example.com"
    };

    person_t person3 = {
        "Bill Jones",
        40,
        'M',
        "789 Oak Street",
        "Anytown",
        "CA",
        "01234",
        "555-1214",
        "bill.jones@example.com"
    };

    add_person(db, &person1);
    add_person(db, &person2);
    add_person(db, &person3);

    print_database(db);

    remove_person(db, "Jane Doe");

    print_database(db);

    destroy_database(db);

    return 0;
}