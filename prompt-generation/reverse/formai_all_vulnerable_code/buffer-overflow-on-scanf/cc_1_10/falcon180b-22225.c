//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *)a;
    Person *personB = (Person *)b;

    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *people[MAX_SIZE];
    int numPeople = 0;

    while (numPeople < MAX_SIZE) {
        printf("Enter a name and age (or type 'done' to finish):\n");
        char name[100];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        int age;
        scanf("%d", &age);

        if (numPeople >= MAX_SIZE) {
            printf("Error: too many people!\n");
            exit(1);
        }

        people[numPeople] = malloc(sizeof(Person));
        people[numPeople]->name = strdup(name);
        people[numPeople]->age = age;
        numPeople++;
    }

    qsort(people, numPeople, sizeof(Person), compare);

    printf("Sorted by age:\n");
    for (int i = 0; i < numPeople; i++) {
        printPerson(people[i]);
    }

    return 0;
}