//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_USERS 5

typedef struct User {
    char name[MAX_NAME_LENGTH];
    int age;
} User;

void display_users(User* users, int user_count) {
    printf("List of Users:\n");
    for (int i = 0; i < user_count; i++) {
        printf("User %d: Name: %s, Age: %d\n", i+1, users[i].name, users[i].age);
    }
}

User* create_user(const char* name, int age) {
    User* new_user = (User*)malloc(sizeof(User));
    if (new_user == NULL) {
        fprintf(stderr, "Error allocating memory for user!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_user->name, name, MAX_NAME_LENGTH - 1);
    new_user->name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null-termination
    new_user->age = age;
    return new_user;
}

void free_user(User* user) {
    if (user != NULL) {
        free(user);
        user = NULL; // Prevent dangling pointer
    }
}

void simulate_user_management() {
    User* users[MAX_USERS];
    int user_count = 0;

    while (user_count < MAX_USERS) {
        char name[MAX_NAME_LENGTH];
        int age;
        printf("\nEnter name of user %d: ", user_count + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character
        
        if (strlen(name) == 0) {
            printf("No name entered. Exiting...\n");
            break;
        }

        printf("Enter age of user %d: ", user_count + 1);
        if (scanf("%d", &age) != 1) {
            printf("Invalid age input. Exiting...\n");
            break;
        }

        // Consume the newline character left by scanf
        while ((getchar()) != '\n');

        users[user_count] = create_user(name, age);
        user_count++;
    }

    display_users(users, user_count);

    // Free allocated memory
    for (int i = 0; i < user_count; i++) {
        free_user(users[i]);
    }

    printf("Memory cleared. Program finished successfully!\n");
}

int main() {
    printf("Welcome to the User Management System!\n");
    printf("You can enter up to %d users.\n", MAX_USERS);
    simulate_user_management();
    return 0;
}