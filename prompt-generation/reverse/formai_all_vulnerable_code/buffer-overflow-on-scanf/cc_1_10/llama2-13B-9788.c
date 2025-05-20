//LLAMA2-13B DATASET v1.0 Category: Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 120

// Structure to hold user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} user_info_t;

// Function to get user information
void get_user_info(user_info_t *user) {
    printf("Welcome, please enter your name: ");
    fgets(user->name, MAX_NAME_LENGTH, stdin);
    user->age = get_age();
}

// Function to get age
int get_age() {
    int age;
    printf("Please enter your age: ");
    scanf("%d", &age);
    return age;
}

// Function to print a message based on user's age
void print_message(user_info_t *user) {
    if (user->age >= 18 && user->age <= 64) {
        printf("Hello, young adult! You have a lot of life ahead of you.\n");
    } else if (user->age > 64 && user->age <= 100) {
        printf("Hello, wise elder! You have lived a long and fulfilling life.\n");
    } else {
        printf("Hello, young one! You have a bright future ahead of you.\n");
    }
}

int main() {
    user_info_t user;

    // Get user information
    get_user_info(&user);

    // Print message based on user's age
    print_message(&user);

    return 0;
}