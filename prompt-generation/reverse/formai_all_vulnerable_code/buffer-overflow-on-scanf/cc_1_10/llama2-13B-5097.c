//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100

// Structure to hold user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} user_info_t;

// Function to get user information and validate inputs
user_info_t get_user_info() {
    user_info_t user;
    printf("Enter your name: ");
    fgets(user.name, MAX_NAME_LENGTH, stdin);
    user.name[strcspn(user.name, "\n")] = '\0'; // Remove newline character

    printf("Enter your age: ");
    scanf("%d", &user.age);

    // Check if age is valid
    if (user.age < 0 || user.age > MAX_AGE) {
        printf("Invalid age! Please enter a valid age between 0 and %d\n", MAX_AGE);
        get_user_info(); // Call function again to get valid input
    }

    return user;
}

int main() {
    user_info_t user;

    do {
        // Get user information and validate inputs
        user = get_user_info();

        // Print user information
        printf("Hello, %s! You are %d years old.\n", user.name, user.age);

        // Generate a random number between 1 and 10
        int random_number = rand() % 10 + 1;

        // Check if random number is less than or equal to age
        if (random_number <= user.age) {
            printf("You are young and have a bright future ahead of you! \n");
        } else {
            printf("You are getting old, but you can still achieve your dreams! \n");
        }

    } while (1); // Loop indefinitely

    return 0;
}