//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char *username;
    char *password;
    char *website;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char website[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);
    printf("Enter website: ");
    scanf("%s", website);

    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    passwords[numPasswords].username = strdup(username);
    passwords[numPasswords].password = strdup(password);
    passwords[numPasswords].website = strdup(website);

    numPasswords++;
    printf("Password added successfully.\n");
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("No passwords found.\n");
        return;
    }

    printf("Username\tPassword\tWebsite\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t\t%s\t\t%s\n", passwords[i].username, passwords[i].password, passwords[i].website);
    }
}

int main() {
    char choice;
    while (1) {
        printf("Password Manager\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                addPassword();
                break;
            case '2':
                viewPasswords();
                break;
            case '3':
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}