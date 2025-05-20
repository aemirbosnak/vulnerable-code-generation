//GEMINI-pro DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Password database is full.\n");
        return;
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

int findPassword(char *username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void printPassword(char *username) {
    int index = findPassword(username);

    if (index == -1) {
        printf("Error: Password not found.\n");
        return;
    }

    printf("Password: %s\n", passwords[index].password);
}

int main() {
    char command;
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Password Management System\n");

    while (1) {
        printf("Enter command (A to add, F to find, P to print, Q to quit): ");
        scanf(" %c", &command);

        switch (command) {
            case 'A':
                printf("Enter username: ");
                scanf(" %s", username);

                printf("Enter password: ");
                scanf(" %s", password);

                addPassword(username, password);
                break;

            case 'F':
                printf("Enter username: ");
                scanf(" %s", username);

                int index = findPassword(username);

                if (index == -1) {
                    printf("Error: Password not found.\n");
                } else {
                    printf("Password found.\n");
                }

                break;

            case 'P':
                printf("Enter username: ");
                scanf(" %s", username);

                printPassword(username);
                break;

            case 'Q':
                printf("Exiting Password Management System.\n");
                return 0;

            default:
                printf("Invalid command.\n");
                break;
        }
    }

    return 0;
}