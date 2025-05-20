//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person*)a;
    Person *personB = (Person*)b;

    int result = strcmp(personA->name, personB->name);
    if (result == 0) {
        result = personA->age - personB->age;
    }

    return result;
}

void search(Person *people, int numPeople, char *name) {
    qsort(people, numPeople, sizeof(Person), compare);

    for (int i = 0; i < numPeople; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found person: %s, age: %d\n", people[i].name, people[i].age);
        }
    }
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    while (numPeople < MAX_SIZE) {
        printf("Enter a name and age (or enter 'done' to finish):\n");
        char name[MAX_SIZE];
        scanf("%s", name);

        if (strcmp(name, "done") == 0) {
            break;
        }

        printf("Enter age:\n");
        scanf("%d", &people[numPeople].age);
        strcpy(people[numPeople].name, name);
        numPeople++;
    }

    char searchName[MAX_SIZE];
    printf("Enter a name to search for:\n");
    scanf("%s", searchName);

    search(people, numPeople, searchName);

    return 0;
}