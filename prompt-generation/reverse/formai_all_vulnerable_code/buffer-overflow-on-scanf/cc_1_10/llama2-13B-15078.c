//LLAMA2-13B DATASET v1.0 Category: Game ; Style: modular
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
} user_t;

// Function to print a welcome message
void welcome(void) {
    printf("Welcome to the user information program!\n");
}

// Function to get user name and age
user_t get_user_info(void) {
    printf("Please enter your name: ");
    char name[MAX_NAME_LENGTH];
    fgets(name, MAX_NAME_LENGTH, stdin);
    printf("Please enter your age: ");
    int age;
    scanf("%d", &age);
    return (user_t) { .name = name, .age = age };
}

// Function to print user information
void print_user_info(user_t user) {
    printf("Your name is %s, and you are %d years old.\n", user.name, user.age);
}

// Main program
int main() {
    srand(time(NULL));

    // Call welcome function
    welcome();

    // Get user information
    user_t user = get_user_info();

    // Print user information
    print_user_info(user);

    return 0;
}