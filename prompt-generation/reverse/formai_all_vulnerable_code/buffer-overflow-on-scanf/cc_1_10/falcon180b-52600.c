//Falcon-180B DATASET v1.0 Category: Password management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void viewPasswords() {
    int i;

    printf("Username\t\tPassword\n");

    for (i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void deletePassword() {
    char username[MAX_USERNAME_LENGTH];

    printf("Enter username to delete: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            printf("Password deleted\n");
            break;
        }
    }
}

void searchPassword() {
    char username[MAX_USERNAME_LENGTH];

    printf("Enter username to search: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password found\n");
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Search password\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            viewPasswords();
            break;
        case 3:
            deletePassword();
            break;
        case 4:
            searchPassword();
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 0);

    return 0;
}