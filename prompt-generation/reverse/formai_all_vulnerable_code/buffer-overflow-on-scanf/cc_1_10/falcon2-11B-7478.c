//Falcon2-11B DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* username;
    char* password;
} User;

int main() {
    User users[10];
    int numUsers = 0;
    
    // Prompt user to enter number of users
    printf("Enter number of users: ");
    scanf("%d", &numUsers);
    
    // Prompt user to enter each user's information
    for (int i = 0; i < numUsers; i++) {
        char username[100];
        char password[100];
        
        printf("User %d: ", i + 1);
        scanf("%s", username);
        scanf("%s", password);
        
        User* newUser = malloc(sizeof(User));
        newUser->username = strdup(username);
        newUser->password = strdup(password);
        
        users[i] = *newUser;
        free(newUser);
        
        printf("User %d added!\n", i + 1);
    }
    
    // Prompt user to enter username and password
    char username[100];
    char password[100];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Password for user %s: ", users[i].username);
            printf("%s\n", users[i].password);
            break;
        }
    }
    
    // Prompt user to enter new password
    char newPassword[100];
    
    printf("Enter new password: ");
    scanf("%s", newPassword);
    
    // Prompt user to enter user's information
    char userInfo[100];
    
    printf("Enter user's information: ");
    scanf("%s", userInfo);
    
    // Update user's password
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            users[i].password = strdup(newPassword);
            printf("Password updated for user %s\n", users[i].username);
            break;
        }
    }
    
    // Prompt user to enter username to delete
    char deleteUsername[100];
    
    printf("Enter username to delete: ");
    scanf("%s", deleteUsername);
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, deleteUsername) == 0) {
            free(users[i].username);
            free(users[i].password);
            free(users[i].password);
            users[i] = users[numUsers - 1];
            numUsers--;
            printf("User %s deleted!\n", users[i].username);
            break;
        }
    }
    
    // Print all users
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: %s, %s\n", i + 1, users[i].username, users[i].password);
    }
    
    return 0;
}