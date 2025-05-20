//Gemma-7B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct {
    char *name;
    char *password;
} user_data;

user_data users[MAX_PASSWORDS];

int main() {
    int i = 0;
    char command[20];

    system("clear");

    // Create users and passwords
    users[0].name = "John Doe";
    users[0].password = "Secret123";
    users[1].name = "Jane Doe";
    users[1].password = "StrongPswd";

    // Display the list of users
    printf("List of users:\n");
    for (i = 0; i < MAX_PASSWORDS; i++) {
        if (users[i].name) {
            printf("%s\n", users[i].name);
        }
    }

    // Get the user command
    printf("Enter a command: ");
    scanf("%s", command);

    // Check if the command is to retrieve a password
    if (strcmp(command, "retrieve password") == 0) {
        // Get the user's name
        char username[20];
        printf("Enter your username: ");
        scanf("%s", username);

        // Search for the user and check if the password is correct
        for (i = 0; i < MAX_PASSWORDS; i++) {
            if (strcmp(username, users[i].name) == 0) {
                if (strcmp(users[i].password, command) == 0) {
                    printf("Your password is: %s\n", users[i].password);
                } else {
                    printf("Error: Invalid password.\n");
                }
            }
        }
    } else {
        printf("Error: Invalid command.\n");
    }

    return 0;
}