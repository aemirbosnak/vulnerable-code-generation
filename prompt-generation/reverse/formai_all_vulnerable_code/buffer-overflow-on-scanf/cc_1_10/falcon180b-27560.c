//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age == personB->age) {
        return 0;
    } else {
        return 1;
    }
}

void search(Person *people, int numPeople, char *name) {
    qsort(people, numPeople, sizeof(Person), compare);

    int i;
    for (i = 0; i < numPeople; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found person: %s, age: %d\n", people[i].name, people[i].age);
            return;
        }
    }

    printf("Person not found.\n");
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    while (numPeople < MAX_SIZE && scanf("%s %d", people[numPeople].name, &people[numPeople].age) == 2) {
        numPeople++;
    }

    char nameToSearch[MAX_SIZE];
    printf("Enter name to search: ");
    scanf("%s", nameToSearch);

    search(people, numPeople, nameToSearch);

    return 0;
}