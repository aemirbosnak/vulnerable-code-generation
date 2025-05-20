//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *createPerson(char *name, int age) {
    Person *person = (Person*)malloc(sizeof(Person));
    person->name = strdup(name);
    person->age = age;
    return person;
}

void deletePerson(Person *person) {
    free(person->name);
    free(person);
}

int compare(const void *a, const void *b) {
    Person *personA = *(Person**)a;
    Person *personB = *(Person**)b;

    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return strcmp(personA->name, personB->name);
    }
}

int main() {
    Person *people[MAX_SIZE];
    int count = 0;

    printf("Enter names and ages of people (enter 'done' when finished):\n");

    while (count < MAX_SIZE) {
        char name[100];
        int age;

        scanf("%s %d", name, &age);

        if (strcmp(name, "done") == 0) {
            break;
        }

        Person *person = createPerson(name, age);
        people[count++] = person;
    }

    qsort(people, count, sizeof(Person*), compare);

    printf("Sorted by age:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", people[i]->name, people[i]->age);
        deletePerson(people[i]);
    }

    return 0;
}