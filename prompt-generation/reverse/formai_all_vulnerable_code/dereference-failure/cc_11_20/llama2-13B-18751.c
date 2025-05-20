//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

struct person {
    char name[MAX_NAME_LENGTH];
    int age;
};

int main() {
    struct person person = {0};

    // Example 1: Missing Argument
    if (sizeof(person.name) == 0) {
        printf("Error: Missing name argument\n");
        return 1;
    }

    // Example 2: Invalid Name Length
    if (strlen(person.name) > MAX_NAME_LENGTH) {
        printf("Error: Name length exceeds maximum (%d)\n", MAX_NAME_LENGTH);
        return 1;
    }

    // Example 3: Negative Age
    if (person.age < 0) {
        printf("Error: Age must be positive (%d)\n", person.age);
        return 1;
    }

    // Example 4: Age Out of Range
    if (person.age > MAX_AGE) {
        printf("Error: Age exceeds maximum (%d)\n", MAX_AGE);
        return 1;
    }

    // Example 5: Memory Allocation Failure
    if (malloc(sizeof(person)) == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    // Example 6: null pointer dereference
    if (person.name == NULL) {
        printf("Error: null pointer dereference\n");
        return 1;
    }

    // Example 7: division by zero
    if (person.age == 0) {
        printf("Error: division by zero\n");
        return 1;
    }

    // Example 8: overflow
    if (person.age > 100) {
        printf("Error: overflow\n");
        return 1;
    }

    // Example 9: underflow
    if (person.age < 0) {
        printf("Error: underflow\n");
        return 1;
    }

    // Example 10: invalid memory access
    if (person.name[10] != '\0') {
        printf("Error: invalid memory access\n");
        return 1;
    }

    printf("Success: All examples passed\n");
    return 0;
}