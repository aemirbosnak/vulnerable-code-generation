//Falcon-180B DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char *username;
    char *password;
};

int main() {
    FILE *file;
    struct Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;
    char line[MAX_PASSWORD_LENGTH];

    // Open the password file
    file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("Error: could not open password file.\n");
        return 1;
    }

    // Read each line from the password file
    while (fgets(line, MAX_PASSWORD_LENGTH, file)!= NULL) {
        // Remove the newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';

        // Split the line into username and password
        char *username = strtok(line, ":");
        char *password = strtok(NULL, ":");

        // Add the password to the array
        if (num_passwords < MAX_PASSWORDS) {
            passwords[num_passwords].username = strdup(username);
            passwords[num_passwords].password = strdup(password);
            num_passwords++;
        } else {
            printf("Error: too many passwords in file.\n");
        }
    }

    // Close the password file
    fclose(file);

    // Print the list of passwords
    printf("Passwords:\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }

    // Prompt the user to enter a username
    printf("Enter a username:\n");
    char *username_input = fgets(line, MAX_PASSWORD_LENGTH, stdin);

    // Remove the newline character from the end of the input
    line[strcspn(line, "\n")] = '\0';

    // Search for the password associated with the username
    int password_index = -1;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username_input) == 0) {
            password_index = i;
            break;
        }
    }

    // If the password was found, print it
    if (password_index!= -1) {
        printf("Password for %s: %s\n", username_input, passwords[password_index].password);
    } else {
        printf("Password not found.\n");
    }

    // Free the memory allocated for the passwords
    for (int i = 0; i < num_passwords; i++) {
        free(passwords[i].username);
        free(passwords[i].password);
    }

    return 0;
}