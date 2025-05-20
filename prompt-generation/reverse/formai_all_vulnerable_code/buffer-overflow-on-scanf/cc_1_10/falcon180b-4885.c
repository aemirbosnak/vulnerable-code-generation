//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Cryptic
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

int compare_name(const void *a, const void *b) {
    Person *person_a = *(Person **)a;
    Person *person_b = *(Person **)b;

    return strcmp(person_a->name, person_b->name);
}

int compare_age(const void *a, const void *b) {
    Person *person_a = *(Person **)a;
    Person *person_b = *(Person **)b;

    return person_a->age - person_b->age;
}

void print_person(Person *person) {
    printf("Name: %s, Age: %d\n", person->name, person->age);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (1) {
        printf("Enter name and age (or 'q' to quit): ");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        char *name = strtok(input, " ");
        int age = atoi(strtok(NULL, " "));

        create_person(&people[num_people], name, age);
        num_people++;
    }

    qsort(people, num_people, sizeof(Person *), compare_age);

    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(people[i]);
    }

    return 0;
}