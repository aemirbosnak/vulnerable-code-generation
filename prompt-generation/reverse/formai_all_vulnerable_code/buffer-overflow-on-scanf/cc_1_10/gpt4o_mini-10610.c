//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_NAME_LENGTH 50

// Structure to store user information
typedef struct {
    char *name;
    int age;
} User;

// Function to create a new User and allocate memory for the name
User* create_user(const char *name, int age) {
    User *new_user = (User*)malloc(sizeof(User));
    if (new_user == NULL) {
        fprintf(stderr, "Memory allocation failed for user.\n");
        exit(EXIT_FAILURE);
    }

    new_user->age = age;

    // Allocate memory for the user's name
    new_user->name = (char*)malloc(strlen(name) + 1); // +1 for the null terminator
    if (new_user->name == NULL) {
        fprintf(stderr, "Memory allocation failed for user name.\n");
        free(new_user);
        exit(EXIT_FAILURE);
    }

    strcpy(new_user->name, name);
    return new_user;
}

// Function to free the memory allocated for a User
void free_user(User *user) {
    if (user != NULL) {
        free(user->name);
        free(user);
    }
}

// Function to print user details
void print_user(const User *user) {
    if (user != NULL) {
        printf("User Name: %s\n", user->name);
        printf("User Age: %d\n", user->age);
    }
}

// Function to load multiple users into an array
void load_users(User **users, int count) {
    char name[MAX_NAME_LENGTH];
    int age;

    for (int i = 0; i < count; i++) {
        printf("Enter name for user %d: ", i + 1);
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character

        printf("Enter age for user %d: ", i + 1);
        scanf("%d", &age);
        getchar(); // Consume the newline character left in the buffer

        users[i] = create_user(name, age);
    }
}

// Function to print all users
void print_all_users(User **users, int count) {
    for (int i = 0; i < count; i++) {
        print_user(users[i]);
    }
}

int main() {
    User *users[MAX_USERS];

    printf("Welcome to the User Registration System!\n");

    load_users(users, MAX_USERS);

    printf("\nRegistered Users:\n");
    print_all_users(users, MAX_USERS);

    // Free allocated memory
    for (int i = 0; i < MAX_USERS; i++) {
        free_user(users[i]);
    }

    printf("Goodbye!\n");
    return 0;
}