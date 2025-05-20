//Falcon-180B DATASET v1.0 Category: Memory management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *p) {
    p->name = NULL;
    p->age = 0;
}

void destroy_person(Person *p) {
    if (p->name!= NULL) {
        free(p->name);
        p->name = NULL;
    }
}

Person *create_person(char *name, int age) {
    Person *p = malloc(sizeof(Person));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    init_person(p);

    p->name = malloc(strlen(name) + 1);
    if (p->name == NULL) {
        printf("Memory allocation failed!\n");
        destroy_person(p);
        exit(1);
    }

    strcpy(p->name, name);
    p->age = age;

    return p;
}

void print_person(Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
}

int main() {
    Person *p1 = create_person("John", 30);
    Person *p2 = create_person("Jane", 25);

    print_person(p1);
    print_person(p2);

    destroy_person(p1);
    destroy_person(p2);

    free(p1);
    free(p2);

    return 0;
}