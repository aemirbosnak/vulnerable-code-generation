//Falcon-180B DATASET v1.0 Category: Memory management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
    char *address;
} Person;

Person *create_person(char *name, int age, char *address) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = (char *)malloc(sizeof(char) * strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->address = (char *)malloc(sizeof(char) * strlen(address) + 1);
    strcpy(person->address, address);
    return person;
}

void delete_person(Person *person) {
    free(person->name);
    free(person->address);
    free(person);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[50];
        int age;
        char address[200];

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter address: ");
        scanf("%s", address);

        people[num_people] = create_person(name, age, address);
        num_people++;
    }

    for (int i = 0; i < num_people; i++) {
        printf("Name: %s\n", people[i]->name);
        printf("Age: %d\n", people[i]->age);
        printf("Address: %s\n\n", people[i]->address);

        delete_person(people[i]);
    }

    return 0;
}