//FormAI DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_PASSWORD_LENGTH 20

// Structure to hold user credentials
struct userDetails {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

// Function to validate user input
int validateInput(char input[]) {
    if (strlen(input) < 6 || strlen(input) > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    return 1;
}

int main() {
    struct userDetails users[MAX_USERS];
    int userCount = 0;

    printf("Welcome to Happy Password Manager!\n");

    while (1) {
        int choice;

        // Display menu of options
        printf("\n1. Create a new user\n");
        printf("2. Sign in\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                if (userCount == MAX_USERS) {
                    printf("\nCannot create new user. Maximum user limit reached.\n");
                    break;
                }
                // Prompt user to input username
                printf("\nEnter username (must be at least 6 characters long and less than 20 characters): ");
                scanf("%s", users[userCount].username);

                // Prompt user to input password
                printf("Enter password (must be at least 6 characters long and less than 20 characters): ");
                scanf("%s", users[userCount].password);

                if (validateInput(users[userCount].password) && validateInput(users[userCount].username)) {
                    printf("\nUser created successfully!\n");
                    userCount++;
                } else {
                    printf("\nInvalid username or password entered. Please try again.\n");
                }

                break;
            }
            case 2: {
                // Prompt user to input username and password
                char username[MAX_PASSWORD_LENGTH], password[MAX_PASSWORD_LENGTH];
                printf("\nEnter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);

                // Check if user exists and if the input password matches the stored password
                for (int i=0; i<userCount; i++) {
                    if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                        printf("\nWelcome back %s!\n", username);
                        break;
                    } else if (i == userCount-1) {
                        printf("\nIncorrect username or password entered. Please try again.\n");
                    }
                }

                break;
            }
            case 3: {
                // Exit program
                printf("\nThank you for using Happy Password Manager. Goodbye!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice entered. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}