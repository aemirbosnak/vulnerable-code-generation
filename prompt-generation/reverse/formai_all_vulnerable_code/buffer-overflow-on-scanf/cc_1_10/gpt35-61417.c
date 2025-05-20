//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOGIN_ATTEMPTS 3  // Maximum allowed failed login attempts
#define INVALID_LOGIN -1  // Return value when login fails

// Struct to store information about individual login attempts
struct LoginAttempt {
    char username[20];
    char password[20];
    int attempts;
};

// Function to check if a login attempt is valid
int login(char *username, char *password) {
    // Simulating a database lookup
    if(strcmp(username, "admin") == 0 && strcmp(password, "password") == 0) {
        return 1;
    }
    return INVALID_LOGIN;
}

// Function to detect and respond to potential intrusions
void detectIntrusion(struct LoginAttempt *la) {
    if(la->attempts >= MAX_LOGIN_ATTEMPTS) {
        printf("Potential intrusion detected for username: %s\n", la->username);
        // TODO: Add code to handle potential intrusion
    }
}

int main() {
    struct LoginAttempt la = {"admin", "wrongpassword", 0};
    
    int loggedIn = login(la.username, la.password);
    
    while(loggedIn == INVALID_LOGIN) {
        printf("Incorrect login details!\n");
        la.attempts++;
        detectIntrusion(&la);
        
        printf("Please enter your username: ");
        scanf("%s", la.username);
        printf("Please enter your password: ");
        scanf("%s", la.password);
        
        loggedIn = login(la.username, la.password);
    }
    
    printf("Welcome, %s!\n", la.username);
    
    return 0;
}