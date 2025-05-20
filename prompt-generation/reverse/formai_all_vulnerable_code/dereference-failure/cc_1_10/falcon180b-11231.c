//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void destroy_person(Person *person) {
    free(person->name);
    free(person);
}

int compare_persons(Person *p1, Person *p2) {
    return strcmp(p1->name, p2->name);
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    create_person(people[num_people++], "Alice", 25);
    create_person(people[num_people++], "Bob", 30);
    create_person(people[num_people++], "Charlie", 20);
    create_person(people[num_people++], "David", 35);

    qsort(people, num_people, sizeof(Person *), compare_persons);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    destroy_person(people[0]);
    destroy_person(people[1]);
    destroy_person(people[2]);
    destroy_person(people[3]);

    return 0;
}