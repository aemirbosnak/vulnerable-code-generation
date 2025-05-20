//Falcon-180B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void displayPasswords() {
    printf("\nPasswords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    printf("\nWelcome to the Password Management System!\n");

    int choice;
    while (1) {
        printf("\n1. Add password\n2. Display passwords\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;

        case 2:
            displayPasswords();
            break;

        case 3:
            printf("\nExiting...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}