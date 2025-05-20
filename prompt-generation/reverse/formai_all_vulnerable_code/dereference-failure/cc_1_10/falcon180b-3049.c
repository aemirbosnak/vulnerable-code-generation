//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char *name;
    int age;
    float height;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} ArrayList;

void initArrayList(ArrayList *list) {
    list->data = (Person *)malloc(10 * sizeof(Person));
    list->size = 0;
    list->capacity = 10;
}

void addPerson(ArrayList *list, char *name, int age, float height) {
    if (list->size == list->capacity) {
        list->capacity += 10;
        list->data = (Person *)realloc(list->data, list->capacity * sizeof(Person));
    }
    list->data[list->size].name = strdup(name);
    list->data[list->size].age = age;
    list->data[list->size].height = height;
    list->size++;
}

void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Height: %.2f\n", person->height);
}

void printArrayList(ArrayList *list) {
    for (int i = 0; i < list->size; i++) {
        printPerson(&list->data[i]);
    }
}

void sortArrayList(ArrayList *list, int (*compare)(const void *, const void *)) {
    qsort(list->data, list->size, sizeof(Person), compare);
}

int compareAge(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;
    return personA->age - personB->age;
}

int main() {
    ArrayList people;
    initArrayList(&people);

    addPerson(&people, "Alice", 25, 165.5);
    addPerson(&people, "Bob", 30, 180.0);
    addPerson(&people, "Charlie", 20, 170.2);

    printArrayList(&people);

    sortArrayList(&people, compareAge);

    printArrayList(&people);

    return 0;
}