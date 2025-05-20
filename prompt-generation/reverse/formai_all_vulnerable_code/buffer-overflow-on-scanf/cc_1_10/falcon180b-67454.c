//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password name: ");
    scanf("%s", name);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void editPassword() {
    int index;
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password name to edit: ");
    scanf("%s", name);

    for (index = 0; index < numPasswords; index++) {
        if (strcmp(passwords[index].name, name) == 0) {
            printf("Enter new password: ");
            scanf("%s", password);

            strcpy(passwords[index].password, password);

            printf("Password updated.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void deletePassword() {
    char name[MAX_PASSWORD_LENGTH];

    printf("Enter password name to delete: ");
    scanf("%s", name);

    for (int index = 0; index < numPasswords; index++) {
        if (strcmp(passwords[index].name, name) == 0) {
            numPasswords--;

            for (int i = index; i < numPasswords; i++) {
                strcpy(passwords[i].name, passwords[i+1].name);
                strcpy(passwords[i].password, passwords[i+1].password);
            }

            printf("Password deleted.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void displayPasswords() {
    printf("Passwords:\n");
    for (int index = 0; index < numPasswords; index++) {
        printf("%s: %s\n", passwords[index].name, passwords[index].password);
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Edit password\n");
        printf("3. Delete password\n");
        printf("4. Display passwords\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                editPassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                displayPasswords();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}