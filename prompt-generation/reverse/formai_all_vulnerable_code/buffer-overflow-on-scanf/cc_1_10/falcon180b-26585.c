//Falcon-180B DATASET v1.0 Category: Password management ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached\n");
        return;
    }

    char name[MAX_PASSWORD_LENGTH];
    printf("Enter the name of the website/account: ");
    scanf("%s", name);

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
    printf("Password added successfully\n");
}

void removePassword() {
    if (numPasswords == 0) {
        printf("Error: no passwords found\n");
        return;
    }

    char name[MAX_PASSWORD_LENGTH];
    printf("Enter the name of the website/account: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("Password found and removed\n");
            numPasswords--;
            return;
        }
    }

    printf("Password not found\n");
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found\n");
        return;
    }

    printf("Passwords:\n");
    int i;
    for (i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].name, passwords[i].password);
    }
}

void main() {
    int choice;

    printf("Welcome to the password manager\n");
    while (1) {
        printf("\n1. Add password\n2. Remove password\n3. View passwords\n4. Exit\n");
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
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}