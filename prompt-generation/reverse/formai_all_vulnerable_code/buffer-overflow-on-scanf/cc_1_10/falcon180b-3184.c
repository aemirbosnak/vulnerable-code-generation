//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void editPassword() {
    char username[50];
    int index;

    printf("Enter username to edit: ");
    scanf("%s", username);

    for (index = 0; index < numPasswords; index++) {
        if (strcmp(passwords[index].username, username) == 0) {
            printf("Enter new password: ");
            scanf("%s", passwords[index].password);

            break;
        }
    }
}

void deletePassword() {
    char username[50];

    printf("Enter username to delete: ");
    scanf("%s", username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i + 1], (numPasswords - i - 1) * sizeof(Password));

            numPasswords--;

            break;
        }
    }
}

void viewPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Edit password\n");
        printf("3. Delete password\n");
        printf("4. View passwords\n");
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
                viewPasswords();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}