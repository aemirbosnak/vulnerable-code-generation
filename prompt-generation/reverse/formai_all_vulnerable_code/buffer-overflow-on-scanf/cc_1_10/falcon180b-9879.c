//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

void create_person(Person *person, char *name, int age) {
    person->name = strdup(name);
    person->age = age;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

void print_person(Person *person) {
    printf("Name: %s\nAge: %d\n", person->name, person->age);
}

int compare_names(const void *a, const void *b) {
    Person *person_a = (Person *)a;
    Person *person_b = (Person *)b;

    return strcmp(person_a->name, person_b->name);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    char name[100];
    int age;

    while (1) {
        printf("Enter a name (or type 'exit' to quit): ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter an age: ");
        scanf("%d", &age);

        create_person(&people[num_people], name, age);
        num_people++;
    }

    qsort(people, num_people, sizeof(Person), compare_names);

    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(people[i]);
    }

    return 0;
}