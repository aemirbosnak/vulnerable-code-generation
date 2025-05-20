//Falcon-180B DATASET v1.0 Category: Password management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define PASSWORD_LENGTH 16

typedef struct {
    char name[20];
    char password[PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void printMenu() {
    printf("Choose an option:\n");
    printf("1. Add a password\n");
    printf("2. Remove a password\n");
    printf("3. Generate a password\n");
    printf("4. Exit\n");
}

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("You have reached the maximum number of passwords.\n");
        return;
    }

    printf("Enter the name of the password:\n");
    scanf("%s", passwords[numPasswords].name);

    printf("Enter the password:\n");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void removePassword() {
    if (numPasswords == 0) {
        printf("You do not have any passwords.\n");
        return;
    }

    printf("Enter the name of the password to remove:\n");
    char name[20];
    scanf("%s", name);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            memset(passwords[i].password, '\0', PASSWORD_LENGTH);
            numPasswords--;
            printf("The password has been removed.\n");
            return;
        }
    }

    printf("The password was not found.\n");
}

void generatePassword() {
    char password[PASSWORD_LENGTH];
    int length = 0;

    printf("Enter the desired length of the password (up to %d):\n", PASSWORD_LENGTH);
    scanf("%d", &length);

    if (length > PASSWORD_LENGTH) {
        printf("The password is too long.\n");
        return;
    }

    int i;
    for (i = 0; i < length; i++) {
        password[i] = rand() % 26 + 'a';
    }

    printf("Your password is: %s\n", password);
}

int main() {
    srand(time(NULL));

    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                removePassword();
                break;
            case 3:
                generatePassword();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}