//FormAI DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function to execute shell command and return output */
char* executeCommand(char* command) {
    FILE* fp;
    char buffer[1024];
    char* result = "";
    
    fp = popen(command, "r");
    
    while (fgets(buffer, 1024, fp) != NULL) {
        strcat(result, buffer);
    }
    
    pclose(fp);
    
    return result;
}

/* Function to check if a user exists */
int userExists(char* username) {
    char* command;
    int result;
 
    command = (char*) malloc(strlen(username) + 16);
    sprintf(command, "id %s 2> /dev/null", username);
    
    if (strcmp(executeCommand(command), "") == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    free(command);
    
    return result;
}

/* Function to create a new user */
int createUser() {
    char* username;
    char* password;
    char* command;
    int result;
    
    printf("Enter username: ");
    scanf("%s", username);
    
    if (userExists(username)) {
        printf("User already exists.\n");
        return 1;
    }
    
    printf("Enter password: ");
    scanf("%s", password);
    
    command = (char*) malloc(strlen(username) + strlen(password) + 33);
    sprintf(command, "sudo useradd -m -p $(openssl passwd -1 %s) %s", password, username);
    
    if (system(command) != 0) {
        printf("An error occurred while creating the user.\n");
        result = 1;
    } else {
        printf("User created successfully.\n");
        result = 0;
    }
    
    free(command);
    
    return result;
}

/* Function to delete a user */
int deleteUser() {
    char* username;
    char* command;
    int result;
    
    printf("Enter username: ");
    scanf("%s", username);
    
    if (!userExists(username)) {
        printf("User does not exist.\n");
        return 1;
    }
    
    command = (char*) malloc(strlen(username) + 14);
    sprintf(command, "sudo userdel %s", username);
    
    if (system(command) != 0) {
        printf("An error occurred while deleting the user.\n");
        result = 1;
    } else {
        printf("User deleted successfully.\n");
        result = 0;
    }
    
    free(command);
    
    return result;
}

/* Function to change a user's password */
int changePassword() {
    char* username;
    char* password;
    char* command;
    int result;
    
    printf("Enter username: ");
    scanf("%s", username);
    
    if (!userExists(username)) {
        printf("User does not exist.\n");
        return 1;
    }
    
    printf("Enter new password: ");
    scanf("%s", password);
    
    command = (char*) malloc(strlen(username) + strlen(password) + 27);
    sprintf(command, "sudo passwd %s <<< %s\n", username, password);
    
    if (system(command) != 0) {
        printf("An error occurred while changing the password.\n");
        result = 1;
    } else {
        printf("Password changed successfully.\n");
        result = 0;
    }
    
    free(command);
    
    return result;
}

/* Main function */
int main() {
    int choice;
    
    do {
        printf("\n");
        printf("===== User management menu =====\n");
        printf("1. Create new user\n");
        printf("2. Delete user\n");
        printf("3. Change user password\n");
        printf("4. Exit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                deleteUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}