//Falcon-180B DATASET v1.0 Category: Password management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 10
#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

int main() {
    int numUsers = 0;
    User users[MAX_USERS];
    char choice;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    do {
        printf("Welcome to the Password Manager!\n");
        printf("Please choose an option:\n");
        printf("1. Create a new user\n");
        printf("2. Login as an existing user\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter a new username: ");
                scanf("%s", username);
                numUsers++;
                strcpy(users[numUsers-1].username, username);
                printf("Enter a new password: ");
                scanf("%s", password);
                strcpy(users[numUsers-1].password, password);
                printf("User '%s' created successfully!\n", username);
                break;
            case '2':
                printf("Enter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);
                for(int i=0; i<numUsers; i++) {
                    if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                        printf("Login successful!\n");
                        break;
                    } else {
                        printf("Incorrect username or password.\n");
                    }
                }
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= '3');

    return 0;
}