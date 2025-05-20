//Falcon-180B DATASET v1.0 Category: Memory management ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void init_person(Person *person) {
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

void delete_person(Person *person) {
    if (person->name!= NULL) {
        free(person->name);
    }
    memset(person, 0, sizeof(Person));
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));

    int num_people = 0;
    while (num_people < MAX_SIZE) {
        char name[MAX_SIZE];
        printf("Enter name (leave blank to stop): ");
        scanf("%s", name);
        if (name[0] == '\0') {
            break;
        }

        Person person;
        init_person(&person);
        set_name(&person, name);
        set_age(&person, rand() % 100);
        people[num_people] = person;
        num_people++;
    }

    printf("Number of people: %d\n", num_people);

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(&people[i]);
    }

    free(people);

    return 0;
}