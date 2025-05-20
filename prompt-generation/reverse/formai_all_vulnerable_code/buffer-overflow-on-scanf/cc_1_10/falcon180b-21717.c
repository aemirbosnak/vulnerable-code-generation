//Falcon-180B DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

void free_person(Person *person) {
    free(person->name);
    free(person);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[32];
        int age;

        printf("Enter name (or type 'quit' to exit): ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter age: ");
        scanf("%d", &age);

        Person *person = malloc(sizeof(Person));
        init_person(person, name, age);
        people[num_people++] = person;
    }

    printf("List of people:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        free_person(people[i]);
    }

    return 0;
}