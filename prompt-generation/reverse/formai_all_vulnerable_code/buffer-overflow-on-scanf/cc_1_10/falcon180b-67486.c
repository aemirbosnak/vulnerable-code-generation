//Falcon-180B DATASET v1.0 Category: Educational ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int id;
} Person;

bool compare(const void *a, const void *b) {
    const Person *personA = (const Person *) a;
    const Person *personB = (const Person *) b;

    if (personA->age > personB->age) {
        return true;
    } else if (personA->age < personB->age) {
        return false;
    } else {
        return strcmp(personA->name, personB->name) > 0;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Person *people = malloc(n * sizeof(Person));

    for (int i = 0; i < n; i++) {
        people[i].name = malloc(MAX_SIZE * sizeof(char));
        scanf("%s", people[i].name);
        people[i].age = scanf("%d", &people[i].age);
        people[i].id = i;
    }

    qsort(people, n, sizeof(Person), compare);

    for (int i = 0; i < n; i++) {
        printf("%d. %s (%d years old)\n", i + 1, people[i].name, people[i].age);
    }

    for (int i = 0; i < n; i++) {
        free(people[i].name);
    }
    free(people);

    return 0;
}