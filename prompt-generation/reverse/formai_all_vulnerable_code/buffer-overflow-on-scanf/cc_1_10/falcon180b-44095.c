//Falcon-180B DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100

typedef struct {
    char username[50];
    char password[50];
} Password;

void generatePassword(char *password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_length];
    }

    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char username[50];
    char password[50];

    while (1) {
        printf("Enter a username: ");
        scanf("%s", username);

        int found = 0;
        for (int i = 0; i < numPasswords; i++) {
            if (strcmp(passwords[i].username, username) == 0) {
                printf("Password for %s: ", username);
                printf("%s\n", passwords[i].password);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Enter a new password for %s: ", username);
            generatePassword(password, 12);
            strcpy(passwords[numPasswords].password, password);
            strcpy(passwords[numPasswords].username, username);
            numPasswords++;
            printf("Password saved for %s\n", username);
        }
    }

    return 0;
}