//Gemma-7B DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char username[20];
    char password[20];
    char admin_pass[20] = "supersecret";

    printf("Welcome to the IT Department, please enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, admin_pass) == 0) {
        printf("You are now logged in as an administrator.\n");
        printf("Please choose an action:\n");
        printf("1. Ban a user\n");
        printf("2. Add a new user\n");
        printf("3. Change system settings\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the username of the user you want to ban: ");
                scanf("%s", username);
                printf("User %s has been banned.\n", username);
                break;
            case 2:
                printf("Enter the new user's name: ");
                scanf("%s", username);
                printf("Enter the new user's password: ");
                scanf("%s", password);
                printf("New user %s has been added.\n", username);
                break;
            case 3:
                printf("Enter the new system setting: ");
                scanf("%s", password);
                printf("System setting changed to %s.\n", password);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}