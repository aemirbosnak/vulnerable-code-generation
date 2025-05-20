//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
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

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

void search(Person *people, int numPeople, int age) {
    qsort(people, numPeople, sizeof(Person), compare);

    printf("People with age %d:\n", age);
    for (int i = 0; i < numPeople; i++) {
        if (people[i].age == age) {
            printf("%s\n", people[i].name);
        }
    }
}

int main() {
    Person people[MAX_SIZE];
    int numPeople = 0;

    while (numPeople < MAX_SIZE) {
        printf("Enter a name (or leave blank to stop): ");
        fgets(people[numPeople].name, MAX_SIZE, stdin);

        if (people[numPeople].name[0] == '\0') {
            break;
        }

        printf("Enter an age: ");
        scanf("%d", &people[numPeople].age);

        numPeople++;
    }

    int ageToSearch;
    printf("Enter an age to search for: ");
    scanf("%d", &ageToSearch);

    search(people, numPeople, ageToSearch);

    return 0;
}