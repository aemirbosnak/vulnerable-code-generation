//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

struct user {
    char username[MAX_PASSWORDS];
    char password[MAX_PASSWORDS];
};

int main() {
    int choice;
    char username[MAX_PASSWORDS];
    char password[MAX_PASSWORDS];
    struct user users[MAX_USERS];
    int num_users = 0;

    printf("Welcome to the password manager!\n");
    printf("Please choose an option:\n");
    printf("1. Create a new account\n");
    printf("2. Log in to an existing account\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a username: ");
            scanf("%s", username);
            printf("Enter a password: ");
            scanf("%s", password);

            for(int i = 0; i < num_users; i++) {
                if(strcmp(users[i].username, username) == 0) {
                    printf("User already exists!\n");
                    break;
                }
            }

            strcpy(users[num_users].username, username);
            strcpy(users[num_users].password, password);
            num_users++;

            printf("User created successfully!\n");
            break;

        case 2:
            printf("Enter a username: ");
            scanf("%s", username);

            for(int i = 0; i < num_users; i++) {
                if(strcmp(users[i].username, username) == 0) {
                    printf("Enter password: ");
                    scanf("%s", password);

                    if(strcmp(users[i].password, password) == 0) {
                        printf("Login successful!\n");
                    } else {
                        printf("Incorrect password!\n");
                    }

                    break;
                }
            }

            printf("User not found!\n");
            break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}