//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray(int capacity) {
    DynamicArray *array = (DynamicArray *)malloc(sizeof(DynamicArray));
    array->data = (Person *)malloc(capacity * sizeof(Person));
    array->size = 0;
    array->capacity = capacity;
    return array;
}

void destroyDynamicArray(DynamicArray *array) {
    free(array->data);
    free(array);
}

void addToDynamicArray(DynamicArray *array, Person person) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        array->data = (Person *)realloc(array->data, array->capacity * sizeof(Person));
    }
    array->data[array->size++] = person;
}

void printDynamicArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("Name: %s, Age: %d\n", array->data[i].name, array->data[i].age);
    }
}

int main() {
    DynamicArray *array = createDynamicArray(MAX_SIZE);

    Person person1 = {"Alice", 25};
    Person person2 = {"Bob", 30};
    Person person3 = {"Charlie", 35};

    addToDynamicArray(array, person1);
    addToDynamicArray(array, person2);
    addToDynamicArray(array, person3);

    printDynamicArray(array);

    destroyDynamicArray(array);

    return 0;
}