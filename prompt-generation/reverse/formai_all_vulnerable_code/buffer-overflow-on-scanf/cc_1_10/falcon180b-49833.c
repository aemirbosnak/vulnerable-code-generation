//Falcon-180B DATASET v1.0 Category: Memory management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void initialize(Person *person) {
    person->name = NULL;
    person->age = 0;
}

void set_name(Person *person, char *name) {
    if (person->name!= NULL) {
        free(person->name);
    }
    person->name = strdup(name);
}

void set_age(Person *person, int age) {
    person->age = age;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));
    int num_people = 0;

    initialize(people);

    while (num_people < MAX_SIZE) {
        char name[50];
        int age;

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        set_name(&people[num_people], name);
        set_age(&people[num_people++], age);
    }

    printf("List of people:\n");

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    free(people);

    return 0;
}