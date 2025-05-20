//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    printf("Enter name for new password: ");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void viewPasswords() {
    printf("Name\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].name, passwords[i].password);
    }
}

void searchPassword() {
    printf("Enter name to search: ");
    char name[MAX_PASSWORD_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(name, passwords[i].name) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

void deletePassword() {
    printf("Enter name of password to delete: ");
    char name[MAX_PASSWORD_LENGTH];
    scanf("%s", name);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(name, passwords[i].name) == 0) {
            strcpy(passwords[i].name, "");
            strcpy(passwords[i].password, "");
            numPasswords--;
            printf("Password deleted.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

int main() {
    printf("Password Manager\n");

    while (1) {
        printf("\n1. Add Password\n2. View Passwords\n3. Search Password\n4. Delete Password\n5. Exit\n");
        int choice;
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
                deletePassword();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}