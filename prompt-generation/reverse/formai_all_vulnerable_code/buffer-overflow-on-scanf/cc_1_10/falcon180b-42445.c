//Falcon-180B DATASET v1.0 Category: Password management ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

struct Password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    int numPasswords = 0;
    struct Password passwords[MAX_PASSWORDS];

    printf("Welcome to the Happy Password Manager!\n");
    printf("How many passwords would you like to store? ");
    scanf("%d", &numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        printf("Enter the username for password #%d: ", i+1);
        scanf("%s", passwords[i].username);

        printf("Enter the password for %s: ", passwords[i].username);
        char password[MAX_PASSWORD_LENGTH];
        scanf("%s", password);

        strcpy(passwords[i].password, password);
    }

    printf("\nYour passwords have been saved!\n");

    while (1) {
        printf("\nEnter the username for the password you want to retrieve: ");
        char username[MAX_USERNAME_LENGTH];
        scanf("%s", username);

        int found = 0;
        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(passwords[i].username, username) == 0) {
                printf("\nThe password for %s is: %s\n", username, passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nPassword not found.\n");
        }
    }

    return 0;
}