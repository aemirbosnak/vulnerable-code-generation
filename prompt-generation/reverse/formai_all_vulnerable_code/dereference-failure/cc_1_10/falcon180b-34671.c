//Falcon-180B DATASET v1.0 Category: Error handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} People;

void init_people(People *people) {
    people->data = NULL;
    people->size = 0;
    people->capacity = 0;
}

void add_person(People *people, char *name, int age) {
    if (people->size >= people->capacity) {
        people->capacity += 10;
        people->data = realloc(people->data, people->capacity * sizeof(Person));
    }

    people->data[people->size] = (Person) {
       .name = strdup(name),
       .age = age
    };

    people->size++;
}

void print_people(People *people) {
    for (int i = 0; i < people->size; i++) {
        printf("Name: %s, Age: %d\n", people->data[i].name, people->data[i].age);
    }
}

void free_people(People *people) {
    for (int i = 0; i < people->size; i++) {
        free(people->data[i].name);
    }

    free(people->data);
}

int main() {
    People people;
    init_people(&people);

    add_person(&people, "Alice", 25);
    add_person(&people, "Bob", 30);
    add_person(&people, "Charlie", 20);

    print_people(&people);

    free_people(&people);

    return 0;
}