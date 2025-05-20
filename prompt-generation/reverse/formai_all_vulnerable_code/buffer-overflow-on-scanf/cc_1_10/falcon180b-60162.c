//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
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

int main() {
    int n, i;
    Person *people = NULL;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    people = (Person *)malloc(n * sizeof(Person));

    for (i = 0; i < n; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", people[i].name);
        printf("Enter age for person %s: ", people[i].name);
        scanf("%d", &people[i].age);
    }

    qsort(people, n, sizeof(Person), compare);

    printf("Sorted by age:\n");
    for (i = 0; i < n; i++) {
        printf("%s (%d)\n", people[i].name, people[i].age);
    }

    free(people);

    return 0;
}