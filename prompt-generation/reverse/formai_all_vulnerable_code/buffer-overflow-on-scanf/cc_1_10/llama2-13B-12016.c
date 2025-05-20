//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

int main() {
    // Declare variables
    char name[MAX_NAME_LEN];
    int age;
    int num_errors = 0;

    // Get name and age from user
    printf("Please enter your name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    printf("Please enter your age: ");
    scanf("%d", &age);

    // Check for invalid input
    if (name[0] == '\n' || age < 0 || age > MAX_AGE) {
        num_errors++;
        printf("Invalid input. Please try again.\n");
    }

    // Check for name length exceeding maximum
    if (strlen(name) > MAX_NAME_LEN) {
        num_errors++;
        printf("Name too long. Please try again.\n");
    }

    // Check for age exceeding maximum
    if (age > MAX_AGE) {
        num_errors++;
        printf("Age too high. Please try again.\n");
    }

    // Print success message if no errors
    if (num_errors == 0) {
        printf("Success! Your name is %s and your age is %d.\n", name, age);
    }

    // Print error messages if errors exist
    else {
        printf("Error(s) found:\n");
        if (num_errors == 1) {
            printf("* Invalid input. Please try again.\n");
        }
        if (num_errors == 2) {
            printf("* Name too long. Please try again.\n");
            printf("* Age too high. Please try again.\n");
        }
    }

    // Add some randomness to the program
    srand(time(NULL));
    if (rand() % 2 == 0) {
        num_errors++;
        printf("Additional error found. Please try again.\n");
    }

    return num_errors;
}