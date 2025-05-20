//Falcon-180B DATASET v1.0 Category: Password management ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
    printf("Password added successfully.\n");
}

void removePassword() {
    if (numPasswords == 0) {
        printf("Sorry, you don't have any passwords yet.\n");
        return;
    }

    printf("Enter username of the password you want to remove: ");
    scanf("%s", passwords[0].username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            numPasswords--;
            printf("Password removed successfully.\n");
            return;
        }
    }

    printf("Password not found.\n");
}

void searchPassword() {
    if (numPasswords == 0) {
        printf("Sorry, you don't have any passwords yet.\n");
        return;
    }

    printf("Enter username of the password you want to search for: ");
    scanf("%s", passwords[0].username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            return;
        }
    }

    printf("Password not found.\n");
}

void listPasswords() {
    if (numPasswords == 0) {
        printf("Sorry, you don't have any passwords yet.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. Search password\n");
        printf("4. List all passwords\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            removePassword();
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
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}