//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void createPerson(Person *person) {
    printf("Enter name: ");
    scanf("%s", person->name);
    printf("Enter age: ");
    scanf("%d", &person->age);
}

void displayPerson(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
}

int compare(const void *a, const void *b) {
    Person p1 = *(Person *)a;
    Person p2 = *(Person *)b;

    if (p1.age < p2.age) {
        return -1;
    } else if (p1.age > p2.age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int count = 0;

    while (count < MAX_SIZE) {
        printf("Enter person details (name age): ");
        scanf("%s %d", people[count].name, &people[count].age);
        createPerson(&people[count]);
        count++;
    }

    qsort(people, count, sizeof(Person), compare);

    printf("Sorted by age:\n");
    for (int i = 0; i < count; i++) {
        displayPerson(people[i]);
    }

    free(people);
    return 0;
}