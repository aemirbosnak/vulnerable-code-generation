//FormAI DATASET v1.0 Category: Password management ; Style: relaxed
#include<stdio.h>
#include<string.h>

// Constants for maximum length of username and password
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 20

// Constant for maximum number of users that can be stored
#define MAX_USERS 5

// Function to encrypt the password
void encrypt_password(char *password)
{
    for(int i = 0; i < strlen(password); i++)
    {
        password[i] = password[i] + 3;
    }
}

// Function to decrypt the password
void decrypt_password(char *password)
{
    for(int i = 0; i < strlen(password); i++)
    {
        password[i] = password[i] - 3;
    }
}

// User struct that stores the username and encrypted password
struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Array of users
struct user users[MAX_USERS];

// Function to add a user
void add_user()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    encrypt_password(password);
    
    for(int i = 0; i < MAX_USERS; i++)
    {
        if(users[i].username[0] == '\0')
        {
            strcpy(users[i].username, username);
            strcpy(users[i].password, password);
            printf("User added successfully!\n");
            return;
        }
    }
    
    printf("Cannot add user. Maximum number of users reached.\n");
}

// Function to authenticate the user
int authenticate_user()
{
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("Enter username: ");
    scanf("%s", username);
    
    printf("Enter password: ");
    scanf("%s", password);
    
    encrypt_password(password);
    
    for(int i = 0; i < MAX_USERS; i++)
    {
        if(strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0)
        {
            printf("Authentication successful!\n");
            return 1;
        }
    }
    
    printf("Authentication failed!\n");
    return 0;
}

// Main function 
int main()
{
    int choice = 0;
    
    while(1)
    {
        printf("1. Add user\n");
        printf("2. Authenticate user\n");
        printf("3. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                add_user();
                break;
                
            case 2:
                authenticate_user();
                break;
                
            case 3:
                printf("Exiting program.\n");
                return 0;
                
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    
    return 0;
}