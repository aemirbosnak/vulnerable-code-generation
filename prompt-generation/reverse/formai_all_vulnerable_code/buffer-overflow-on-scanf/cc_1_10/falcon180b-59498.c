//Falcon-180B DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];
} User;

User users[MAX_USERS];
int numUsers = 0;

void printMenu() {
    printf("Password Manager Menu:\n");
    printf("1. Create new user\n");
    printf("2. Login\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    char username[MAX_USERNAME_LENGTH + 1];
    char password[MAX_PASSWORD_LENGTH + 1];

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);

                printf("Enter password: ");
                scanf("%s", password);

                for(int i = 0; i < numUsers; i++) {
                    if(strcmp(users[i].username, username) == 0) {
                        printf("User already exists.\n");
                        break;
                    }
                }

                if(numUsers == MAX_USERS) {
                    printf("Maximum number of users reached.\n");
                } else {
                    strcpy(users[numUsers].username, username);
                    strcpy(users[numUsers].password, password);
                    numUsers++;
                    printf("User created successfully.\n");
                }
                break;

            case 2:
                printf("Enter username: ");
                scanf("%s", username);

                for(int i = 0; i < numUsers; i++) {
                    if(strcmp(users[i].username, username) == 0) {
                        printf("Enter password: ");
                        scanf("%s", password);

                        if(strcmp(password, users[i].password) == 0) {
                            printf("Login successful.\n");
                            break;
                        } else {
                            printf("Incorrect password.\n");
                        }
                    }
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 3);

    return 0;
}