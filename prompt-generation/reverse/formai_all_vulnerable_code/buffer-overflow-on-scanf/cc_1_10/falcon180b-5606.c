//Falcon-180B DATASET v1.0 Category: Password management ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
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

void deletePassword() {
    int i;
    char username[50];

    printf("Enter username to delete: ");
    scanf("%s", username);

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memset(&passwords[i], 0, sizeof(Password));
            numPasswords--;
            printf("Password deleted successfully.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void viewPasswords() {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("\nPassword Management System\n");
        printf("1. Add password\n2. Delete password\n3. View passwords\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                deletePassword();
                break;
            case 3:
                viewPasswords();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}