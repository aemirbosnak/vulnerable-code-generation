//Falcon-180B DATASET v1.0 Category: Educational ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void print_person(Person person) {
    printf("Name: %s\nAge: %d\n", person.name, person.age);
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[50];
        int age;

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        create_person(&people[num_people], name, age);
        num_people++;
    }

    printf("People:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(&people[i]);
    }

    free(people);

    return 0;
}