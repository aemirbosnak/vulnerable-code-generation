//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Dennis Ritchie
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

Array *create_array() {
    Array *array = (Array *)malloc(sizeof(Array));
    array->data = (Person *)malloc(MAX_SIZE * sizeof(Person));
    array->size = 0;
    array->capacity = MAX_SIZE;
    return array;
}

void destroy_array(Array *array) {
    free(array->data);
    free(array);
}

void add_person(Array *array, char *name, int age) {
    if (array->size >= array->capacity) {
        printf("Array is full.\n");
        return;
    }
    array->data[array->size++] = (Person){.name = strdup(name),.age = age};
}

void print_array(Array *array) {
    printf("Array:\n");
    for (int i = 0; i < array->size; i++) {
        printf("%d. %s (%d years old)\n", i + 1, array->data[i].name, array->data[i].age);
    }
}

int main() {
    Array *array = create_array();
    add_person(array, "Alice", 25);
    add_person(array, "Bob", 30);
    add_person(array, "Charlie", 35);
    print_array(array);
    destroy_array(array);
    return 0;
}