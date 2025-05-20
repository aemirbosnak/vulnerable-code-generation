//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

Person *createPerson(char *name, int age) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = (char *)malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    return person;
}

void printPerson(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    Person *people[MAX_SIZE];
    int numPeople = 0;

    while (numPeople < MAX_SIZE) {
        char name[100];
        printf("Enter name: ");
        scanf("%s", name);

        int age;
        printf("Enter age: ");
        scanf("%d", &age);

        Person *person = createPerson(name, age);
        people[numPeople] = person;
        numPeople++;
    }

    int choice;
    while (true) {
        printf("\n1. Print all people\n2. Print people with age > 30\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < numPeople; i++) {
                printPerson(people[i]);
            }
            break;

        case 2:
            for (int i = 0; i < numPeople; i++) {
                Person *person = people[i];
                if (person->age > 30) {
                    printPerson(person);
                }
            }
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}