//FormAI DATASET v1.0 Category: Password management ; Style: random
#include <stdio.h>
#include <string.h>

#define MAX_PASSWORDS 50
#define MAX_PASSWORD_LENGTH 25

int numPasswords = 0;
char passwords[MAX_PASSWORDS][MAX_PASSWORD_LENGTH];

void displayMenu() {
    printf("\nWelcome to Password Manager!\n");
    printf("1. Add a password\n");
    printf("2. View all passwords\n");
    printf("3. Delete a password\n");
    printf("4. Change a password\n");
    printf("5. Exit\n");
    printf("\nEnter number: ");
}

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("\nMaximum number of passwords reached.\n");
        return;
    }
    printf("\nEnter password: ");
    scanf("%s", passwords[numPasswords]);
    numPasswords++;
    printf("\nPassword added successfully.\n");
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("\nNo passwords saved.\n");
        return;
    }
    printf("\nSaved Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i+1, passwords[i]);
    }
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("\nNo passwords saved.\n");
        return;
    }
    int choice = 0;
    printf("\nEnter index of password to delete: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > numPasswords) {
        printf("\nInvalid index.\n");
        return;
    }
    for (int i = choice-1; i < numPasswords-1; i++) {
        strcpy(passwords[i], passwords[i+1]);
    }
    numPasswords--;
    printf("\nPassword deleted successfully.\n");
}

void changePassword() {
    if (numPasswords == 0) {
        printf("\nNo passwords saved.\n");
        return;
    }
    int choice = 0;
    printf("\nEnter index of password to change: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > numPasswords) {
        printf("\nInvalid index.\n");
        return;
    }
    printf("\nEnter new password: ");
    scanf("%s", passwords[choice-1]);
    printf("\nPassword changed successfully.\n");
}

int main() {
    int option = 0;
    do {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
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
                changePassword();
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    } while (option != 5);
    return 0;
}