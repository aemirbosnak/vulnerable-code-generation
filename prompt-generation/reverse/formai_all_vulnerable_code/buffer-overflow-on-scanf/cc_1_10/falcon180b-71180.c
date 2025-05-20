//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int compare(const void *a, const void *b) {
    Person *personA = (Person *) a;
    Person *personB = (Person *) b;

    if (personA->age < personB->age) {
        return -1;
    } else if (personA->age > personB->age) {
        return 1;
    } else {
        return 0;
    }
}

void search(Person *people, int numPeople) {
    char searchName[MAX_SIZE];
    printf("Enter the name to search for: ");
    scanf("%s", searchName);

    qsort(people, numPeople, sizeof(Person), compare);

    int found = 0;
    for (int i = 0; i < numPeople; i++) {
        if (strcmp(people[i].name, searchName) == 0) {
            printf("Found: %s, Age: %d\n", people[i].name, people[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("Name not found.\n");
    }
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    while (numPeople < MAX_SIZE) {
        printf("Enter a name and age (or 0 to quit): ");
        scanf("%s %d", people[numPeople].name, &people[numPeople].age);
        if (people[numPeople].age == 0) {
            break;
        }
        numPeople++;
    }

    printf("Enter the number of people to search for: ");
    int searchNum;
    scanf("%d", &searchNum);

    if (searchNum > numPeople) {
        printf("Invalid number of people to search for.\n");
        return 1;
    }

    search(people, searchNum);

    return 0;
}