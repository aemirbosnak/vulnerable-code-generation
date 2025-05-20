//GEMINI-pro DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100

typedef struct {
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
} password_t;

int main() {
    // Initialize an array of passwords
    password_t passwords[MAX_PASSWORDS];
    int num_passwords = 0;

    // Load passwords from a file
    FILE *fp = fopen("passwords.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening passwords.txt\n");
        return 1;
    }
    while (fscanf(fp, "%s %s\n", passwords[num_passwords].username, passwords[num_passwords].password) != EOF) {
        num_passwords++;
    }
    fclose(fp);

    // Get the username and password from the user
    char username[MAX_PASSWORD_LEN];
    char password[MAX_PASSWORD_LEN];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Find the password for the given username
    int i;
    for (i = 0; i < num_passwords; i++) {
        if (strcmp(username, passwords[i].username) == 0) {
            break;
        }
    }

    // Check if the password is correct
    if (i == num_passwords) {
        printf("Invalid username or password\n");
        return 1;
    }
    if (strcmp(password, passwords[i].password) != 0) {
        printf("Invalid password\n");
        return 1;
    }

    // Print the password
    printf("Your password is: %s\n", passwords[i].password);

    return 0;
}