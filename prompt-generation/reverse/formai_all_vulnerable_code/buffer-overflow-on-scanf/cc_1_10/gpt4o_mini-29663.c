//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_USERS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} User;

typedef struct {
    User *users[MAX_USERS];
    int userCount;
} UserManager;

UserManager *createUserManager() {
    UserManager *manager = (UserManager *)malloc(sizeof(UserManager));
    if (manager == NULL) {
        fprintf(stderr, "Failed to allocate memory for UserManager.\n");
        exit(EXIT_FAILURE);
    }
    manager->userCount = 0;
    return manager;
}

User *createUser(const char *name, int age) {
    if (age < 0) {
        fprintf(stderr, "Error: Age cannot be negative.\n");
        return NULL;
    }
    
    User *user = (User *)malloc(sizeof(User));
    if (user == NULL) {
        fprintf(stderr, "Failed to allocate memory for User '%s'.\n", name);
        return NULL;
    }
    
    strncpy(user->name, name, MAX_NAME_LENGTH - 1);
    user->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    user->age = age;
    
    return user;
}

int addUser(UserManager *manager, User *user) {
    if (manager->userCount >= MAX_USERS) {
        fprintf(stderr, "Error: Cannot add user, max number reached.\n");
        return -1;
    }
    
    if (user == NULL) {
        fprintf(stderr, "Error: Null user cannot be added.\n");
        return -1;
    }
    
    manager->users[manager->userCount++] = user;
    return 0;
}

void freeUser(User *user) {
    if (user != NULL) {
        free(user);
    }
}

void freeUserManager(UserManager *manager) {
    if (manager != NULL) {
        for (int i = 0; i < manager->userCount; i++) {
            freeUser(manager->users[i]);
        }
        free(manager);
    }
}

void printUsers(UserManager *manager) {
    if (manager->userCount == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("Registered Users:\n");
    for (int i = 0; i < manager->userCount; i++) {
        printf("Name: %s, Age: %d\n", manager->users[i]->name, manager->users[i]->age);
    }
}

int main() {
    UserManager *manager = createUserManager();
    
    char name[MAX_NAME_LENGTH];
    int age;
    
    while (1) {
        printf("Enter user name (or 'exit' to stop): ");
        fgets(name, MAX_NAME_LENGTH, stdin);
        name[strcspn(name, "\n")] = 0; // Remove trailing newline

        if (strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter age: ");
        if (scanf("%d", &age) != 1) {
            fprintf(stderr, "Invalid input. Age must be a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        
        while (getchar() != '\n'); // Clear input buffer for next entry
        
        User *user = createUser(name, age);
        if (addUser(manager, user) != 0) {
            freeUser(user); // Clean up memory if user could not be added
        }
    }
    
    printUsers(manager);
    
    freeUserManager(manager);
    
    return 0;
}