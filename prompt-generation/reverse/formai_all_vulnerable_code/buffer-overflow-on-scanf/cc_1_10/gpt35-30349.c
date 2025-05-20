//FormAI DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LEN 12
#define MAX_ATTEMPTS 3

struct User {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
};

struct User userDb[MAX_USERS];
int userCount = 0;

int authenticate(char* username, char* password) {
    for (int i=0; i<userCount; i++) {
        if (strcmp(userDb[i].username, username) == 0 && strcmp(userDb[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

void createNewUser(char* username, char* password) {
    if (userCount >= MAX_USERS) {
        printf("Max number of users exceeded\n");
        return;
    }
    
    struct User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    userDb[userCount++] = newUser;
}

void displayMenu() {
    printf("\n1. Create a new user\n");
    printf("2. Authenticate a user\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char username[MAX_PASSWORD_LEN], password[MAX_PASSWORD_LEN];
    
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                createNewUser(username, password);
                printf("\nUser created successfully!\n");
                break;
            case 2:
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                int isAuthenticated = authenticate(username, password);
                if (isAuthenticated) {
                    printf("\nAuthentication successful!\n");
                } else {
                    printf("\nAuthentication failed, please try again!\n");
                    int attempts = 1;
                    while (attempts < MAX_ATTEMPTS) {
                        printf("\nEnter password again (attempt %d/%d): ", attempts+1, MAX_ATTEMPTS);
                        scanf("%s", password);
                        isAuthenticated = authenticate(username, password);
                        if (isAuthenticated) {
                            printf("\nAuthentication successful!\n");
                            break;
                        } else {
                            printf("\nAuthentication failed, please try again!\n");
                            attempts++;
                        }
                    }
                    if (attempts >= MAX_ATTEMPTS) {
                        printf("\nMaximum login attempts exceeded! Please try again later.\n");
                    }
                }
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}