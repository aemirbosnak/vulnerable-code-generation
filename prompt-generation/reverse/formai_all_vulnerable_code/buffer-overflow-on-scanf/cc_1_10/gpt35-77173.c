//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
 
#define MAX_NAME_LEN 50 
#define MAX_EMAIL_LEN 100 
#define MAX_ADDRESS_LEN 200
#define MAX_PHONE_LEN 20
#define MAX_USERS 10 

// Structures
typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
} user;

// Function prototypes
bool login(char *username, char *password);
int getUserIndex(char *username);
void displayUserData(int index);
void displayAllUsersData();

// Global variables
user users[MAX_USERS] = {
    {"John Doe", "john.doe@email.com", "123 Main St", "555-1234"},
    {"Jane Smith", "jane.smith@email.com", "456 Oak Ave", "555-5678"}
};
int numUsers = 2;

int main() {
    char username[MAX_NAME_LEN];
    char password[MAX_NAME_LEN];

    // Prompt user for login credentials
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Verify login credentials
    if (login(username, password)) {
        // If login successful, prompt user for action
        int index = getUserIndex(username);
        char action;
        do {
            printf("Welcome, %s!\n", users[index].name);
            printf("Choose an action:\n");
            printf("1. View my profile\n");
            printf("2. View all users\n");
            printf("3. Logout\n");
            scanf(" %c", &action);
            switch (action) {
                case '1':
                    displayUserData(index);
                    break;
                case '2':
                    displayAllUsersData();
                    break;
                case '3':
                    printf("Logging out...\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        } while (action != '3');
    }
    else {
        // If login unsuccessful, display error message
        printf("Invalid username or password.\n");
    }

    return 0;
}

bool login(char *username, char *password) {
    // Verify username and password by checking if they match
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].name, username) == 0 && strcmp(users[i].phone, password) == 0) {
            return true;
        }
    }
    return false;
}

int getUserIndex(char *username) {
    // Find index of user from their username
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].name, username) == 0) {
            return i;
        }
    }
    return -1;
}

void displayUserData(int index) {
    // Display data of specific user
    printf("Name: %s\n", users[index].name);
    printf("Email: %s\n", users[index].email);
    printf("Address: %s\n", users[index].address);
    printf("Phone: %s\n", users[index].phone);
}

void displayAllUsersData() {
    // Display data of all users
    for (int i = 0; i < numUsers; i++) {
        printf("Name: %s\n", users[i].name);
        printf("Email: %s\n", users[i].email);
        printf("Address: %s\n", users[i].address);
        printf("Phone: %s\n\n", users[i].phone);
    }
}