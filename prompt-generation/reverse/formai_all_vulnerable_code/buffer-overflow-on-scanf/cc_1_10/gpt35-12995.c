//FormAI DATASET v1.0 Category: System administration ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length for the username */
#define MAX_USERNAME_LENGTH 20

/* Define the maximum length for the password */
#define MAX_PASSWORD_LENGTH 20

/* Define the maximum length for the user's home directory */
#define MAX_HOME_DIRECTORY_LENGTH 100

/* Define the maximum number of users that can be added */
#define MAX_USERS 10

/* Define the user struct */
struct user {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char home_directory[MAX_HOME_DIRECTORY_LENGTH];
};

/* Define the array of users */
struct user users[MAX_USERS];

/* Define the current number of users */
int num_users = 0;

/**
 * Prints the list of current users.
 */
void print_users() {
    if (num_users == 0) {
        printf("There are no users.\n");
    } else {
        printf("Users:\n");
        for (int i = 0; i < num_users; i++) {
            printf("%s\t%s\t%s\n", users[i].username, users[i].password, users[i].home_directory);
        }
    }
}

/**
 * Adds a new user to the list.
 */
void add_user() {
    struct user new_user;
    char input[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + MAX_HOME_DIRECTORY_LENGTH + 10];

    /* Get the username */
    printf("Enter the username: ");
    fgets(input, MAX_USERNAME_LENGTH, stdin);
    strtok(input, "\n"); /* Remove the newline character */
    strcpy(new_user.username, input);

    /* Get the password */
    printf("Enter the password: ");
    fgets(input, MAX_PASSWORD_LENGTH, stdin);
    strtok(input, "\n"); /* Remove the newline character */
    strcpy(new_user.password, input);

    /* Get the home directory */
    printf("Enter the home directory: ");
    fgets(input, MAX_HOME_DIRECTORY_LENGTH, stdin);
    strtok(input, "\n"); /* Remove the newline character */
    strcpy(new_user.home_directory, input);

    /* Add the user to the list */
    users[num_users++] = new_user;

    printf("User added successfully.\n");
}

int main() {
    int choice;

    do {
        /* Print the menu */
        printf("\n1. View users\n");
        printf("2. Add user\n");
        printf("3. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); /* Remove the newline character */

        /* Perform the selected action */
        switch (choice) {
            case 1:
                print_users();
                break;
            case 2:
                add_user();
                break;
            case 3:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}