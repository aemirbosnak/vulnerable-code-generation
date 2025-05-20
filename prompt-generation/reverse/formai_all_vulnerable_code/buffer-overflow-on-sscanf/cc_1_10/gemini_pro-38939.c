//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 1024

int main() {
    // Declare variables
    char input[MAX_INPUT_LEN];
    int age;
    float height;
    char name[MAX_INPUT_LEN];

    // Get user input
    printf("Enter your age: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // Sanitize age input
    while (sscanf(input, "%d", &age) != 1) {
        printf("Invalid age input. Please enter a valid integer: ");
        fgets(input, MAX_INPUT_LEN, stdin);
    }

    // Get user input
    printf("Enter your height: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // Sanitize height input
    while (sscanf(input, "%f", &height) != 1) {
        printf("Invalid height input. Please enter a valid floating-point number: ");
        fgets(input, MAX_INPUT_LEN, stdin);
    }

    // Get user input
    printf("Enter your name: ");
    fgets(input, MAX_INPUT_LEN, stdin);

    // Sanitize name input
    while (strlen(input) == 0 || strlen(input) > MAX_INPUT_LEN) {
        printf("Invalid name input. Please enter a valid name: ");
        fgets(input, MAX_INPUT_LEN, stdin);
    }

    // Print the sanitized user input
    printf("Your age: %d\n", age);
    printf("Your height: %.2f\n", height);
    printf("Your name: %s\n", name);

    return 0;
}