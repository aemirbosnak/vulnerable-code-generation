//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_USERS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} User;

void createUser(User *users, int index) {
    printf("Enter name for user %d: ", index + 1);
    fgets(users[index].name, MAX_NAME_LENGTH, stdin);
    users[index].name[strcspn(users[index].name, "\n")] = 0; // remove newline character

    printf("Enter age for user %d: ", index + 1);
    scanf("%d", &users[index].age);
    getchar(); // consume newline character left by scanf
}

void displayUsers(User *users, int count) {
    printf("\n--- User List ---\n");
    for (int i = 0; i < count; i++) {
        printf("User %d: Name: %s, Age: %d\n", i + 1, users[i].name, users[i].age);
    }
}

void freeMemory(User *users) {
    free(users);
}

int main() {
    int userCount = 0;
    User *users = (User *)malloc(MAX_USERS * sizeof(User));

    if (users == NULL) {
        fprintf(stderr, "Memory allocation failed!");
        return 1;
    }

    char choice;
    do {
        if (userCount >= MAX_USERS) {
            printf("Maximum user limit reached. Cannot add more users.\n");
            break;
        }
        
        createUser(users, userCount);
        userCount++;
        
        printf("Do you want to add another user? (y/n): ");
        choice = getchar();
        getchar(); // consume newline character
    } while (choice == 'y' || choice == 'Y');

    displayUsers(users, userCount);
    freeMemory(users);
    
    return 0;
}