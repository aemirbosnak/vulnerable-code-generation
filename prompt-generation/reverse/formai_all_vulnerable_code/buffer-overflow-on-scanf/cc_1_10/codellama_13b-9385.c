//Code Llama-13B DATASET v1.0 Category: User Input Sanitizer ; Style: ultraprecise
// Example: C User Input Sanitizer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants
#define MAX_LEN 100
#define MAX_CHARS 255

// Define data types
typedef struct {
    char name[MAX_LEN];
    int age;
} person_t;

// Define functions
void sanitize_input(char *input) {
    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Replace spaces with underscores
    char *p = input;
    while (*p != '\0') {
        if (*p == ' ') {
            *p = '_';
        }
        p++;
    }
}

void print_person(person_t person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
}

int main(void) {
    // Initialize variables
    char name[MAX_LEN];
    int age;

    // Get user input
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);

    // Sanitize input
    sanitize_input(name);

    // Create person object
    person_t person = {name, age};

    // Print person information
    print_person(person);

    return 0;
}