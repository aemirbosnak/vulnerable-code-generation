//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERS 50

struct User {
    char name[50];
    char password[MAX_PASSWORD_LENGTH];
};

struct User userList[MAX_USERS];
int numberOfUsers = 0;

void addUser() {
    printf("Enter username: ");
    scanf("%s", userList[numberOfUsers].name);

    printf("Enter password: ");
    scanf("%s", userList[numberOfUsers].password);

    numberOfUsers++;
}

int checkUser(char* username, char* password) {
    for(int i=0; i<numberOfUsers; i++) {
        if(strcmp(userList[i].name, username) == 0 && strcmp(userList[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the Password Manager!\n");

    while(1) {
        printf("\nEnter 1 to add a user\nEnter 2 to check a user\nEnter 3 to exit\n");
        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            addUser();
            printf("\nUser added successfully!\n");
        } else if(choice == 2) {
            char username[50];
            char password[MAX_PASSWORD_LENGTH];

            printf("Enter username: ");
            scanf("%s", username);

            printf("Enter password: ");
            scanf("%s", password);

            if(checkUser(username, password)) {
                printf("\nUser found!\n");
            } else {
                printf("\nUser not found.\n");
            }
        } else if(choice == 3) {
            printf("\nExiting...\n");
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}