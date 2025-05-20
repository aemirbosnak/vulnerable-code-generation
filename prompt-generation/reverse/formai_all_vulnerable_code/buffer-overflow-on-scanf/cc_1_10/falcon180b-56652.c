//Falcon-180B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct {
    char *name;
    int age;
    int id;
} Person;

Person *create_person(char *name, int age, int id) {
    Person *person = (Person *) malloc(sizeof(Person));
    person->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
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
    printf("ID: %d\n\n", person->id);
}

int main() {
    Person *people[SIZE];
    int count = 0;

    while (count < SIZE) {
        char name[20];
        int age, id;

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter age: ");
        scanf("%d", &age);

        printf("Enter ID: ");
        scanf("%d", &id);

        people[count] = create_person(name, age, id);
        print_person(people[count]);
        count++;
    }

    for (int i = 0; i < count; i++) {
        delete_person(people[i]);
    }

    return 0;
}