//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int index;
} Person;

void swap(Person *a, Person *b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

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

void search(Person *people, int size, char *name) {
    int (*comparator)(const void *, const void *) = compare;
    qsort(people, size, sizeof(Person), comparator);

    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (strcmp(people[mid].name, name) == 0) {
            printf("Found person with name %s and age %d at index %d\n", people[mid].name, people[mid].age, mid);
            return;
        } else if (strcmp(people[mid].name, name) < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Person with name %s not found\n", name);
}

int main() {
    Person people[MAX_SIZE];
    int size = 0;

    while (size < MAX_SIZE) {
        printf("Enter name: ");
        scanf("%s", people[size].name);
        printf("Enter age: ");
        scanf("%d", &people[size].age);
        size++;
    }

    char nameToSearch[MAX_SIZE];
    printf("Enter name to search: ");
    scanf("%s", nameToSearch);

    search(people, size, nameToSearch);

    return 0;
}