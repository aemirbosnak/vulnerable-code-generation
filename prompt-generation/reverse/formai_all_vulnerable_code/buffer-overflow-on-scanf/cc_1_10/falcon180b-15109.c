//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: introspective
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

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    Person *people = NULL;
    int numPeople = 0;
    char input[MAX_SIZE];

    printf("Enter the number of people: ");
    scanf("%d", &numPeople);

    if (numPeople <= 0 || numPeople > MAX_SIZE) {
        printf("Invalid number of people.\n");
        return 1;
    }

    people = (Person *)malloc(numPeople * sizeof(Person));

    printf("Enter the name and age of each person:\n");
    for (int i = 0; i < numPeople; i++) {
        scanf("%s %d", people[i].name, &people[i].age);
    }

    qsort(people, numPeople, sizeof(Person), compare);

    printf("Sorted by age:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s %d\n", people[i].name, people[i].age);
    }

    free(people);

    return 0;
}