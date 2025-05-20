//FormAI DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define MAX_LENGTH 100

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} User;

int num_of_users = 0;

User users[MAX_USERS];

int addUser(char* username, char* password) {
    if (num_of_users >= MAX_USERS) {
        return -1;
    }
    
    strcpy(users[num_of_users].username, username);
    strcpy(users[num_of_users].password, password);
    num_of_users++;
    
    return 0;
}

int checkPassword(char* username, char* password) {
    for (int i = 0; i < num_of_users; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    
    printf("Welcome to the Password Management program!\n");
    printf("Please create a new account.\n\n");
    
    while (1) {
        printf("Enter your username: ");
        scanf("%s", username);
        
        printf("Enter your password: ");
        scanf("%s", password);
        
        if (addUser(username, password) == 0) {
            printf("Account created successfully.\n");
            break;
        } else {
            printf("Maximum number of users exceeded. Please try again later.\n");
        }
    }
    
    printf("\nPlease log in to your account.\n\n");
    
    while (1) {
        printf("Enter your username: ");
        scanf("%s", username);
        
        printf("Enter your password: ");
        scanf("%s", password);
        
        if (checkPassword(username, password)) {
            printf("Login successful. Welcome back, %s!\n", username);
            break;
        } else {
            printf("Invalid username or password. Please try again.\n");
        }
    }
    
    return 0;
}