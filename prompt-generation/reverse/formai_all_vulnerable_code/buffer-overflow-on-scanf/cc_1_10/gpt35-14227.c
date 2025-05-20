//FormAI DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 20
#define MAX_PASS_LEN 16
#define MAX_NAME_LEN 32

// struct to hold user info
typedef struct {
    char name[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
} User;

// global array of all users
User users[MAX_USERS];

// tracks number of users currently registered
int numUsers = 0;

// function to add a new user
void addUser(char name[], char password[]) {
    if(numUsers >= MAX_USERS) {
        printf("Error: Max number of users reached\n");
        return;
    }

    User newUser;
    strcpy(newUser.name, name);
    strcpy(newUser.password, password);

    users[numUsers++] = newUser;

    printf("User %s added successfully\n", name);
}

// function to check if a user already exists
bool userExists(char name[]) {
    for(int i = 0; i < numUsers; i++) {
        if(strcmp(users[i].name, name) == 0) {
            return true;
        }
    }

    return false;
}

// function to delete a user
void deleteUser(char name[]) {
    bool found = false;

    for(int i = 0; i < numUsers; i++) {
        if(strcmp(users[i].name, name) == 0) {
            found = true;
            numUsers--;

            for(int j = i; j < numUsers; j++) {
                users[j] = users[j+1];
            }

            printf("User %s deleted successfully\n", name);
            break;
        }
    }

    if(!found) {
        printf("Error: User not found\n");
    }
}

// main function to run the program
int main() {
    char command;
    char name[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];

    while(true) {
        printf("Enter command (a = add, d = delete, q = quit): ");
        scanf(" %c", &command);

        switch(command) {
            case 'a':
                printf("Enter username: ");
                scanf("%s", name);

                if(userExists(name)) {
                    printf("Error: User already exists\n");
                    break;
                }

                printf("Enter password: ");
                scanf("%s", password);

                addUser(name, password);
                break;

            case 'd':
                printf("Enter username: ");
                scanf("%s", name);

                deleteUser(name);
                break;

            case 'q':
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Error: Invalid command\n");
                break;
        }
    }

    return 0;
}