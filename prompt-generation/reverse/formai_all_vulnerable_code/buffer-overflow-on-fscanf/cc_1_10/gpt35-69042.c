//FormAI DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USR_LENGTH 16 // Maximum length of user names
#define MAX_PASS_LENGTH 16 // Maximum length of passwords

int main() {
    char username[MAX_USR_LENGTH]; // Usernames of system users
    char password[MAX_PASS_LENGTH]; // Passwords of system users
    char input_username[MAX_USR_LENGTH]; // User specified username
    char input_password[MAX_PASS_LENGTH]; // User specified password
    int system_users = 0; // Number of system users
    int i; // Loop variable

    // Read the system's user data
    FILE* usr_info = fopen("user_data.txt", "r");
    if(usr_info == NULL) {
        printf("Error opening user data file.\n");
        return 1;
    }

    while(fscanf(usr_info, "%s %s", username, password) != EOF) {
        system_users++;
    }

    fclose(usr_info);

    // Start the authentication process
    while(1) {
        printf("System Login:\n");
        printf("Username: ");
        scanf("%s", input_username);

        printf("Password: ");
        scanf("%s", input_password);

        // Check if user is in the system
        usr_info = fopen("user_data.txt", "r");

        for(i = 0; i < system_users; i++) {
            fscanf(usr_info, "%s %s", username, password);
            if(strcmp(input_username, username) == 0 && strcmp(input_password, password) == 0) {
                printf("Welcome, %s.\n", username);
                fclose(usr_info);
                return 0;
            }
        }

        fclose(usr_info);
        printf("Username or password is incorrect. Please try again.\n");
    }

    return 0;
}