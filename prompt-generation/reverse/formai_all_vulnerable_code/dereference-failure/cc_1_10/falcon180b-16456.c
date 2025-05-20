//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *email;
} Person;

typedef struct {
    Person *data;
    int size;
    int capacity;
} People;

void init(People *p) {
    p->data = (Person *)malloc(MAX_SIZE * sizeof(Person));
    p->size = 0;
    p->capacity = MAX_SIZE;
}

void destroy(People *p) {
    free(p->data);
}

int is_full(People *p) {
    return p->size == p->capacity;
}

void resize(People *p) {
    p->capacity *= 2;
    p->data = (Person *)realloc(p->data, p->capacity * sizeof(Person));
}

void add(People *p, const char *name, int age, const char *email) {
    if (is_full(p)) {
        resize(p);
    }

    p->data[p->size].name = strdup(name);
    p->data[p->size].age = age;
    p->data[p->size].email = strdup(email);

    p->size++;
}

void search(const People *p, const char *query) {
    int i;

    for (i = 0; i < p->size; i++) {
        if (strstr(p->data[i].name, query) || strstr(p->data[i].email, query)) {
            printf("%s\n", p->data[i].name);
        }
    }
}

int main() {
    People people;
    init(&people);

    add(&people, "John Doe", 25, "john@example.com");
    add(&people, "Jane Doe", 30, "jane@example.com");
    add(&people, "Bob Smith", 40, "bob@example.com");

    search(&people, "John");
    search(&people, "Doe");
    search(&people, "Jane");
    search(&people, "Smith");

    destroy(&people);

    return 0;
}