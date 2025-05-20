//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_NAME_LEN 256
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LEN];
    int age;
};

void print_error(const char* message) {
    printf("Error: %s\n", message);
}

void handle_error(const char* message, struct person* person) {
    if (strlen(message) > 0) {
        printf("Error: %s\n", message);
        person->age = -1; // set age to -1 to indicate an error
    }
}

int main() {
    struct person person = {0};

    // example 1: missing name
    if (scanf("%255s %d", person.name, &person.age) != 2) {
        handle_error("Missing name", &person);
    }

    // example 2: invalid age
    if (person.age < 0 || person.age > MAX_AGE) {
        handle_error("Invalid age", &person);
    }

    // example 3: too long name
    if (strlen(person.name) > MAX_NAME_LEN) {
        handle_error("Name too long", &person);
    }

    // example 4: divide by zero
    if (person.age == 0) {
        handle_error("Divide by zero", &person);
    }

    // example 5: NULL pointer
    if (person.name == NULL) {
        handle_error("NULL pointer", &person);
    }

    // example 6: invalid input
    if (scanf("%c", &person.age) != 1) {
        handle_error("Invalid input", &person);
    }

    return 0;
}