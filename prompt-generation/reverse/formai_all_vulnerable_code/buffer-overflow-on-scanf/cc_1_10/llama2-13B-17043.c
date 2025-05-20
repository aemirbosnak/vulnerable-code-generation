//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

// Structure to hold user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} user_info;

// Function to handle errors
void handle_error(const char* message) {
    printf("Error: %s\n", message);
    exit(EXIT_FAILURE);
}

// Function to get user information
user_info get_user_info(void) {
    // Prompt user for name and age
    printf("Enter your name: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    int age = get_age();

    // Check for invalid input
    if (name[0] == '\0' || age < 0 || age > MAX_AGE) {
        handle_error("Invalid input");
    }

    // Return user information
    user_info user = {name, age};
    return user;
}

// Function to get age
int get_age(void) {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

int main(void) {
    user_info user = get_user_info();
    printf("Hello, %s! You are %d years old.\n", user.name, user.age);
    return EXIT_SUCCESS;
}