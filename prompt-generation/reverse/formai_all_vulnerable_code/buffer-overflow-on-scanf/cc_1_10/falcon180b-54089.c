//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    fgets(username, MAX_PASSWORD_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    numPasswords++;

    printf("Password added successfully.\n");
}

void viewPasswords() {
    printf("Username\t\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    char username[MAX_PASSWORD_LENGTH];

    printf("Enter username to search: ");
    fgets(username, MAX_PASSWORD_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';

    int index = -1;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index!= -1) {
        printf("Password: %s\n", passwords[index].password);
    } else {
        printf("Password not found.\n");
    }
}

void main() {
    int choice;

    do {
        printf("\nPassword Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search password\n");
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);
}