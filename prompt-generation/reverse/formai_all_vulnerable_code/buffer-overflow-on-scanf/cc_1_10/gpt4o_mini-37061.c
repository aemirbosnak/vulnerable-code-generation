//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_AGE 150

// Struct to hold user data
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} User;

// Function to get user data
int getUserData(User *user) {
    printf("Enter your name: ");
    if (fgets(user->name, sizeof(user->name), stdin) == NULL) {
        fprintf(stderr, "Error reading name. Please try again.\n");
        return -1;
    }
    // Remove newline character from string if present
    user->name[strcspn(user->name, "\n")] = 0;

    printf("Enter your age: ");
    if (scanf("%d", &user->age) != 1) {
        fprintf(stderr, "Error reading age. Please enter a valid number.\n");
        return -1;
    }
    // Check if age is within valid bounds
    if (user->age < 0 || user->age > MAX_AGE) {
        fprintf(stderr, "Age must be between 0 and %d. Please try again!\n", MAX_AGE);
        return -1;
    }
    return 0;
}

// Function to display user data
void displayUserData(const User *user) {
    printf("\n--- User Information ---\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("------------------------\n");
}

// Main function
int main() {
    User user;

    printf("Welcome to the User Information Program!\n");
    printf("Let's collect some fun data about you!\n\n");

    // Get user data
    while (getUserData(&user) != 0) {
        printf("Oops! There was a problem. Let's try again!\n");
        // Clear the input buffer in case of errors
        while (getchar() != '\n');
    }

    // Display user data
    displayUserData(&user);

    printf("Thank you for sharing your information! Have a wonderful day!\n");

    return 0;
}