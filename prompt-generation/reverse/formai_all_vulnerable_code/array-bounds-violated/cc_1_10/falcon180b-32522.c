//Falcon-180B DATASET v1.0 Category: Password management ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
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

    passwords[numPasswords].username = strdup(username);
    passwords[numPasswords].password = strdup(password);

    numPasswords++;
}

void removePassword(int index) {
    free(passwords[index].username);
    free(passwords[index].password);

    for (int i = index; i < numPasswords - 1; i++) {
        passwords[i] = passwords[i + 1];
    }

    numPasswords--;
}

void changePassword(int index) {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter new username: ");
    scanf("%s", username);

    printf("Enter new password: ");
    scanf("%s", password);

    free(passwords[index].username);
    free(passwords[index].password);

    passwords[index].username = strdup(username);
    passwords[index].password = strdup(password);
}

void displayPasswords() {
    for (int i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("Password Management System\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Change password\n");
        printf("4. Display passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            printf("Enter password index: ");
            scanf("%d", &choice);
            removePassword(choice);
            break;
        case 3:
            printf("Enter password index: ");
            scanf("%d", &choice);
            changePassword(choice);
            break;
        case 4:
            displayPasswords();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}