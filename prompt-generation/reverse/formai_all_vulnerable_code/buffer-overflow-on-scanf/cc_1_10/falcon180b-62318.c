//Falcon-180B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
    char gender;
} Person;

void swap(Person* a, Person* b) {
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b) {
    const Person* personA = (const Person*)a;
    const Person* personB = (const Person*)b;

    if (personA->age > personB->age) {
        return 1;
    } else if (personA->age < personB->age) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    Person people[MAX_SIZE];
    int numPeople = 0;

    printf("Enter the number of people: ");
    scanf("%d", &numPeople);

    for (int i = 0; i < numPeople; i++) {
        printf("Enter the name of person %d: ", i+1);
        scanf("%s", people[i].name);
        printf("Enter the age of person %d: ", i+1);
        scanf("%d", &people[i].age);
        printf("Enter the gender of person %d (M/F): ", i+1);
        scanf(" %c", &people[i].gender);
    }

    qsort(people, numPeople, sizeof(Person), compare);

    printf("\nSorted by age:\n");
    for (int i = 0; i < numPeople; i++) {
        printf("%s is %d years old.\n", people[i].name, people[i].age);
    }

    return 0;
}