//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

void validate_person(Person* person, const char* function_name) {
    if (strlen(person->name) > MAX_NAME_LENGTH) {
        fprintf(stderr, "[%s] Error: Name is too long.\n", function_name);
        exit(EXIT_FAILURE);
    }
    if (person->age < 0 || person->age > MAX_AGE) {
        fprintf(stderr, "[%s] Error: Age is invalid.\n", function_name);
        exit(EXIT_FAILURE);
    }
}

void create_person(Person* person, const char* name, int age) {
    strcpy(person->name, name);
    person->age = age;
    validate_person(person, "create_person");
}

void print_person(const Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main(void) {
    Person suspect;

    printf("Enter suspect's name: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    printf("Enter suspect's age: ");
    int age;
    scanf("%d", &age);

    create_person(&suspect, name, age);
    print_person(&suspect);

    return EXIT_SUCCESS;
}