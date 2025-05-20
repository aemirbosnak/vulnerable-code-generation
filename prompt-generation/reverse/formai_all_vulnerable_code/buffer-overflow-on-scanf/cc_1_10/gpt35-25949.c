//FormAI DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20 // maximum length of the password
#define MAX_ATTEMPTS 3 // maximum number of login attempts

struct account {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

int main() {
    struct account user1 = {"JohnDoe", "password123"}; // replace with your own username and password
    struct account user2 = {"JaneDoe", "password456"}; // replace with your own username and password
    struct account user3 = {"BobSmith", "password789"}; // replace with your own username and password
    
    struct account users[3] = {user1, user2, user3}; // array of user accounts
    
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    int attempts = 0; // number of login attempts
    
    printf("Welcome to the password management system.\n");
    
    while (1) {
        printf("Username: ");
        scanf("%s", username);
        
        printf("Password: ");
        scanf("%s", password);
        
        // search for the user account
        int found = 0;
        for (int i = 0; i < 3; i++) {
            if (strcmp(users[i].username, username) == 0) {
                found = 1;
                if (strcmp(users[i].password, password) == 0) {
                    printf("Login success!\n");
                    // do something after successful login
                    break;
                } else {
                    printf("Incorrect password. Please try again.\n");
                    attempts++;
                    break;
                }
            }
        }
        
        if (!found) {
            printf("Username not found. Please try again.\n");
        }
        
        if (attempts >= MAX_ATTEMPTS) {
            printf("Maximum login attempts exceeded. Exiting program...\n");
            exit(0);
        }
    }
    
    return 0;
}