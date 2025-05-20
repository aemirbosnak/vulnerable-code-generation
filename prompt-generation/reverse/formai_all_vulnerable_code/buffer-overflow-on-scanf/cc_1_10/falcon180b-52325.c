//Falcon-180B DATASET v1.0 Category: Password management ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50
#define MAX_USER_LENGTH 50

typedef struct {
    char username[MAX_USER_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[MAX_USER_LENGTH];
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
    char username[MAX_USER_LENGTH];

    printf("Enter username to delete: ");
    scanf("%s", username);

    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            printf("Password deleted.\n");
            break;
        }
    }
}

void viewPasswords() {
    int i;

    printf("Username\t\tPassword\n");
    for (i = 0; i < numPasswords; i++) {
        if (passwords[i].username[0]!= '\0') {
            printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n");
        printf("2. Delete password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
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