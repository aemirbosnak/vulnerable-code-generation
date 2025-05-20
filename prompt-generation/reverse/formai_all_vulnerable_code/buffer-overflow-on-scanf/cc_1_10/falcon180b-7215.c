//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
}

void delete_person(Person *person) {
    free(person->name);
}

int compare_persons(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    int result = strcmp(person_a->name, person_b->name);
    if (result == 0) {
        result = person_a->age - person_b->age;
    }

    return result;
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (num_people < MAX_SIZE && scanf("%s %d", people[num_people].name, &people[num_people].age)!= EOF) {
        num_people++;
    }

    qsort(people, num_people, sizeof(Person), compare_persons);

    printf("Sorted by name:\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    printf("\nSorted by age:\n");
    qsort(people, num_people, sizeof(Person), (int (*)(const void *, const void *))compare_persons);
    for (int i = 0; i < num_people; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    free(people);
    return 0;
}