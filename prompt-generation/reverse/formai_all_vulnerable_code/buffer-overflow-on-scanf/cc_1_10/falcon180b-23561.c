//Falcon-180B DATASET v1.0 Category: Password management ; Style: accurate
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
    printf("Enter username: ");
    scanf("%s", passwords[numPasswords].username);

    printf("Enter password: ");
    scanf("%s", passwords[numPasswords].password);

    numPasswords++;
}

void displayPasswords() {
    printf("Username\tPassword\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\n", passwords[i].username, passwords[i].password);
    }
}

void searchPassword() {
    printf("Enter username to search for: ");
    char searchUsername[MAX_PASSWORD_LENGTH];
    scanf("%s", searchUsername);

    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, searchUsername) == 0) {
            printf("Password for %s is: %s\n", searchUsername, passwords[i].password);
            found = 1;
        }
    }

    if (found == 0) {
        printf("No password found for %s\n", searchUsername);
    }
}

int main() {
    printf("Password Manager\n");

    while (1) {
        printf("\n1. Add password\n2. Display passwords\n3. Search password\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                displayPasswords();
                break;
            case 3:
                searchPassword();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}