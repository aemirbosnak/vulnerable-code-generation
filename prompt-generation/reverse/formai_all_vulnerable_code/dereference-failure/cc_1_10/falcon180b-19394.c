//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int age;
} Person;

int main(int argc, char* argv[]) {
    Person* people = (Person*) malloc(sizeof(Person) * 5);

    // Initialize the people array
    strcpy(people[0].name, "John");
    people[0].age = 25;

    strcpy(people[1].name, "Jane");
    people[1].age = 30;

    strcpy(people[2].name, "Bob");
    people[2].age = 20;

    strcpy(people[3].name, "Alice");
    people[3].age = 28;

    strcpy(people[4].name, "Charlie");
    people[4].age = 35;

    // Print the people array
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    // Sort the people array by age
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (people[i].age > people[j].age) {
                Person temp = people[i];
                people[i] = people[j];
                people[j] = temp;
            }
        }
    }

    // Print the sorted people array
    printf("\nSorted by age:\n");
    for (int i = 0; i < 5; i++) {
        printf("Name: %s, Age: %d\n", people[i].name, people[i].age);
    }

    free(people);

    return 0;
}