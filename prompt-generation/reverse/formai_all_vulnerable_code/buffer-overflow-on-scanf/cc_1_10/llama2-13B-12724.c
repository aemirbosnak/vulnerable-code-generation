//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Structure to hold user information
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} user_t;

// Function to print a surprised message
void surprise(const char *message) {
    printf("O_O WOW! %s\n", message);
}

// Function to ask for user information
void ask_for_info(user_t *user) {
    printf("Hello there! Please enter your name: ");
    fgets(user->name, MAX_NAME_LEN, stdin);
    printf("And your age: ");
    scanf("%d", &user->age);
}

// Function to print a surprised message based on user information
void print_surprise(user_t *user) {
    surprise(user->name);
    if (user->age > MAX_AGE) {
        surprise("You're so old!");
    } else if (user->age < 18) {
        surprise("You're so young!");
    } else {
        surprise("You're just right!");
    }
}

int main() {
    user_t user;

    // Ask for user information
    ask_for_info(&user);

    // Print a surprised message based on user information
    print_surprise(&user);

    return 0;
}