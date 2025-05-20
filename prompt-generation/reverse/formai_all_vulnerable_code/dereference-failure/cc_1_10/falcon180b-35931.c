//Falcon-180B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int age;
    char *occupation;
} Person;

void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed! ");
        exit(1);
    }
    return ptr;
}

void my_free(void *ptr) {
    free(ptr);
}

void init_person(Person *person) {
    person->name = NULL;
    person->age = 0;
    person->occupation = NULL;
}

void set_person_name(Person *person, char *name) {
    person->name = my_malloc(strlen(name) + 1);
    strcpy(person->name, name);
}

void set_person_age(Person *person, int age) {
    person->age = age;
}

void set_person_occupation(Person *person, char *occupation) {
    person->occupation = my_malloc(strlen(occupation) + 1);
    strcpy(person->occupation, occupation);
}

void print_person(Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Occupation: %s\n", person->occupation);
}

int main() {
    Person person1, person2;
    init_person(&person1);
    init_person(&person2);

    set_person_name(&person1, "John");
    set_person_age(&person1, 25);
    set_person_occupation(&person1, "Software Engineer");

    set_person_name(&person2, "Jane");
    set_person_age(&person2, 30);
    set_person_occupation(&person2, "Data Scientist");

    printf("Person 1:\n");
    print_person(&person1);

    printf("\nPerson 2:\n");
    print_person(&person2);

    my_free(person1.name);
    my_free(person1.occupation);
    my_free(person2.name);
    my_free(person2.occupation);

    return 0;
}