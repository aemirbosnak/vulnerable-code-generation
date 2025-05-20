//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_BUFFER_SIZE 1024

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
    int age;
} user_t;

// Function to get user information
void get_user_info(user_t *user) {
    printf("Enter your name: ");
    fgets(user->name, MAX_NAME_LEN, stdin);
    printf("Enter your email: ");
    fgets(user->email, MAX_NAME_LEN, stdin);
    printf("Enter your age: ");
    scanf("%d", &user->age);
}

// Function to print user information
void print_user_info(user_t *user) {
    printf("Hello, %s!\n", user->name);
    printf("Your email is: %s\n", user->email);
    printf("You are %d years old.\n", user->age);
}

// Main function
int main() {
    user_t user;

    // Get user information
    get_user_info(&user);

    // Print user information
    print_user_info(&user);

    // Get user input again
    printf("Would you like to enter more information? (y/n): ");
    char input;
    scanf(" %c", &input);

    // If user inputs "y", continue to get more information
    if (input == 'y') {
        get_user_info(&user);
        print_user_info(&user);
    }

    // If user inputs "n", end the program
    else if (input == 'n') {
        printf("Goodbye!\n");
        return 0;
    }

    // If user inputs anything else, print an error message
    else {
        printf("Invalid input. Please enter 'y' or 'n'.\n");
    }

    return 0;
}