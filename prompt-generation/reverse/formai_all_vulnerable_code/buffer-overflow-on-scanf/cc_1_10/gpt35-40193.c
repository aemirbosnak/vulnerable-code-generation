//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30
#define MAX_USERS 10

struct user{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void addUser(int *numberOfUsers, struct user *database);
int authenticate(struct user *database, int numberOfUsers);
void changePassword(struct user *database, int userIndex);

int main(){
    struct user database[MAX_USERS];
    int numberOfUsers = 0;
    int authenticatedUser = -1;
    int menuChoice = 0;
    printf("Welcome to the Password Manager!\n");

    do{
        printf("\nMenu\n");
        printf("====\n");
        printf("1 - Add user\n");
        printf("2 - Authenticate\n");
        printf("3 - Change password\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menuChoice);
        switch(menuChoice){
            case 1:
                addUser(&numberOfUsers, database);
                break;
            case 2:
                authenticatedUser = authenticate(database, numberOfUsers);
                if(authenticatedUser != -1){
                    printf("Authentication successful!\n");
                } else {
                    printf("Authentication failed!\n");
                }
                break;
            case 3:
                if(authenticatedUser != -1){
                    changePassword(database, authenticatedUser);
                } else {
                    printf("You must first authenticate!\n");
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(menuChoice != 4);

    return 0;
}

void addUser(int *numberOfUsers, struct user *database){
    if(*numberOfUsers == MAX_USERS){
        printf("Error: Maximum number of users reached!\n");
    } else {
        printf("Enter username: ");
        scanf("%s", database[*numberOfUsers].username);
        printf("Enter password: ");
        scanf("%s", database[*numberOfUsers].password);
        (*numberOfUsers)++;
    }
}

int authenticate(struct user *database, int numberOfUsers){
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int i;
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    for(i = 0; i < numberOfUsers; i++){
        if(strcmp(username, database[i].username) == 0 && strcmp(password, database[i].password) == 0){
            return i;
        }
    }
    return -1;
}

void changePassword(struct user *database, int userIndex){
    char newPassword[MAX_PASSWORD_LENGTH];
    printf("Enter new password: ");
    scanf("%s", newPassword);
    strcpy(database[userIndex].password, newPassword);
    printf("Password changed successfully!\n");
}