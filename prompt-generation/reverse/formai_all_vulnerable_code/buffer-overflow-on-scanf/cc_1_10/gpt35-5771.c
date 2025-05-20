//FormAI DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORDS 50

typedef struct {
    char website[50];
    char username[50];
    char password[50];
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword() {
    if (numPasswords == MAX_PASSWORDS) {
        printf("Sorry, you have reached the maximum number of passwords.\n");
        return;
    }

    Password p;
    printf("Enter website: ");
    scanf("%s", p.website);
    printf("Enter username: ");
    scanf("%s", p.username);
    printf("Enter password: ");
    scanf("%s", p.password);

    passwords[numPasswords++] = p;
    printf("Password added successfully!\n");
}

void viewPasswords() {
    if (numPasswords == 0) {
        printf("You haven't added any passwords yet.\n");
        return;
    }

    for (int i = 0; i < numPasswords; i++) {
        printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
    }
}

void searchPasswords() {
    char website[50];
    printf("Enter website to search: ");
    scanf("%s", website);

    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].website, website) == 0) {
            printf("Website: %s\nUsername: %s\nPassword: %s\n", passwords[i].website, passwords[i].username, passwords[i].password);
            found = 1;
        }
    }

    if (!found) {
        printf("No passwords found for that website.\n");
    }
}

int main() {
    int choice;
    do {
        printf("Welcome to your Password Manager! What would you like to do?\n");
        printf("1. Add password\n");
        printf("2. View passwords\n");
        printf("3. Search passwords by website\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                searchPasswords();
                break;
            case 4:
                printf("Thank you for using Password Manager!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}