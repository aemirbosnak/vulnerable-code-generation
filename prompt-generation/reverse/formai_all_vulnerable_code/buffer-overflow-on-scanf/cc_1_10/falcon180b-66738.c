//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
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

void readData(Person *people, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", people[i].name);

        printf("Enter age for person %s: ", people[i].name);
        scanf("%d", &people[i].age);
    }
}

void printData(Person *people, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }
}

int main() {
    int n;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    Person *people = (Person *)malloc(n * sizeof(Person));

    readData(people, n);

    qsort(people, n, sizeof(Person), compare);

    printf("Sorted by age:\n");
    printData(people, n);

    free(people);

    return 0;
}