//Falcon-180B DATASET v1.0 Category: Password management ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_LENGTH 64

typedef struct {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    char username[MAX_LENGTH];
    printf("Enter username: ");
    scanf("%s", username);

    char password[MAX_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
    printf("Password added successfully.\n");
}

void removePassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    char username[MAX_LENGTH];
    printf("Enter username to remove: ");
    scanf("%s", username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(passwords[i].password, 0, MAX_LENGTH);
            printf("Password removed successfully.\n");
            return;
        }
    }

    printf("Error: Username not found.\n");
}

void listPasswords() {
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
    char choice;

    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. List passwords\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                addPassword();
                break;
            case '2':
                removePassword();
                break;
            case '3':
                listPasswords();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}