//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

void print_person(Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("ID: %d\n", person.id);
}

bool compare_name(Person person, char *name) {
    return strcmp(person.name, name) == 0;
}

bool compare_age(Person person, int age) {
    return person.age == age;
}

bool compare_id(Person person, int id) {
    return person.id == id;
}

void search_person(Person *persons, int size, char *search_name, int search_age, int search_id) {
    int i;
    Person result = {NULL, 0, 0};

    for (i = 0; i < size; i++) {
        if (strcmp(persons[i].name, search_name) == 0) {
            result = persons[i];
            break;
        }
    }

    if (result.name == NULL) {
        printf("No person found with name '%s'\n", search_name);
    } else {
        print_person(result);
    }
}

int main() {
    Person persons[MAX_SIZE];
    int size = 0;

    create_person(&persons[size], "John", 25, 1);
    size++;
    create_person(&persons[size], "Jane", 30, 2);
    size++;
    create_person(&persons[size], "Doe", 35, 3);
    size++;

    char search_name[20];
    int search_age, search_id;

    printf("Enter name to search: ");
    scanf("%s", search_name);

    printf("Enter age to search: ");
    scanf("%d", &search_age);

    printf("Enter ID to search: ");
    scanf("%d", &search_id);

    search_person(persons, size, search_name, search_age, search_id);

    return 0;
}