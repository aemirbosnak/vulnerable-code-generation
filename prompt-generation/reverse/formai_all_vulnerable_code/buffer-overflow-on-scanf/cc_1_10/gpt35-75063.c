//FormAI DATASET v1.0 Category: Password management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_LENGTH 25
#define TRUE 1
#define FALSE 0

struct Password {
    char name[MAX_LENGTH];
    char value[MAX_LENGTH];
};

struct PasswordManager {
    char masterPassword[MAX_LENGTH];
    struct Password passwords[MAX_PASSWORDS];
    int numOfPasswords;
};

void clearScreen() {
    system("clear||cls");
}

void printHeader() {
    printf("\n------------------------------");
    printf("\n    Password Management");
    printf("\n------------------------------\n\n");
}

int validatePassword(char* inputPassword, char* actualPassword) {
    return strcmp(inputPassword, actualPassword) == 0;
}

void promptMasterPassword(char* masterPassword) {
    printf("\nEnter Master Password: ");
    scanf("%s", masterPassword);
}

int promptAddPassword(struct PasswordManager* passwordManager) {
    char name[MAX_LENGTH], value[MAX_LENGTH];

    printf("\nEnter Website/Service Name: ");
    scanf("%s", name);
    printf("Enter Password: ");
    scanf("%s", value);

    if (passwordManager->numOfPasswords < MAX_PASSWORDS) {
        struct Password temp = {name, value};
        passwordManager->passwords[passwordManager->numOfPasswords++] = temp;
        printf("\nPassword added successfully!");
        return TRUE;
    } else {
        printf("\nPassword database is full. Remove passwords to add new ones.");
        return FALSE;
    }
}

void promptRemovePassword(struct PasswordManager* passwordManager) {
    int index;

    printf("\nEnter index of password to remove: ");
    scanf("%d", &index);

    if (index >= 0 && index < passwordManager->numOfPasswords) {
        for (int i = index; i < passwordManager->numOfPasswords - 1; i++) {
            passwordManager->passwords[i] = passwordManager->passwords[i+1];
        }
        printf("\nPassword removed successfully!");
        passwordManager->numOfPasswords--;
    } else {
        printf("\nInvalid index. Please try again.");
    }
}

void promptListPasswords(struct PasswordManager* passwordManager) {
    printf("\nList of Passwords:\n\n");
    for (int i = 0; i < passwordManager->numOfPasswords; i++) {
        printf("%d. %s - %s\n", i, passwordManager->passwords[i].name, passwordManager->passwords[i].value);
    }
}

void promptExit() {
    printf("\nThank you for using Password Management. Goodbye!\n");
    exit(0);
}

int main() {
    struct PasswordManager passwordManager = {"password", {}, 0};
    char input[MAX_LENGTH];

    clearScreen();
    while (TRUE) {
        printHeader();
        printf("Commands: [add | remove | list | exit]\n\n");
        printf("Enter Command: ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            if (validatePassword(passwordManager.masterPassword, "password")) {
                promptAddPassword(&passwordManager);
            } else {
                printf("\nInvalid password. Access Denied.");
            }
        } else if (strcmp(input, "remove") == 0) {
            if (validatePassword(passwordManager.masterPassword, "password")) {
                promptRemovePassword(&passwordManager);
            } else {
                printf("\nInvalid password. Access Denied.");
            }
        } else if (strcmp(input, "list") == 0) {
            if (validatePassword(passwordManager.masterPassword, "password")) {
                promptListPasswords(&passwordManager);
            } else {
                printf("\nInvalid password. Access Denied.");
            }
        } else if (strcmp(input, "exit") == 0) {
            promptExit();
        } else {
            printf("\nInvalid command. Please try again.");
        }
        getchar();
    }
    return 0;
}