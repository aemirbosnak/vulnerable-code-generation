//Falcon-180B DATASET v1.0 Category: Password management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Error: Password list is full.\n");
        return;
    }

    char name[MAX_PASSWORD_LENGTH];
    printf("Enter the name of the website/service:\n");
    scanf("%s", name);

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the password:\n");
    scanf("%s", password);

    Password p;
    strcpy(p.name, name);
    strcpy(p.password, password);

    passwords[numPasswords] = p;
    numPasswords++;
}

void deletePassword() {
    if (numPasswords == 0) {
        printf("Error: Password list is empty.\n");
        return;
    }

    int i;
    printf("Enter the index of the password to delete:\n");
    scanf("%d", &i);

    if (i < 0 || i >= numPasswords) {
        printf("Error: Invalid index.\n");
        return;
    }

    for (int j = i; j < numPasswords - 1; j++) {
        passwords[j] = passwords[j + 1];
    }

    numPasswords--;
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("Error: Password list is empty.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("Name: %s\nPassword: %s\n\n", passwords[i].name, passwords[i].password);
    }
}

int main() {
    char choice;
    while (1) {
        printf("Password Management System\n");
        printf("1. Add Password\n2. Delete Password\n3. View Passwords\n4. Exit\n");
        printf("Enter your choice:\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                addPassword();
                break;
            case '2':
                deletePassword();
                break;
            case '3':
                viewPasswords();
                break;
            case '4':
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}