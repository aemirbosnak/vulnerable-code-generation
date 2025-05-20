//Falcon-180B DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    char *name;
    int age;
} Person;

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

Person *read_person(FILE *file) {
    char line[MAX_LINE_LENGTH];
    Person *person = NULL;

    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        print_error("Failed to read line from file");
    }

    person = malloc(sizeof(Person));
    if (person == NULL) {
        print_error("Failed to allocate memory for person");
    }

    person->name = strdup(line);
    if (person->name == NULL) {
        print_error("Failed to duplicate name");
    }

    if (sscanf(line, "%s %d", person->name, &person->age)!= 2) {
        print_error("Invalid format for person data");
    }

    return person;
}

void write_person(const Person *person, FILE *file) {
    fprintf(file, "%s %d\n", person->name, person->age);
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");

    if (input_file == NULL) {
        print_error("Failed to open input file");
    }

    if (output_file == NULL) {
        print_error("Failed to open output file");
    }

    Person *person = read_person(input_file);
    if (person == NULL) {
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    write_person(person, output_file);

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}