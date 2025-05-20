//Falcon-180B DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 32

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void addPassword(struct Password *passwords, int numPasswords, char *name, char *password) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Password already exists.\n");
            return;
        }
    }
    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;
}

void deletePassword(struct Password *passwords, int numPasswords, char *name) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memmove(&passwords[i], &passwords[i+1], (numPasswords - i - 1) * sizeof(struct Password));
            numPasswords--;
            return;
        }
    }
    printf("Password not found.\n");
}

void changePassword(struct Password *passwords, int numPasswords, char *name, char *newPassword) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(passwords[i].password, newPassword);
            return;
        }
    }
    printf("Password not found.\n");
}

void displayPasswords(struct Password *passwords, int numPasswords) {
    printf("Passwords:\n");
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        printf("1. Add Password\n2. Delete Password\n3. Change Password\n4. Display Passwords\n5. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", password);
                addPassword(passwords, numPasswords, name, password);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                deletePassword(passwords, numPasswords, name);
                break;
            case 3:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter new password: ");
                scanf("%s", password);
                changePassword(passwords, numPasswords, name, password);
                break;
            case 4:
                displayPasswords(passwords, numPasswords);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}