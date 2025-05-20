//Falcon-180B DATASET v1.0 Category: Password management ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 1000

typedef struct {
    char *username;
    char *password;
    char *website;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: Maximum number of passwords reached.\n");
        return;
    }

    Password newPassword;
    printf("Enter username: ");
    scanf("%s", newPassword.username);
    printf("Enter password: ");
    scanf("%s", newPassword.password);
    printf("Enter website: ");
    scanf("%s", newPassword.website);

    passwords[numPasswords] = newPassword;
    numPasswords++;
}

void viewPasswords() {
    printf("\nUsername\tPassword\tWebsite\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\t%s\t%s\n", passwords[i].username, passwords[i].password, passwords[i].website);
    }
}

void searchPassword() {
    char searchTerm[100];
    printf("\nEnter search term: ");
    scanf("%s", searchTerm);

    for (int i = 0; i < numPasswords; i++) {
        if (strstr(passwords[i].username, searchTerm) || strstr(passwords[i].password, searchTerm) || strstr(passwords[i].website, searchTerm)) {
            printf("\nUsername: %s\nPassword: %s\nWebsite: %s\n", passwords[i].username, passwords[i].password, passwords[i].website);
        }
    }
}

int main() {
    printf("Welcome to the Password Manager!\n");

    while (1) {
        printf("\nOptions:\n1. Add password\n2. View passwords\n3. Search password\n4. Exit\n");
        int choice;
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
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}