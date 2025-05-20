//Falcon-180B DATASET v1.0 Category: Password management ; Style: detailed
/* C Password Management Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 64

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter a username: ");
        scanf("%s", username);
        printf("Enter a password: ");
        scanf("%s", password);

        strncpy(passwords[numPasswords].username, username, MAX_USERNAME_LENGTH);
        strncpy(passwords[numPasswords].password, password, MAX_PASSWORD_LENGTH);

        numPasswords++;
    }

    printf("\nEnter a username to search for: ");
    scanf("%s", username);

    int index = -1;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Username not found.\n");
    } else {
        printf("Password for %s: %s\n", passwords[index].username, passwords[index].password);
    }

    return 0;
}

/* End of C Password Management Program */