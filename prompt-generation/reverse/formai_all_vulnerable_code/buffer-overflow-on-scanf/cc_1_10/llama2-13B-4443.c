//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

// Structure to hold user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} user_info_t;

// Function to get user information
void get_user_info(user_info_t *user) {
    printf("Enter your name: ");
    fgets(user->name, MAX_NAME_LENGTH, stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove newline character

    printf("Enter your age: ");
    scanf("%d", &user->age);

    // Check if age is valid
    if (user->age < 0 || user->age > MAX_AGE) {
        printf("Invalid age. Please enter a valid age between 1 and %d.\n", MAX_AGE);
        get_user_info(user);
        return;
    }
}

// Function to print a message based on user information
void print_message(user_info_t user) {
    if (user.age < 18) {
        printf("Hello there, young one!");
    } else {
        printf("Hello, respected elder!");
    }

    if (strlen(user.name) > 10) {
        printf("Your name is quite long, isn't it?");
    }
}

int main() {
    user_info_t user;

    // Get user information
    get_user_info(&user);

    // Print message based on user information
    print_message(user);

    return 0;
}