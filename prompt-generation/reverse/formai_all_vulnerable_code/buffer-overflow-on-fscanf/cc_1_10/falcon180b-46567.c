//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: grateful
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
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Person *people[MAX_SIZE];
    int numPeople = 0;

    FILE *file = fopen("people.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fscanf(file, "%s %d\n", people[numPeople]->name, &people[numPeople]->age)!= EOF) {
        numPeople++;
    }

    fclose(file);

    qsort(people, numPeople, sizeof(Person), compare);

    printf("Sorted by age:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s %d\n", people[i]->name, people[i]->age);
    }

    return 0;
}