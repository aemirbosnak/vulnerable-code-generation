//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define NAME_LENGTH 50

struct User {
    int id;
    char name[NAME_LENGTH];
};

void displayUsers(struct User *users, int count) {
    if (count == 0) {
        printf("No users to display.\n");
        return;
    }

    printf("User List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", users[i].id, users[i].name);
    }
}

struct User* allocateUsers(int count) {
    struct User *users = (struct User*) malloc(count * sizeof(struct User));
    if (users == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return users;
}

void initializeUsers(struct User *users, int count) {
    for (int i = 0; i < count; i++) {
        users[i].id = i + 1;
        snprintf(users[i].name, NAME_LENGTH, "User%d", i + 1);
    }
}

void freeUsers(struct User *users) {
    free(users);
}

int main() {
    int userCount;

    printf("Enter number of users to create (max %d): ", MAX_USERS);
    scanf("%d", &userCount);
    
    if (userCount < 1 || userCount > MAX_USERS) {
        fprintf(stderr, "Invalid number of users. Should be between 1 and %d.\n", MAX_USERS);
        exit(EXIT_FAILURE);
    }

    struct User *users = allocateUsers(userCount);
    initializeUsers(users, userCount);
    
    displayUsers(users, userCount);
    
    char choice;
    do {
        printf("Do you want to add a new user? (y/n): ");
        getchar(); // To consume the newline character
        choice = getchar();
        
        if (choice == 'y') {
            if (userCount < MAX_USERS) {
                struct User newUser;
                newUser.id = userCount + 1;
                printf("Enter name for User%d: ", newUser.id);
                getchar(); // Consume newline from previous input
                fgets(newUser.name, NAME_LENGTH, stdin);
                newUser.name[strcspn(newUser.name, "\n")] = 0; // Remove newline
                
                // Resize the users array
                struct User *temp = (struct User*) realloc(users, (userCount + 1) * sizeof(struct User));
                if (temp == NULL) {
                    fprintf(stderr, "Memory reallocation failed!\n");
                    freeUsers(users);
                    exit(EXIT_FAILURE);
                }
                
                users = temp;
                users[userCount] = newUser;
                userCount++;
                
                displayUsers(users, userCount);
            } else {
                printf("Maximum user limit reached. Cannot add more users.\n");
            }
        }
        
    } while (choice == 'y');
    
    freeUsers(users);
    printf("Memory freed and program terminated.\n");
    
    return 0;
}