//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

typedef struct {
    char name[20];
    int age;
    float height;
} Person;

void addPerson(Person *people, int *size) {
    printf("Enter name: ");
    scanf("%s", &people[*size].name);
    printf("Enter age: ");
    scanf("%d", &people[*size].age);
    printf("Enter height: ");
    scanf("%f", &people[*size].height);
    (*size)++;
}

void printPeople(Person *people, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", people[i].name);
        printf("Age: %d\n", people[i].age);
        printf("Height: %.2f\n\n", people[i].height);
    }
}

void sortByAge(Person *people, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

void sortByHeight(Person *people, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (people[i].height > people[j].height) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }
}

int main() {
    Person people[MAX];
    int size = 0;

    addPerson(people, &size);
    addPerson(people, &size);
    addPerson(people, &size);

    printf("Unsorted:\n");
    printPeople(people, size);

    sortByAge(people, size);
    printf("\nSorted by age:\n");
    printPeople(people, size);

    sortByHeight(people, size);
    printf("\nSorted by height:\n");
    printPeople(people, size);

    return 0;
}