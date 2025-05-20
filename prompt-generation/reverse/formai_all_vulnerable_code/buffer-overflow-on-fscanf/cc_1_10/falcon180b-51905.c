//Falcon-180B DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} person_t;

void print_person(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int read_person(FILE *file, person_t *person) {
    char buffer[1024];
    int result = fscanf(file, "Name: %s\nAge: %d\n", person->name, &person->age);

    if (result!= 2) {
        printf("Error: Invalid person format\n");
        return 1;
    }

    return 0;
}

int write_person(FILE *file, person_t *person) {
    fprintf(file, "Name: %s\nAge: %d\n", person->name, person->age);
    return 0;
}

int main() {
    person_t person;
    FILE *file;

    file = fopen("person.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open person.txt for reading\n");
        return 1;
    }

    if (read_person(file, &person)) {
        fclose(file);
        return 1;
    }

    print_person(&person);

    fclose(file);

    file = fopen("person.txt", "w");

    if (file == NULL) {
        printf("Error: Could not open person.txt for writing\n");
        return 1;
    }

    if (write_person(file, &person)) {
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("Success\n");

    return 0;
}