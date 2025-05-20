//Falcon-180B DATASET v1.0 Category: Password management ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);

    numPasswords++;
}

void viewPasswords() {
    int i;

    printf("Username\tPassword\n");

    for (i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void deletePassword() {
    char username[50];

    printf("Enter username to delete: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            memmove(&passwords[i], &passwords[i + 1], (numPasswords - i - 1) * sizeof(Password));
            numPasswords--;
            break;
        }
    }
}

void searchPassword() {
    char username[50];

    printf("Enter username to search: ");
    scanf("%s", username);

    int i;
    for (i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Password: %s\n", passwords[i].password);
            break;
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add password\n2. View passwords\n3. Delete password\n4. Search password\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
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
            searchPassword();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}