//Falcon-180B DATASET v1.0 Category: Password management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter username: ");
        scanf("%s", passwords[numPasswords].username);

        printf("Enter password: ");
        scanf("%s", passwords[numPasswords].password);

        numPasswords++;
    }

    while (1) {
        printf("Enter username: ");
        char username[MAX_USERNAME_LENGTH];
        scanf("%s", username);

        int found = 0;
        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(username, passwords[i].username) == 0) {
                printf("Enter password: ");
                char password[MAX_PASSWORD_LENGTH];
                scanf("%s", password);

                if (strcmp(password, passwords[i].password) == 0) {
                    printf("Login successful.\n");
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
    }

    return 0;
}