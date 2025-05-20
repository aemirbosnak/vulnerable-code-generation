//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

// Function to get user input
int get_name_and_age(char *name, int *age) {
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    printf("Enter your age: ");
    int age_input;
    scanf("%d", &age_input);

    *age = age_input;

    return 0; // Success
}

// Function to print a message based on the error
void print_error(int error_code) {
    switch (error_code) {
        case EINVAL:
            printf("Invalid input. Please try again.\n");
            break;
        case ENAMETOOLONG:
            printf("Name is too long. Please enter a shorter name.\n");
            break;
        case ENOENT:
            printf("No such file or directory. Please check the path.\n");
            break;
        default:
            printf("An unknown error occurred. Please try again.\n");
            break;
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    int age;

    // Try to get user input
    if (get_name_and_age(name, &age) == EINVAL) {
        print_error(errno);
        return 1; // Failure
    }

    // Do something with the input
    printf("Hello, %s! You are %d years old.\n", name, age);

    return 0; // Success
}