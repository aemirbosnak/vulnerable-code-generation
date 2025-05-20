//FormAI DATASET v1.0 Category: Password management ; Style: statistical
// Statistical Style C Password Management Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PASS_LENGTH 20
#define MAX_USERS 500

// Structure to hold user information
struct user {
    char username[MAX_PASS_LENGTH]; // username/identifier
    char password[MAX_PASS_LENGTH]; // password
    int numLogins; // number of successful logins
};

// Function prototypes
void mainMenu();
int addUser(struct user[], int, char[], char[]);
int findUser(struct user[], int, char[]);
int checkLogin(struct user[], int, char[], char[]);
void displayUsers(struct user[], int);

int main() {
    struct user users[MAX_USERS]; // array to hold user information
    int numUsers = 0; // counter for number of users in array
    int choice = 0; // user's menu selection
    char username[MAX_PASS_LENGTH], password[MAX_PASS_LENGTH]; // temporary strings for username and password input

    // Display welcome message and main menu
    printf("\nWelcome to the Password Management Program\n"); 
    mainMenu();
    scanf("%d", &choice);

    while(choice != 4) { // continue program until user selects option 4 (exit)
        switch(choice) {
            case 1: // Add user
                printf("\nEnter a username (maximum %d characters): ", MAX_PASS_LENGTH-1);
                scanf("%s", username);
                printf("Enter a password (maximum %d characters): ", MAX_PASS_LENGTH-1);
                scanf("%s", password);
                if(addUser(users, numUsers, username, password) == 0) { // check if user already exists
                    printf("\nUser %s added successfully.\n", username);
                    numUsers++; // increment user count
                }
                else {
                    printf("\nUser %s already exists. Please choose a different username.\n", username);
                }
                break;
            case 2: // Login
                printf("\nEnter your username: ");
                scanf("%s", username);
                printf("Enter your password: ");
                scanf("%s", password);
                if(checkLogin(users, numUsers, username, password) == 1) { // check if login is successful
                    printf("\nLogin successful. Welcome, %s!\n", username);
                    for(int i=0; i<numUsers; i++) { // increment user's number of logins
                        if(strcmp(users[i].username, username) == 0) {
                            users[i].numLogins++;
                        }
                    }
                }
                else {
                    printf("\nIncorrect username or password. Please try again.\n");
                }
                break;
            case 3: // Display users
                displayUsers(users, numUsers);
                break;
            default: // Invalid selection
                printf("\nInvalid selection. Please try again.\n");
        }
        mainMenu(); // display main menu
        scanf("%d", &choice); // get user's choice
    }
    printf("\nThank you for using the Password Management Program. Goodbye!\n");
    return 0; // exit program
}

void mainMenu() {
    printf("\nMain Menu - Please choose an option:\n");
    printf("1. Add user\n");
    printf("2. Login\n");
    printf("3. Display users\n");
    printf("4. Exit\n");
}

int addUser(struct user users[], int numUsers, char username[], char password[]) {
    for(int i=0; i<numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) { // check if user already exists
            return 1;
        }
    }
    strcpy(users[numUsers].username, username); // add user to array
    strcpy(users[numUsers].password, password);
    users[numUsers].numLogins = 0;
    return 0;
}

int findUser(struct user users[], int numUsers, char username[]) {
    for(int i=0; i<numUsers; i++) {
        if(strcmp(users[i].username, username) == 0) { // check if user exists in array
            return i;
        }
    }
    return -1;
}

int checkLogin(struct user users[], int numUsers, char username[], char password[]) {
    int index = findUser(users, numUsers, username); // find user's index in array
    if(index != -1 && strcmp(users[index].password, password) == 0) { // check if username and password match
        return 1;
    }
    return 0;
}

void displayUsers(struct user users[], int numUsers) {
    printf("\nUsers:\n");
    printf("%-20s%-20s%s\n", "Username", "Password", "Logins");
    printf("--------------------------------------------------\n");
    for(int i=0; i<numUsers; i++) { // loop through all users in array
        printf("%-20s%-20s%d\n", users[i].username, users[i].password, users[i].numLogins);
    }
}