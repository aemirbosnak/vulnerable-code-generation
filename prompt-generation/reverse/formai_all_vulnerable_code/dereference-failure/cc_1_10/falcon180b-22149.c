//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

int compare_names(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    return strcmp(person_a->name, person_b->name);
}

int compare_ages(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    if (person_a->age < person_b->age)
        return -1;
    else if (person_a->age == person_b->age)
        return 0;
    else
        return 1;
}

int main() {
    int num_people = 10;
    Person *people = (Person *)malloc(num_people * sizeof(Person));

    for (int i = 0; i < num_people; i++) {
        char name[20];
        sprintf(name, "Person %d", i + 1);
        people[i].name = strdup(name);
        people[i].age = i + 1;
    }

    qsort(people, num_people, sizeof(Person), compare_names);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    qsort(people, num_people, sizeof(Person), compare_ages);

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    free(people);

    return 0;
}