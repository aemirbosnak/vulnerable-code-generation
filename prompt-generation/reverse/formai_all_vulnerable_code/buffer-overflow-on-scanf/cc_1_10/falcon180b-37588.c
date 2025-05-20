//Falcon-180B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[MAX_PASSWORD_LENGTH];
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
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            for (int j = i; j < numPasswords - 1; j++) {
                strcpy(passwords[j].username, passwords[j + 1].username);
                strcpy(passwords[j].password, passwords[j + 1].password);
            }

            numPasswords--;
            break;
        }
    }
}

void searchPassword() {
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }
}

void listPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("Username: %s\nPassword: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. Search password\n");
        printf("4. List passwords\n");
        printf("5. Exit\n");
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
                searchPassword();
                break;
            case 4:
                listPasswords();
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