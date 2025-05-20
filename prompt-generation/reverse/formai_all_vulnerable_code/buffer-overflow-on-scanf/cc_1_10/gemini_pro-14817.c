//GEMINI-pro DATASET v1.0 Category: Password management ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct password {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} password;

password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Too many passwords stored.\n");
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

    for (i = i + 1; i < numPasswords; i++) {
        strcpy(passwords[i - 1].username, passwords[i].username);
        strcpy(passwords[i - 1].password, passwords[i].password);
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
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int choice;

    while (1) {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Print passwords\n");
        printf("4. Quit\n");
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
                printPasswords();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}