//Falcon-180B DATASET v1.0 Category: Password management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void addPassword(Password passwords[], int numPasswords, char* name, char* password) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Password already exists for %s.\n", name);
            return;
        }
    }
    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void deletePassword(Password passwords[], int numPasswords, char* name) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memmove(&passwords[i], &passwords[i+1], sizeof(Password) * (numPasswords - i - 1));
            numPasswords--;
            return;
        }
    }
    printf("Password not found for %s.\n", name);
}

void changePassword(Password passwords[], int numPasswords, char* name, char* newPassword) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(passwords[i].password, newPassword);
            return;
        }
    }
    printf("Password not found for %s.\n", name);
}

void printPasswords(Password passwords[], int numPasswords) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while (1) {
        printf("Enter command (add, delete, change, print, or quit): ");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            char password[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter password: ");
            scanf("%s", password);
            addPassword(passwords, numPasswords, name, password);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            deletePassword(passwords, numPasswords, name);
        } else if (strcmp(command, "change") == 0) {
            char name[MAX_PASSWORD_LENGTH];
            char newPassword[MAX_PASSWORD_LENGTH];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter new password: ");
            scanf("%s", newPassword);
            changePassword(passwords, numPasswords, name, newPassword);
        } else if (strcmp(command, "print") == 0) {
            printPasswords(passwords, numPasswords);
        }
    }

    return 0;
}