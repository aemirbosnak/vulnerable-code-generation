//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STRING_LENGTH 1024
#define MAX_INTEGER_VALUE 10000

int main() {
    int age;
    char name[MAX_STRING_LENGTH];
    int result;

    // Example 1: Valid input
    printf("Enter your name: ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    if (sscanf(name, "%d", &age) == 1) {
        result = age;
    } else {
        result = -1;
    }
    printf("Your age is: %d\n", result);

    // Example 2: Invalid input (negative number)
    printf("Enter your name: ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    if (sscanf(name, "%d", &age) == 1) {
        result = age;
    } else {
        result = -2;
    }
    printf("Your age is: %d\n", result);

    // Example 3: Input exceeds maximum length
    printf("Enter your name: ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    if (sscanf(name, "%d", &age) == 1) {
        result = age;
    } else {
        result = -3;
    }
    printf("Your age is: %d\n", result);

    // Example 4: Invalid input (empty string)
    printf("Enter your name: ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    if (sscanf(name, "%d", &age) == 1) {
        result = age;
    } else {
        result = -4;
    }
    printf("Your age is: %d\n", result);

    // Example 5: Input is not a number
    printf("Enter your name: ");
    fgets(name, MAX_STRING_LENGTH, stdin);
    if (sscanf(name, "%d", &age) == 1) {
        result = age;
    } else {
        result = -5;
    }
    printf("Your age is: %d\n", result);

    return 0;
}