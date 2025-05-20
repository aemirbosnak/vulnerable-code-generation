//Falcon-180B DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char* name;
    int age;
    char* email;
} Person;

Person* read_person_from_file(FILE* file) {
    Person* person = malloc(sizeof(Person));
    char line[MAX_LINE_LENGTH];
    int i = 0;
    char* token;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, ",");
        if (i == 0) {
            person->name = strdup(token);
        } else if (i == 1) {
            person->age = atoi(token);
        } else if (i == 2) {
            person->email = strdup(token);
        }
        i++;
    }

    return person;
}

void write_person_to_file(FILE* file, Person* person) {
    fprintf(file, "%s,%d,%s\n", person->name, person->age, person->email);
}

void print_person(Person* person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Email: %s\n", person->email);
}

int main() {
    FILE* file = fopen("people.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    Person* person = read_person_from_file(file);
    print_person(person);

    fclose(file);

    file = fopen("people.csv", "a");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    person->age++;
    write_person_to_file(file, person);

    fclose(file);

    free(person->name);
    free(person->email);
    free(person);

    return 0;
}