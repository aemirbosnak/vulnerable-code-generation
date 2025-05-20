//Falcon-180B DATASET v1.0 Category: Password management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    int index;
    printf("Enter index of password to delete: ");
    scanf("%d", &index);

    if (index >= numPasswords) {
        printf("Error: Invalid index.\n");
        return;
    }

    numPasswords--;
    for (int i = index; i < numPasswords; i++) {
        strcpy(passwords[i].username, passwords[i+1].username);
        strcpy(passwords[i].password, passwords[i+1].password);
    }
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("Password Manager\n");

    while (1) {
        printf("\n1. Add password\n2. Delete password\n3. Display passwords\n4. Exit\n");
        int choice;
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

    return 0;
}