//FormAI DATASET v1.0 Category: System administration ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Welcome to my AWESOME system administration program!
// This program will help you keep track of your user accounts on your system.

struct user {
    char username[10];
    char password[10];
};

int main() {

    // Let's start by defining our array of users
    // We'll have a maximum of 10 users for now.
    struct user users[10];

    // We'll also define some variables for user input.
    char input[10];
    char username[10];
    char password[10];

    // Now let's add some users to our system.
    // We'll ask the user to input a username and password for each user.
    printf("Let's add some users!\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter a username for user %d: ", i+1);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", username);
        printf("Enter a password for user %d: ", i+1);
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", password);
        strcpy(users[i].username, username);
        strcpy(users[i].password, password);
    }

    // Now let's ask the user which user they would like to modify.
    printf("\nWhich user would you like to modify?\n");
    for (int i = 0; i < 10; i++) {
        printf("%d: %s\n", i+1, users[i].username);
    }
    fgets(input, sizeof(input), stdin);
    int index = atoi(input) - 1;

    // Let's ask the user if they want to change the username or password.
    printf("\nWhat would you like to modify?\n");
    printf("1: Username\n");
    printf("2: Password\n");
    fgets(input, sizeof(input), stdin);
    int choice = atoi(input);

    // Now let's ask the user for the new username or password.
    printf("\nEnter the new ");
    if (choice == 1) {
        printf("username: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", username);
        strcpy(users[index].username, username);
    }
    else if (choice == 2) {
        printf("password: ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", password);
        strcpy(users[index].password, password);
    }
    else {
        printf("Invalid choice.");
        exit(1);
    }

    // Let's print out the updated user accounts.
    printf("\nUpdated user accounts:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s:%s\n", users[i].username, users[i].password);
    }

    // Thank you for using my AWESOME system administration program!
    return 0;
}