//Falcon-180B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

Person *createPerson(char *name, int age) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    person->name = strdup(name);
    person->age = age;
    return person;
}

void deletePerson(Person *person) {
    free(person->name);
    free(person);
}

void printPerson(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *people[SIZE];
    int count = 0;

    while (count < SIZE) {
        char name[20];
        int age;
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        people[count] = createPerson(name, age);
        count++;
    }

    printf("List of people:\n");
    for (int i = 0; i < count; i++) {
        printPerson(people[i]);
    }

    for (int i = 0; i < count; i++) {
        deletePerson(people[i]);
    }

    return 0;
}