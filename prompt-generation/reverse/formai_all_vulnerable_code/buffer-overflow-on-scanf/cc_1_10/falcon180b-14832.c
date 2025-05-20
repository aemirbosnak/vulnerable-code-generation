//Falcon-180B DATASET v1.0 Category: Memory management ; Style: innovative
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

void destroy_person(Person *person) {
    free(person->name);
}

void print_person(Person *person) {
    printf("Name: %s\nAge: %d\nID: %d\n", person->name, person->age, person->id);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        char name[50];
        int age, id;

        printf("Enter person #%d's name:\n", i + 1);
        scanf("%s", name);

        printf("Enter person #%d's age:\n", i + 1);
        scanf("%d", &age);

        printf("Enter person #%d's ID:\n", i + 1);
        scanf("%d", &id);

        create_person(&people[num_people], name, age, id);
        num_people++;
    }

    printf("All people:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(&people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        destroy_person(&people[i]);
    }

    return 0;
}