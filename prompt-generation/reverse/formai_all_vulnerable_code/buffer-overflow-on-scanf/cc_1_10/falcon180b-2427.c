//Falcon-180B DATASET v1.0 Category: Password management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

struct Password {
    char name[20];
    char password[PASSWORD_LENGTH];
};

void addPassword(struct Password *passwords, int numPasswords, char *name, char *password) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Error: Password already exists.\n");
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
            strcpy(passwords[i].name, "");
            strcpy(passwords[i].password, "");
            numPasswords--;
            return;
        }
    }
    printf("Error: Password not found.\n");
}

void changePassword(struct Password *passwords, int numPasswords, char *name, char *newPassword) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            strcpy(passwords[i].password, newPassword);
            return;
        }
    }
    printf("Error: Password not found.\n");
}

void displayPasswords(struct Password *passwords, int numPasswords) {
    printf("Passwords:\n");
    printf("Name\tPassword\n");
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (passwords[i].name[0]!= '\0') {
            printf("%s\t%s\n", passwords[i].name, passwords[i].password);
        }
    }
}

int main() {
    struct Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char choice;
    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Change password\n");
        printf("4. Display passwords\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter name of password: ");
                char name[20];
                scanf("%s", name);
                printf("Enter password: ");
                char password[PASSWORD_LENGTH];
                scanf("%s", password);
                addPassword(passwords, numPasswords, name, password);
                break;
            case '2':
                printf("Enter name of password to delete: ");
                char delName[20];
                scanf("%s", delName);
                deletePassword(passwords, numPasswords, delName);
                break;
            case '3':
                printf("Enter name of password to change: ");
                char changeName[20];
                scanf("%s", changeName);
                printf("Enter new password: ");
                char newPassword[PASSWORD_LENGTH];
                scanf("%s", newPassword);
                changePassword(passwords, numPasswords, changeName, newPassword);
                break;
            case '4':
                displayPasswords(passwords, numPasswords);
                break;
            case '5':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '5');

    return 0;
}