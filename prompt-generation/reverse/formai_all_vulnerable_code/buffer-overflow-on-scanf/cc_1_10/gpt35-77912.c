//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USERS 1000
#define MAX_PASS_LEN 20

// Struct for user credentials
struct User {
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
};

// Array of registered users
struct User users[MAX_USERS];

// Counter for number of registered users
int num_users = 0;

// Function to check if user is registered
int check_user(char *username) {
    int i;
    for(i=0; i<num_users; i++) {
        if(strcmp(users[i].username, username) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add new user
void add_user() {
    char username[MAX_PASS_LEN];
    char password[MAX_PASS_LEN];
    
    printf("Enter new username: ");
    scanf("%s", username);
    
    if(check_user(username)) {
        printf("ERROR: Username already exists\n");
        return;
    }
    
    printf("Enter new password: ");
    scanf("%s", password);
    
    struct User new_user;
    strcpy(new_user.username, username);
    strcpy(new_user.password, password);
    
    users[num_users] = new_user;
    num_users++;
    
    printf("SUCCESS: New user added\n");
}

// Function to check user credentials
int check_credentials(char *username, char *password) {
    int i;
    for(i=0; i<num_users; i++) {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to detect intrusion attempts
void detect_intrusion(char *username, char *password) {
    if(!check_user(username)) {
        printf("INTRUSION: Attempt to login with non-existent username: %s\n", username);
        return;
    }
    
    if(!check_credentials(username, password)) {
        printf("INTRUSION: Attempt to login with invalid credentials for username: %s\n", username);
        return;
    }
    
    printf("SUCCESS: Login successful\n");
}

int main() {
    while(1) {
        char username[MAX_PASS_LEN];
        char password[MAX_PASS_LEN];
        
        printf("Enter username: ");
        scanf("%s", username);
        
        printf("Enter password: ");
        scanf("%s", password);
        
        detect_intrusion(username, password);
        
        printf("\n");
    }
    
    return 0;
}