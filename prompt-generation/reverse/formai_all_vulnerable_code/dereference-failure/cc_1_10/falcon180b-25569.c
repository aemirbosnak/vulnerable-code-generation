//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} ArrayList;

void init_array_list(ArrayList *array_list) {
    array_list->data = NULL;
    array_list->size = 0;
    array_list->capacity = MAX_SIZE;
}

void resize_array_list(ArrayList *array_list) {
    array_list->capacity *= 2;
    Person *new_data = (Person *)malloc(array_list->capacity * sizeof(Person));
    if (array_list->data!= NULL) {
        memcpy(new_data, array_list->data, array_list->size * sizeof(Person));
        free(array_list->data);
    }
    array_list->data = new_data;
}

void add_person(ArrayList *array_list, char *name, int age) {
    if (array_list->size == array_list->capacity) {
        resize_array_list(array_list);
    }
    Person *person = &array_list->data[array_list->size];
    person->name = strdup(name);
    person->age = age;
    array_list->size++;
}

void print_array_list(ArrayList *array_list) {
    for (int i = 0; i < array_list->size; i++) {
        printf("Name: %s, Age: %d\n", array_list->data[i].name, array_list->data[i].age);
    }
}

int main() {
    ArrayList array_list;
    init_array_list(&array_list);

    add_person(&array_list, "Alan Turing", 41);
    add_person(&array_list, "Ada Lovelace", 36);
    add_person(&array_list, "Grace Hopper", 37);

    print_array_list(&array_list);

    return 0;
}