//Falcon-180B DATASET v1.0 Category: Password management ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;
    numPasswords++;
}

void deletePassword() {
    int i, choice;

    printf("Enter password number to delete: ");
    scanf("%d", &choice);

    if (choice < 0 || choice >= numPasswords) {
        printf("Invalid password number.\n");
        return;
    }

    for (i = choice; i < numPasswords - 1; i++) {
        strcpy(passwords[i].password, passwords[i + 1].password);
        passwords[i].length = passwords[i + 1].length;
    }

    numPasswords--;
}

void displayPasswords() {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("%d. %s (%d characters)\n", i + 1, passwords[i].password, passwords[i].length);
    }
}

void main() {
    int choice;

    printf("Password Management System\n");
    printf("1. Add password\n");
    printf("2. Delete password\n");
    printf("3. Display passwords\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            deletePassword();
            break;
        case 3:
            displayPasswords();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}