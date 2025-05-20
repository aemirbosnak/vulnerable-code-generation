//Falcon-180B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

void init_person(Person *person) {
    person->name = NULL;
    person->age = 0;
    person->address = NULL;
}

void set_name(Person *person, char *name) {
    free(person->name);
    person->name = strdup(name);
}

void set_age(Person *person, int age) {
    person->age = age;
}

void set_address(Person *person, char *address) {
    free(person->address);
    person->address = strdup(address);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Address: %s\n", person->address);
}

int main() {
    Person person1;
    init_person(&person1);

    set_name(&person1, "John Doe");
    set_age(&person1, 30);
    set_address(&person1, "123 Main St");

    print_person(&person1);

    return 0;
}