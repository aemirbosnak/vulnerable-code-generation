//FormAI DATASET v1.0 Category: Password management ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 25

// Struct to store the user information
struct User {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
};

// Function to prompt the user to enter a new password
void enterNewPassword(struct User *user){
    char password[MAX_PASSWORD_LENGTH];
    printf("\nEnter a new password for %s: ", user->username);
    scanf("%s", password);
    strcpy(user->password, password);
    printf("Password successfully updated!\n");
}

// Function to validate the entered password
int validatePassword(struct User *user, char *enteredPassword){
    if(strcmp(user->password, enteredPassword) == 0){
        return 1; // Correct password
    }
    else{
        return 0; // Incorrect password
    }
}

int main(){
    // Initialize the user struct with a default password
    struct User myUser = {"John", "mypassword123"};
    
    // Prompt the user to enter their username
    char username[50];
    printf("Please enter your username: ");
    scanf("%s", username);
    
    // If the entered username matches the stored username, prompt for the password
    if(strcmp(username, myUser.username) == 0){
        char enteredPassword[MAX_PASSWORD_LENGTH];
        printf("Please enter your password: ");
        scanf("%s", enteredPassword);
        
        // Validate the entered password
        if(validatePassword(&myUser, enteredPassword)){
            printf("\nWelcome back, %s!\n", myUser.username);
        }
        else{
            printf("\nIncorrect password!\n");
        }
        
        // Prompt the user if they want to change their password
        char response;
        printf("Would you like to change your password? (y/n) ");
        scanf(" %c", &response); // Note the space before %c to ignore whitespace
        
        if(response == 'y' || response == 'Y'){
            enterNewPassword(&myUser);
        }
    }
    else{
        printf("\nInvalid username!\n");
    }
    
    return 0;
}