//Code Llama-13B DATASET v1.0 Category: User Input Sanitizer ; Style: complex
/*
 *  User Input Sanitizer
 *  A complex example program to demonstrate the use of C functions
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store the user input
struct user_input {
    char name[20];
    int age;
    char email[50];
};

// Define a function to sanitize the user input
void sanitize_input(struct user_input *input) {
    // Trim leading and trailing whitespace from the name
    char *name = input->name;
    name[strcspn(name, " \t\n\r")] = 0;

    // Check if the name is empty or not
    if (name[0] == 0) {
        printf("Error: Name cannot be empty\n");
        exit(1);
    }

    // Check if the name is too long
    if (strlen(name) > 20) {
        printf("Error: Name is too long\n");
        exit(1);
    }

    // Check if the age is valid
    if (input->age < 0 || input->age > 120) {
        printf("Error: Invalid age\n");
        exit(1);
    }

    // Check if the email is valid
    char *email = input->email;
    if (email[0] == 0) {
        printf("Error: Email cannot be empty\n");
        exit(1);
    }

    // Check if the email is too long
    if (strlen(email) > 50) {
        printf("Error: Email is too long\n");
        exit(1);
    }

    // Check if the email contains invalid characters
    if (strpbrk(email, " ,;<>\"'\\") != NULL) {
        printf("Error: Email contains invalid characters\n");
        exit(1);
    }
}

int main() {
    // Create a structure to store the user input
    struct user_input input;

    // Get the user input
    printf("Enter your name: ");
    scanf("%19s", input.name);
    printf("Enter your age: ");
    scanf("%d", &input.age);
    printf("Enter your email: ");
    scanf("%49s", input.email);

    // Sanitize the user input
    sanitize_input(&input);

    // Print the sanitized input
    printf("Name: %s\n", input.name);
    printf("Age: %d\n", input.age);
    printf("Email: %s\n", input.email);

    return 0;
}