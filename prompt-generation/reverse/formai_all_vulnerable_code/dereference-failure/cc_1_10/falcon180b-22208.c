//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} Array;

void initArray(Array *array) {
    array->data = (Person *)malloc(MAX_SIZE * sizeof(Person));
    array->size = 0;
    array->capacity = MAX_SIZE;
}

void addPerson(Array *array, const char *name, int age) {
    if (array->size >= array->capacity) {
        printf("Array is full. Cannot add more elements.\n");
        return;
    }

    array->data[array->size].name = strdup(name);
    array->data[array->size].age = age;
    array->size++;
}

void searchPersonByName(Array *array, const char *name) {
    for (int i = 0; i < array->size; i++) {
        if (strcmp(array->data[i].name, name) == 0) {
            printf("Person found: %s, %d years old\n", array->data[i].name, array->data[i].age);
            return;
        }
    }

    printf("Person not found.\n");
}

void searchPersonByAge(Array *array, int age) {
    for (int i = 0; i < array->size; i++) {
        if (array->data[i].age == age) {
            printf("Person found: %s, %d years old\n", array->data[i].name, array->data[i].age);
            return;
        }
    }

    printf("Person not found.\n");
}

int main() {
    Array people;
    initArray(&people);

    addPerson(&people, "Alice", 25);
    addPerson(&people, "Bob", 30);
    addPerson(&people, "Charlie", 35);
    addPerson(&people, "David", 40);

    searchPersonByName(&people, "Bob");
    searchPersonByAge(&people, 30);

    return 0;
}