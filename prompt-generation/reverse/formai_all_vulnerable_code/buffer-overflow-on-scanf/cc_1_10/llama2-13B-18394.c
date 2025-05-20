//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: optimized
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
} user_info_t;

// Function to get user information
user_info_t get_user_info(void) {
    char name[MAX_NAME_LENGTH];
    int age;

    // Get name from user
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Get age from user
    printf("Enter your age: ");
    scanf("%d", &age);

    // Check if age is valid
    if (age < 0 || age > MAX_AGE) {
        printf("Invalid age. Please enter a valid age.\n");
        return (user_info_t) {0, 0};
    }

    return (user_info_t) {name, age};
}

// Function to handle errors
void handle_error(const char* message) {
    printf("Error: %s\n", message);

    // If the error is a invalid input, print a message and exit
    if (strstr(message, "Invalid") != NULL) {
        printf("Please enter valid input.\n");
        exit(1);
    }

    // If the error is a division by zero, print a message and exit
    if (strstr(message, "divide") != NULL) {
        printf("Division by zero encountered. Exiting...\n");
        exit(2);
    }
}

int main(void) {
    user_info_t user_info = get_user_info();

    // Print user information
    printf("Your name is: %s\n", user_info.name);
    printf("Your age is: %d\n", user_info.age);

    // Check if name is empty
    if (user_info.name[0] == '\0') {
        handle_error("Please enter a valid name.");
    }

    // Check if age is out of range
    if (user_info.age < 0 || user_info.age > MAX_AGE) {
        handle_error("Invalid age. Please enter a valid age.");
    }

    return 0;
}