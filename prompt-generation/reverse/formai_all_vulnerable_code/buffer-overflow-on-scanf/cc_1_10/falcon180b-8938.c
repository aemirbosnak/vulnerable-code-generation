//Falcon-180B DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(void) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void removePassword(void) {
    if (numPasswords == 0) {
        printf("Error: Password list is empty.\n");
        return;
    }

    printf("Enter name to remove: ");
    scanf("%s", passwords[numPasswords - 1].name);

    for (int i = 0; i < numPasswords - 1; i++) {
        strcpy(passwords[i].name, passwords[i + 1].name);
        strcpy(passwords[i].password, passwords[i + 1].password);
    }

    numPasswords--;
}

void viewPasswords(void) {
    if (numPasswords == 0) {
        printf("Error: Password list is empty.\n");
        return;
    }

    printf("Name\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].name, passwords[i].password);
    }
}

int main(void) {
    printf("Password Manager\n");
    printf("Commands: add, remove, view\n");

    char command[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            addPassword();
        } else if (strcmp(command, "remove") == 0) {
            removePassword();
        } else if (strcmp(command, "view") == 0) {
            viewPasswords();
        } else {
            printf("Error: Invalid command.\n");
        }
    }

    return 0;
}