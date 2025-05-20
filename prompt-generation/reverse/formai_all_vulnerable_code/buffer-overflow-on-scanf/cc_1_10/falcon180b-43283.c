//Falcon-180B DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char* username;
    char* password;
} Password;

Password* passwords = NULL;
int numPasswords = 0;

void addPassword(char* username, char* password) {
    Password* newPassword = malloc(sizeof(Password));
    if (newPassword == NULL) {
        printf("Error: Could not allocate memory for new password.\n");
        return;
    }
    newPassword->username = strdup(username);
    newPassword->password = strdup(password);
    passwords = realloc(passwords, sizeof(Password) * ++numPasswords);
    passwords[numPasswords - 1] = *newPassword;
    free(newPassword);
}

void deletePassword(char* username) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);
            passwords = realloc(passwords, sizeof(Password) * --numPasswords);
            break;
        }
    }
}

void changePassword(char* oldUsername, char* newUsername, char* newPassword) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, oldUsername) == 0) {
            free(passwords[i].username);
            passwords[i].username = strdup(newUsername);
            free(passwords[i].password);
            passwords[i].password = strdup(newPassword);
            break;
        }
    }
}

void printPasswords() {
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char* username = NULL;
    char* password = NULL;
    char* newUsername = NULL;
    char* newPassword = NULL;
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Change password\n");
        printf("4. Print passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(username, password);
            break;
        case 2:
            printf("Enter username: ");
            scanf("%s", username);
            deletePassword(username);
            break;
        case 3:
            printf("Enter old username: ");
            scanf("%s", username);
            printf("Enter new username: ");
            scanf("%s", newUsername);
            printf("Enter new password: ");
            scanf("%s", newPassword);
            changePassword(username, newUsername, newPassword);
            break;
        case 4:
            printPasswords();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}