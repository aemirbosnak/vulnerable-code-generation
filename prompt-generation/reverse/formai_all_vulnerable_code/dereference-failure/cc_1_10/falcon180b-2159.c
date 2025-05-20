//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Database;

void initDatabase(Database *db, int capacity) {
    db->data = (Person *)malloc(capacity * sizeof(Person));
    db->size = 0;
    db->capacity = capacity;
}

void destroyDatabase(Database *db) {
    free(db->data);
}

void addPerson(Database *db, const char *name, int age, char gender) {
    if (db->size >= db->capacity) {
        printf("Error: Database is full.\n");
        return;
    }

    strcpy(db->data[db->size].name, name);
    db->data[db->size].age = age;
    db->data[db->size].gender = gender;

    db->size++;
}

void removePerson(Database *db, const char *name) {
    int i;

    for (i = 0; i < db->size; i++) {
        if (strcmp(db->data[i].name, name) == 0) {
            db->size--;

            for (int j = i; j < db->size; j++) {
                db->data[j] = db->data[j + 1];
            }

            break;
        }
    }
}

void printDatabase(const Database *db) {
    printf("Name\tAge\tGender\n");

    for (int i = 0; i < db->size; i++) {
        printf("%s\t%d\t%c\n", db->data[i].name, db->data[i].age, db->data[i].gender);
    }
}

int main() {
    Database db;
    initDatabase(&db, 100);

    addPerson(&db, "Romeo", 25, 'M');
    addPerson(&db, "Juliet", 23, 'F');
    addPerson(&db, "Tybalt", 30, 'M');
    addPerson(&db, "Mercutio", 27, 'M');

    printDatabase(&db);

    removePerson(&db, "Tybalt");

    printDatabase(&db);

    destroyDatabase(&db);

    return 0;
}