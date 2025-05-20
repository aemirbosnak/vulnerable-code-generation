//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int nameLength, passwordLength;

    printf("Enter the name of the website or service: ");
    scanf("%s", name);
    nameLength = strlen(name);

    printf("Enter the password: ");
    scanf("%s", password);
    passwordLength = strlen(password);

    if (nameLength > MAX_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH) {
        printf("Error: Name or password is too long.\n");
        return;
    }

    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;

    printf("Password added successfully!\n");
}

void viewPasswords() {
    int i;

    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Passwords:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].password);
    }
}

void searchPassword() {
    char name[MAX_PASSWORD_LENGTH];
    int i;

    printf("Enter the name of the website or service: ");
    scanf("%s", name);

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(name, passwords[i].name) == 0) {
            printf("Password found: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    int choice;

    printf("Welcome to the Password Manager!\n");
    printf("1. Add password\n");
    printf("2. View passwords\n");
    printf("3. Search password\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            viewPasswords();
            break;
        case 3:
            searchPassword();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}