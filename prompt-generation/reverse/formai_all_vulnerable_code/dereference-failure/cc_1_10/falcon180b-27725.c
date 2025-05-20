//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} PersonArray;

void initPersonArray(PersonArray *array) {
    array->data = malloc(10 * sizeof(Person));
    array->size = 0;
    array->capacity = 10;
}

void addPerson(PersonArray *array, char *name, int age, char *email) {
    if (array->size >= array->capacity) {
        array->capacity *= 2;
        array->data = realloc(array->data, array->capacity * sizeof(Person));
    }

    Person *person = &array->data[array->size];
    person->name = strdup(name);
    person->age = age;
    person->email = strdup(email);

    array->size++;
}

void freePersonArray(PersonArray *array) {
    for (int i = 0; i < array->size; i++) {
        free(array->data[i].name);
        free(array->data[i].email);
    }

    free(array->data);
}

void printPersonArray(PersonArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%s (%d) - %s\n", array->data[i].name, array->data[i].age, array->data[i].email);
    }
}

int main() {
    PersonArray people;
    initPersonArray(&people);

    addPerson(&people, "Alice", 25, "alice@example.com");
    addPerson(&people, "Bob", 30, "bob@example.com");
    addPerson(&people, "Charlie", 20, "charlie@example.com");
    addPerson(&people, "David", 40, "david@example.com");

    printf("People:\n");
    printPersonArray(&people);

    freePersonArray(&people);

    return 0;
}