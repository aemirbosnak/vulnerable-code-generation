//Falcon-180B DATASET v1.0 Category: Memory management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    int id;
} Person;

Person *create_person(char *name, int age, int id) {
    Person *person = (Person *)malloc(sizeof(Person));
    person->name = (char *)malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
    person->id = id;
    return person;
}

void delete_person(Person *person) {
    free(person->name);
    free(person);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("ID: %d\n", person->id);
}

int main() {
    Person *people[MAX_SIZE];
    int num_people = 0;

    while (num_people < MAX_SIZE) {
        char name[50];
        int age, id;

        printf("Enter name, age, and ID for person #%d:\n", num_people + 1);
        scanf("%s %d %d", name, &age, &id);

        people[num_people] = create_person(name, age, id);
        num_people++;
    }

    printf("List of people:\n");
    for (int i = 0; i < num_people; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < num_people; i++) {
        delete_person(people[i]);
    }

    return 0;
}