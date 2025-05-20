//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define ELEMENT_SIZE 50

typedef struct {
    char *name;
    int age;
} Person;

Person *newPerson(char *name, int age) {
    Person *person = malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

int compare(const void *a, const void *b) {
    Person *personA = *(Person **)a;
    Person *personB = *(Person **)b;
    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return strcmp(personA->name, personB->name);
    }
}

void printPerson(Person *person) {
    printf("%s (%d)\n", person->name, person->age);
}

int main() {
    Person **people = malloc(MAX_ELEMENTS * sizeof(Person *));
    int numPeople = 0;

    printf("Enter people (name age):\n");
    char input[ELEMENT_SIZE];
    while (fgets(input, ELEMENT_SIZE, stdin)) {
        char *name = strtok(input, " ");
        int age = atoi(strtok(NULL, " "));
        people[numPeople] = newPerson(name, age);
        numPeople++;
    }

    qsort(people, numPeople, sizeof(Person *), compare);

    printf("Sorted by age:\n");
    for (int i = 0; i < numPeople; i++) {
        printPerson(people[i]);
    }

    free(people);
    return 0;
}