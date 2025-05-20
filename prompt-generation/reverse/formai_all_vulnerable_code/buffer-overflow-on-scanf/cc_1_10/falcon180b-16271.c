//Falcon-180B DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(Password* password) {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int length = strlen(chars);
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = chars[rand() % length];
    }
    password->password[MAX_PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while (1) {
        printf("Enter a command (add, delete, list, exit): ");
        char command[MAX_PASSWORD_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter a username: ");
            scanf("%s", passwords[numPasswords].username);
            generatePassword(&passwords[numPasswords]);
            numPasswords++;
            printf("Password added successfully.\n");
        } else if (strcmp(command, "delete") == 0) {
            printf("Enter a username: ");
            scanf("%s", passwords[numPasswords - 1].username);
            numPasswords--;
            printf("Password deleted successfully.\n");
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < numPasswords; i++) {
                printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}