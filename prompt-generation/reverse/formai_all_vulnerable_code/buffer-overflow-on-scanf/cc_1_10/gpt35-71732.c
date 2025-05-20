//FormAI DATASET v1.0 Category: Password management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Function declarations
bool login(char* username, char* password);
void register_user();
void change_password(char* username);
void list_users();

//Struct to store username and password
struct user {
    char* username;
    char* password;
};

//Global variables
int num_users = 0; //Number of registered users
struct user** user_table = NULL; //Table of registered users

int main() {
    printf("Welcome to the Password Management System\n");
    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Change Password\n");
        printf("4. List Users\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                //Login
                {
                    char username[20], password[20];
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    scanf("%s", password);
                    if (login(username, password)) {
                        printf("Login successful!\n");
                    }
                    else {
                        printf("Invalid username or password.\n");
                    }
                }
                break;
            case '2':
                //Register
                register_user();
                break;
            case '3':
                //Change Password
                {
                    char username[20];
                    printf("Username: ");
                    scanf("%s", username);
                    change_password(username);
                }
                break;
            case '4':
                //List Users
                list_users();
                break;
            case '5':
                //Exit
                printf("Goodbye!\n");
                break;
            default:
                //Invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != '5');
    
    //Free memory
    for (int i = 0; i < num_users; i++) {
        free(user_table[i]->username);
        free(user_table[i]->password);
        free(user_table[i]);
    }
    free(user_table);
    
    return 0;
}

bool login(char* username, char* password) {
    //Search for user in user table
    for (int i = 0; i < num_users; i++) {
        if (strcmp(user_table[i]->username, username) == 0) {
            //User exists, check password
            if (strcmp(user_table[i]->password, password) == 0) {
                //Password is correct
                return true;
            }
            else {
                //Password is incorrect
                return false;
            }
        }
    }
    //User does not exist
    return false;
}

void register_user() {
    //Allocate memory for new user
    struct user* new_user = (struct user*) malloc(sizeof(struct user));
    new_user->username = (char*) malloc(20 * sizeof(char));
    new_user->password = (char*) malloc(20 * sizeof(char));
    
    //Get username and password from user
    printf("Username: ");
    scanf("%s", new_user->username);
    printf("Password: ");
    scanf("%s", new_user->password);
    
    //Add new user to user table
    num_users++;
    user_table = (struct user**) realloc(user_table, num_users * sizeof(struct user*));
    user_table[num_users - 1] = new_user;
    
    printf("Registration successful!\n");
}

void change_password(char* username) {
    //Search for user in user table
    for (int i = 0; i < num_users; i++) {
        if (strcmp(user_table[i]->username, username) == 0) {
            //User exists, get new password from user
            printf("Enter new password: ");
            scanf("%s", user_table[i]->password);
            printf("Password changed successfully!\n");
            return;
        }
    }
    //User does not exist
    printf("Invalid username.\n");
}

void list_users() {
    //Print list of registered users
    printf("Registered users:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s\n", user_table[i]->username);
    }
}