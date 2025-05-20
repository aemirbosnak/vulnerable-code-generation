//GEMINI-pro DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    Password passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    // Read in the passwords from a file
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        printf("Error opening file passwords.txt\n");
        return 1;
    }

    while (fscanf(fp, "%s %s", passwords[num_passwords].username, passwords[num_passwords].password) != EOF) {
        num_passwords++;
    }

    fclose(fp);

    // Get the username and password from the user
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the username and password are valid
    int found = 0;
    for (int i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0 && strcmp(password, passwords[i].password) == 0) {
            found = 1;
            break;
        }
    }

    // Print the appropriate message
    if (found) {
        printf("Login successful\n");
    } else {
        printf("Login failed\n");
    }

    return 0;
}