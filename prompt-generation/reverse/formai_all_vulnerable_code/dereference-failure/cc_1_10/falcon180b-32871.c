//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char name[MAX];
    int age;
    char gender[10];
} person;

typedef struct {
    person *data;
    int size;
    int capacity;
} array;

void init(array *arr) {
    arr->data = (person *)malloc(MAX * sizeof(person));
    arr->size = 0;
    arr->capacity = MAX;
}

void destroy(array *arr) {
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i].name);
        free(arr->data[i].gender);
    }
    free(arr->data);
}

void resize(array *arr) {
    arr->capacity *= 2;
    person *new_data = (person *)malloc(arr->capacity * sizeof(person));
    for (int i = 0; i < arr->size; i++) {
        strcpy(new_data[i].name, arr->data[i].name);
        strcpy(new_data[i].gender, arr->data[i].gender);
    }
    free(arr->data);
    arr->data = new_data;
}

void add(array *arr, char *name, int age, char *gender) {
    if (arr->size == arr->capacity) {
        resize(arr);
    }
    strcpy(arr->data[arr->size].name, name);
    arr->data[arr->size].age = age;
    strcpy(arr->data[arr->size].gender, gender);
    arr->size++;
}

void print_array(array arr) {
    for (int i = 0; i < arr.size; i++) {
        printf("%s %d %s\n", arr.data[i].name, arr.data[i].age, arr.data[i].gender);
    }
}

int main() {
    array people;
    init(&people);
    add(&people, "John", 25, "male");
    add(&people, "Jane", 30, "female");
    add(&people, "Bob", 20, "male");
    print_array(people);
    destroy(&people);
    return 0;
}