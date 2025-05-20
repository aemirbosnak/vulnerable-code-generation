//GEMINI-pro DATASET v1.0 Category: Password management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        return;
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void deletePassword(char *username) {
    int i;

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            break;
        }
    }

    if (i == numPasswords) {
        printf("Error: Password not found.\n");
        return;
    }

    for (; i < numPasswords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    numPasswords--;
}

void printPasswords() {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char input[100];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter command (add, delete, print, quit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(username, password);
        } else if (strcmp(input, "delete") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            deletePassword(username);
        } else if (strcmp(input, "print") == 0) {
            printPasswords();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}