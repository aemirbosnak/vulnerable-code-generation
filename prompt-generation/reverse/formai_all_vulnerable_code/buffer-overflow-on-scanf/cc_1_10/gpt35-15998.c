//FormAI DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char website[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwordList[MAX_PASSWORDS];
int numPasswords = 0;

void clearInput() {
    while (getchar() != '\n');
}

int getPasswordIndex(char *website) {
    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwordList[i].website, website) == 0) {
            return i;
        }
    }
    return -1;
}

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password newPassword;

    printf("Enter website: ");
    fgets(newPassword.website, MAX_PASSWORD_LENGTH, stdin);
    newPassword.website[strcspn(newPassword.website, "\n")] = '\0';

    printf("Enter username: ");
    fgets(newPassword.username, MAX_PASSWORD_LENGTH, stdin);
    newPassword.username[strcspn(newPassword.username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(newPassword.password, MAX_PASSWORD_LENGTH, stdin);
    newPassword.password[strcspn(newPassword.password, "\n")] = '\0';

    passwordList[numPasswords] = newPassword;
    numPasswords++;
}

void printPasswords() {
    int i;
    for (i = 0; i < numPasswords; i++) {
        Password p = passwordList[i];
        printf("Website: %s\nUsername: %s\nPassword: %s\n\n", p.website, p.username, p.password);
    }
}

void getPassword() {
    char website[MAX_PASSWORD_LENGTH];
    printf("Enter website: ");
    fgets(website, MAX_PASSWORD_LENGTH, stdin);
    website[strcspn(website, "\n")] = '\0';

    int passwordIndex = getPasswordIndex(website);
    if (passwordIndex == -1) {
        printf("Error: Password not found for website '%s'.\n", website);
        return;
    }

    Password password = passwordList[passwordIndex];
    printf("Website: %s\nUsername: %s\nPassword: %s\n\n", password.website, password.username, password.password);
}

void deletePassword() {
    char website[MAX_PASSWORD_LENGTH];
    printf("Enter website: ");
    fgets(website, MAX_PASSWORD_LENGTH, stdin);
    website[strcspn(website, "\n")] = '\0';

    int passwordIndex = getPasswordIndex(website);
    if (passwordIndex == -1) {
        printf("Error: Password not found for website '%s'.\n", website);
        return;
    }

    int i;
    for (i = passwordIndex; i < numPasswords - 1; i++) {
        passwordList[i] = passwordList[i + 1];
    }
    numPasswords--;
    printf("Password for website '%s' has been deleted.\n", website);
}

int main() {
    while (1) {
        printf("Password Manager\n");
        printf("1. Add Password\n");
        printf("2. Print Passwords\n");
        printf("3. Get Password\n");
        printf("4. Delete Password\n");
        printf("5. Exit\n");
        printf("Enter option: ");

        int option;
        scanf("%d", &option);
        clearInput();

        switch (option) {
            case 1:
                addPassword();
                break;
            case 2:
                printPasswords();
                break;
            case 3:
                getPassword();
                break;
            case 4:
                deletePassword();
                break;
            case 5:
                return 0;
            default:
                printf("Error: Invalid option.\n");
                break;
        }

        printf("\n");
    }
}