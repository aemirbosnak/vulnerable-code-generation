//Falcon-180B DATASET v1.0 Category: Password management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached!\n");
        return;
    }

    Password password;
    printf("Enter a new password: ");
    scanf("%s", password.password);

    password.length = strlen(password.password);

    strcpy(passwords[numPasswords].password, password.password);
    passwords[numPasswords].length = password.length;

    numPasswords++;
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("No passwords to delete!\n");
        return;
    }

    int index;
    printf("Enter the index of the password to delete: ");
    scanf("%d", &index);

    if (index >= numPasswords) {
        printf("Invalid index!\n");
        return;
    }

    numPasswords--;
    for (int i = index; i < numPasswords; i++) {
        strcpy(passwords[i].password, passwords[i + 1].password);
        passwords[i].length = passwords[i + 1].length;
    }
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords to view!\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("Password %d: %s\n", i + 1, passwords[i].password);
    }
}

int main() {
    int choice;
    do {
        printf("\nPassword Manager\n");
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
            printf("Invalid choice!\n");
        }
    } while (choice!= 4);

    return 0;
}