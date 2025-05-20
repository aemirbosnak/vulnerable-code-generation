//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

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

bool compare_persons(Person *person1, Person *person2) {
    return strcmp(person1->name, person2->name) == 0;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    Person *people[MAX_SIZE];
    int count = 0;

    create_person(people[count++], "King Arthur", 42);
    create_person(people[count++], "Sir Lancelot", 30);
    create_person(people[count++], "Merlin", 200);
    create_person(people[count++], "Guinevere", 25);
    create_person(people[count++], "Sir Galahad", 20);

    printf("The Knights of the Round Table:\n");
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
    }

    Person *sir_lancelot = people[1];
    Person *merlin = people[2];

    printf("\nSearching for Sir Lancelot and Merlin:\n");
    for (int i = 0; i < count; i++) {
        if (compare_persons(people[i], sir_lancelot)) {
            print_person(people[i]);
        }
        if (compare_persons(people[i], merlin)) {
            print_person(people[i]);
        }
    }

    destroy_person(sir_lancelot);
    destroy_person(merlin);

    return 0;
}