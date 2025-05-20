//FormAI DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct {
    char account[50];
    char password[50];
} Password;

Password passwordList[MAX_PASSWORDS];

int numPasswords = 0;

void createPassword() {
    Password newPassword;

    printf("Enter account name: ");
    scanf("%s", newPassword.account);

    printf("Enter desired password length: ");
    int length;
    scanf("%d", &length);

    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
    int numChars = strlen(characters);

    for (int i = 0; i < length; i++) {
        newPassword.password[i] = characters[rand()%numChars];
    }
    newPassword.password[length] = '\0';

    passwordList[numPasswords] = newPassword;
    numPasswords++;

    printf("Password created successfully!\n\n");
}

void displayPasswords() {
    if (numPasswords == 0) {
        printf("You have no saved passwords.\n\n");
        return;
    }

    printf("Your saved passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s: %s\n", i+1, passwordList[i].account, passwordList[i].password);
    }
    printf("\n");
}

int findPassword(char* account) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwordList[i].account, account) == 0) {
            return i;
        }
    }
    return -1;
}

void retrievePassword() {
    if (numPasswords == 0) {
        printf("You have no saved passwords.\n\n");
        return;
    }

    char account[50];
    printf("Enter account name: ");
    scanf("%s", account);

    int index = findPassword(account);

    if (index == -1) {
        printf("Password for account \"%s\" not found.\n\n", account);
    } else {
        printf("The password for account \"%s\" is: %s\n\n", account, passwordList[index].password);
    }
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("You have no saved passwords.\n\n");
        return;
    }

    char account[50];
    printf("Enter account name: ");
    scanf("%s", account);

    int index = findPassword(account);

    if (index == -1) {
        printf("Password for account \"%s\" not found.\n\n", account);
    } else {
        for (int i = index; i < numPasswords-1; i++) {
            passwordList[i] = passwordList[i+1];
        }
        numPasswords--;
        printf("Password for account \"%s\" deleted.\n\n", account);
    }
}

int main() {
    printf("Welcome to your password manager!\n\n");

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Create a password\n");
        printf("2. Retrieve a password\n");
        printf("3. Delete a password\n");
        printf("4. Display all passwords\n");
        printf("5. Exit\n");
        printf("Enter your selection: ");

        int selection;
        scanf("%d", &selection);

        switch (selection) {
            case 1:
                createPassword();
                break;
            case 2:
                retrievePassword();
                break;
            case 3:
                deletePassword();
                break;
            case 4:
                displayPasswords();
                break;
            case 5:
                printf("Thanks for using your password manager!\n");
                exit(0);
            default:
                printf("Invalid selection. Please try again.\n\n");
        }
    }
}