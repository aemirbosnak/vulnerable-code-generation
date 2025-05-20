//Falcon-180B DATASET v1.0 Category: Password management ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];

    while (1) {
        printf("Enter your username: ");
        scanf("%s", passwords[numPasswords].username);

        printf("Enter your password: ");
        scanf("%s", passwords[numPasswords].password);

        numPasswords++;

        if (numPasswords == MAX_PASSWORDS) {
            printf("Maximum number of passwords reached.\n");
            break;
        }

        printf("Do you want to add another password? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    while (1) {
        printf("Enter your username: ");
        char username[MAX_USERNAME_LENGTH];
        scanf("%s", username);

        int found = 0;
        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(username, passwords[i].username) == 0) {
                printf("Enter your password: ");
                char password[MAX_PASSWORD_LENGTH];
                scanf("%s", password);

                if (strcmp(passwords[i].password, password) == 0) {
                    printf("Login successful!\n");
                    found = 1;
                    break;
                } else {
                    printf("Incorrect password.\n");
                }
            }
        }

        if (!found) {
            printf("User not found.\n");
        }

        printf("Do you want to login again? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    return 0;
}