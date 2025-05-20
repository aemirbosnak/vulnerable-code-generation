//GEMINI-pro DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *name, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Password limit reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void printPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter command (add, print, quit): ");
        char command[MAX_PASSWORD_LENGTH];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter password: ");
            scanf("%s", password);

            addPassword(name, password);
        } else if (strcmp(command, "print") == 0) {
            printPasswords();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}