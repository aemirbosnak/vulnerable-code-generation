//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_USERS 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} User;

void printUsers(User *users, int count) {
    printf("\n--- List of Users ---\n");
    for (int i = 0; i < count; i++) {
        printf("User %d: Name: %s, Age: %d\n", i + 1, users[i].name, users[i].age);
    }
    printf("----------------------\n");
}

void freeUsers(User *users) {
    free(users);
    printf("Memory for users released.\n");
}

User* createUser(const char *name, int age) {
    User *newUser = (User *)malloc(sizeof(User));
    if (newUser == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newUser->name, name, MAX_NAME_LENGTH);
    newUser->age = age;
    return newUser;
}

int main() {
    User *users = (User *)malloc(MAX_USERS * sizeof(User));
    if (users == NULL) {
        fprintf(stderr, "Memory allocation for users failed\n");
        exit(EXIT_FAILURE);
    }

    int userCount = 0;
    char name[MAX_NAME_LENGTH];
    int age;

    while (userCount < MAX_USERS) {
        printf("Enter name of User %d (or type 'exit' to finish): ", userCount + 1);
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // Remove newline character

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age of User %d: ", userCount + 1);
        if (scanf("%d", &age) != 1) {
            fprintf(stderr, "Invalid age entered.\n");
            // Clearing input buffer
            while (getchar() != '\n');
            continue;
        }

        users[userCount] = *createUser(name, age); // Creating user and storing it directly
        userCount++;

        // Clearing input buffer after reading age
        while (getchar() != '\n');
    }

    printUsers(users, userCount); // Display the list of users
    freeUsers(users); // Free allocated memory for users

    return 0;
}