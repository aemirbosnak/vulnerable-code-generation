//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10 // maximum number of passwords that can be stored
#define PASSWORD_LENGTH 20 // maximum length of each password

char usernames[MAX_PASSWORDS][PASSWORD_LENGTH]; // store usernames
char passwords[MAX_PASSWORDS][PASSWORD_LENGTH]; // store passwords

int current_user = 0; // index of the current user

void add_password(); // function to add a new password
void view_passwords(); // function to view all saved passwords
void search_password(); // function to search for a password by username
void delete_password(); // function to delete a password by username

int main() {
    int choice;
    char password[PASSWORD_LENGTH];
    
    // prompt the user to enter password to access the password manager
    printf("Enter password to access password manager:\n");
    scanf("%s", password);
    
    // check if the password is correct
    if (strcmp(password, "mypassword") != 0) {
        printf("Incorrect password. Exiting program.\n");
        exit(1);
    }
    
    printf("Welcome to the Password Manager!\n");
    
    // main menu loop
    while (1) {
        printf("Enter an option:\n");
        printf("1. Add a new password\n");
        printf("2. View all saved passwords\n");
        printf("3. Search for a password by username\n");
        printf("4. Delete a password by username\n");
        printf("5. Quit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_password();
                break;
            case 2:
                view_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                delete_password();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    
    return 0;
}

void add_password() {
    char username[PASSWORD_LENGTH];
    char password[PASSWORD_LENGTH];
    
    if (current_user >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached. Cannot add more.\n");
        return;
    }
    
    printf("Enter username:\n");
    scanf("%s", username);
    
    // check if the username already exists
    for (int i = 0; i < current_user; i++) {
        if (strcmp(usernames[i], username) == 0) {
            printf("Username already exists. Try again.\n");
            return;
        }
    }
    
    printf("Enter password:\n");
    scanf("%s", password);
    
    // add the new password
    strcpy(usernames[current_user], username);
    strcpy(passwords[current_user], password);
    current_user++;
    
    printf("Password added successfully.\n");
}

void view_passwords() {
    if (current_user == 0) {
        printf("No passwords saved.\n");
        return;
    }
    
    printf("All saved passwords:\n");
    for (int i = 0; i < current_user; i++) {
        printf("%s: %s\n", usernames[i], passwords[i]);
    }
}

void search_password() {
    char username[PASSWORD_LENGTH];
    
    if (current_user == 0) {
        printf("No passwords saved.\n");
        return;
    }
    
    printf("Enter username to search for:\n");
    scanf("%s", username);
    
    // search for the username
    for (int i = 0; i < current_user; i++) {
        if (strcmp(usernames[i], username) == 0) {
            printf("%s: %s\n", usernames[i], passwords[i]);
            return;
        }
    }
    
    printf("Username not found.\n");
}

void delete_password() {
    char username[PASSWORD_LENGTH];
    
    if (current_user == 0) {
        printf("No passwords saved.\n");
        return;
    }
    
    printf("Enter username to delete:\n");
    scanf("%s", username);
    
    // search for the username
    for (int i = 0; i < current_user; i++) {
        if (strcmp(usernames[i], username) == 0) {
            // shift all elements to the left to remove the deleted password
            for (int j = i; j < current_user-1; j++) {
                strcpy(usernames[j], usernames[j+1]);
                strcpy(passwords[j], passwords[j+1]);
            }
            current_user--;
            printf("Password deleted successfully.\n");
            return;
        }
    }
    
    printf("Username not found.\n");
}