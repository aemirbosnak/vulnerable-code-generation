//Falcon-180B DATASET v1.0 Category: Educational ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int id;
} Person;

void create_person(Person *person, char *name, int age, int id) {
    person->name = malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->id = id;
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("ID: %d\n", person->id);
}

void destroy_person(Person *person) {
    free(person->name);
}

int main() {
    Person *people = malloc(MAX_SIZE * sizeof(Person));

    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[20];
        int age, id;

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter ID: ");
        scanf("%d", &id);

        create_person(&people[num_people], name, age, id);
        num_people++;
    }

    printf("\nList of people:\n");

    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        destroy_person(&people[i]);
    }

    free(people);

    return 0;
}