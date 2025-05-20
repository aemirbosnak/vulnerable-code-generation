//Falcon-180B DATASET v1.0 Category: Memory management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int age;
} Person;

Person *create_person(char *name, int age) {
    Person *person = malloc(sizeof(Person));
    if (person == NULL) {
        printf("Error: could not allocate memory for person.\n");
        return NULL;
    }
    person->name = strdup(name);
    person->age = age;
    return person;
}

void delete_person(Person *person) {
    if (person == NULL) {
        return;
    }
    free(person->name);
    free(person);
}

void print_person(Person *person) {
    if (person == NULL) {
        printf("Error: person is NULL.\n");
        return;
    }
    printf("Name: %s\nAge: %d\n", person->name, person->age);
}

int main() {
    Person *people[MAX_SIZE];
    int count = 0;

    while (count < MAX_SIZE) {
        char name[20];
        int age;
        printf("Enter name (max 20 characters): ");
        scanf("%s", name);
        printf("Enter age: ");
        scanf("%d", &age);
        people[count] = create_person(name, age);
        count++;
    }

    printf("List of people:\n");
    for (int i = 0; i < count; i++) {
        print_person(people[i]);
    }

    for (int i = 0; i < count; i++) {
        delete_person(people[i]);
    }

    return 0;
}