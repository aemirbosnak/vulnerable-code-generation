//Falcon-180B DATASET v1.0 Category: Password management ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[50];
    char password[PASSWORD_LENGTH];

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

    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Passwords:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

void deletePassword() {
    char username[50];

    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Enter username to delete: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            numPasswords--;
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Delete password\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}