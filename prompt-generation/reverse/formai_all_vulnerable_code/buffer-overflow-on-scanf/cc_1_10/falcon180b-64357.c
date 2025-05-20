//Falcon-180B DATASET v1.0 Category: Password management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void addUser(struct user *users, int numUsers, char *username, char *password) {
    if (numUsers >= MAX_PASSWORDS) {
        printf("Error: maximum number of users reached.\n");
        return;
    }
    
    strcpy(users[numUsers].username, username);
    strcpy(users[numUsers].password, password);
    
    numUsers++;
}

int login(struct user *users, int numUsers, char *username, char *password) {
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    struct user users[MAX_PASSWORDS];
    int numUsers = 0;
    
    printf("Welcome to Password Manager!\n");
    
    while (1) {
        printf("\n");
        printf("1. Add user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char username[MAX_USERNAME_LENGTH];
                char password[MAX_PASSWORD_LENGTH];
                
                printf("Enter username: ");
                scanf("%s", username);
                
                printf("Enter password: ");
                scanf("%s", password);
                
                addUser(users, numUsers, username, password);
                printf("User added successfully.\n");
                
                break;
            }
            case 2: {
                char username[MAX_USERNAME_LENGTH];
                char password[MAX_PASSWORD_LENGTH];
                
                printf("Enter username: ");
                scanf("%s", username);
                
                printf("Enter password: ");
                scanf("%s", password);
                
                if (login(users, numUsers, username, password)) {
                    printf("Login successful.\n");
                } else {
                    printf("Login failed.\n");
                }
                
                break;
            }
            case 3: {
                printf("Exiting program...\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    }
    
    return 0;
}