//Falcon-180B DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char* username;
    char* password;
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* username, char* password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords.\n");
        return;
    }

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Error: Username already exists.\n");
            return;
        }
    }

    passwords[numPasswords].username = strdup(username);
    passwords[numPasswords].password = strdup(password);
    numPasswords++;
}

void removePassword(char* username) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            free(passwords[i].username);
            free(passwords[i].password);

            for (int j = i; j < numPasswords - 1; j++) {
                passwords[j] = passwords[j + 1];
            }

            numPasswords--;
            return;
        }
    }

    printf("Error: Username not found.\n");
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char* username = NULL;
    char* password = NULL;
    int option;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Display passwords\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
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
                removePassword(username);
                break;
            case 3:
                displayPasswords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (option!= 4);

    return 0;
}