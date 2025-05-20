//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter the name of the website/service: ");
    scanf("%s", name);

    printf("Enter the password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].name, name);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void viewPasswords() {
    int i;

    printf("\nPasswords:\n");
    for (i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].name, passwords[i].password);
    }
}

void searchPassword() {
    char name[MAX_PASSWORD_LENGTH];

    printf("Enter the name of the website/service to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].name, name) == 0) {
            printf("\nPassword: %s\n", passwords[i].password);
            return;
        }
    }

    printf("\nPassword not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add Password\n");
        printf("2. View Passwords\n");
        printf("3. Search Password\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addPassword();
            break;
        case 2:
            viewPasswords();
            break;
        case 3:
            searchPassword();
            break;
        case 4:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}