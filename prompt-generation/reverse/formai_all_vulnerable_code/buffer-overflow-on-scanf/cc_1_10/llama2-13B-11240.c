//LLAMA2-13B DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 256
#define MAX_AGE 100

// Structure to store user information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} user_info;

// Function to get user information
void get_user_info(user_info *user) {
    printf("Enter your name: ");
    fgets(user->name, MAX_NAME_LENGTH, stdin);
    user->age = get_age();
}

// Function to get the user's age
int get_age() {
    int age;
    printf("Enter your age: ");
    scanf("%d", &age);
    return age;
}

// Function to print the user information
void print_user_info(user_info user) {
    printf("Hello, %s! You are %d years old.\n", user.name, user.age);
}

int main() {
    user_info user;

    // Get user information
    get_user_info(&user);

    // Print user information
    print_user_info(user);

    // Get user information again
    get_user_info(&user);

    // Print user information again
    print_user_info(user);

    return 0;
}