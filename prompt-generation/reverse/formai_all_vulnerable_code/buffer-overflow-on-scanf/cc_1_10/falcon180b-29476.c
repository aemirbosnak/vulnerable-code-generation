//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

void create_persons(Person *persons, int num_persons) {
    for (int i = 0; i < num_persons; i++) {
        sprintf(persons[i].name, "Person %d", i + 1);
        persons[i].age = i + 1;
    }
}

int compare_persons(const void *a, const void *b) {
    Person *person_a = (Person *) a;
    Person *person_b = (Person *) b;

    if (strcmp(person_a->name, person_b->name) == 0) {
        return 0;
    } else if (strcmp(person_a->name, person_b->name) > 0) {
        return 1;
    } else {
        return -1;
    }
}

void search_person(Person *persons, int num_persons, char *name_to_search) {
    qsort(persons, num_persons, sizeof(Person), compare_persons);

    Person *person_found = NULL;
    for (int i = 0; i < num_persons; i++) {
        if (strcmp(persons[i].name, name_to_search) == 0) {
            person_found = &persons[i];
            break;
        }
    }

    if (person_found!= NULL) {
        printf("Found person with name %s and age %d\n", person_found->name, person_found->age);
    } else {
        printf("Person not found\n");
    }
}

int main() {
    Person persons[MAX_SIZE];
    int num_persons = 10;

    create_persons(persons, num_persons);

    char name_to_search[MAX_SIZE];
    printf("Enter name to search: ");
    scanf("%s", name_to_search);

    search_person(persons, num_persons, name_to_search);

    return 0;
}