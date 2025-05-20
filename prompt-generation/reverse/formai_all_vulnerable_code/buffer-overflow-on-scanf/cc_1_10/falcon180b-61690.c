//Falcon-180B DATASET v1.0 Category: Password management ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
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
        printf("Error: No passwords found.\n");
        return;
    }

    printf("Enter username to remove: ");
    scanf("%s", passwords[0].username);

    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, passwords[0].username) == 0) {
            strcpy(passwords[i].username, "");
            strcpy(passwords[i].password, "");
            printf("Password removed successfully.\n");
            return;
        }
    }

    printf("Error: Username not found.\n");
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("Error: No passwords found.\n");
        return;
    }

    printf("Username\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. View passwords\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                removePassword();
                break;
            case 3:
                viewPasswords();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}