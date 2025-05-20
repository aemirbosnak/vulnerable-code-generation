//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 32
#define MAX_AGE 120
#define MAX_PHONE_NUMBER_LENGTH 16

struct Person {
    char name[MAX_NAME_LENGTH];
    int age;
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
};

struct Database {
    int size;
    struct Person *people;
};

struct Database *create_database(int size) {
    struct Database *db = malloc(sizeof(struct Database));
    db->size = size;
    db->people = malloc(size * sizeof(struct Person));
    return db;
}

void add_person(struct Database *db, struct Person person) {
    if (db->size == 0) {
        db->people = malloc(sizeof(struct Person));
        db->size++;
    } else {
        db->people = realloc(db->people, (db->size + 1) * sizeof(struct Person));
        db->size++;
    }
    db->people[db->size - 1] = person;
}

void remove_person(struct Database *db, int index) {
    if (index < 0 || index >= db->size) {
        return;
    }
    for (int i = index; i < db->size - 1; i++) {
        db->people[i] = db->people[i + 1];
    }
    db->size--;
}

void print_database(struct Database *db) {
    printf("Database: \n");
    for (int i = 0; i < db->size; i++) {
        printf("%d. %s, %d, %s\n", i + 1, db->people[i].name, db->people[i].age, db->people[i].phone_number);
    }
}

int main() {
    struct Database *db = create_database(10);

    struct Person person1 = {"John Doe", 32, "555-1234"};
    struct Person person2 = {"Jane Doe", 28, "555-5678"};
    struct Person person3 = {"Bob Smith", 45, "555-9012"};

    add_person(db, person1);
    add_person(db, person2);
    add_person(db, person3);

    remove_person(db, 1);

    print_database(db);

    free(db);

    return 0;
}