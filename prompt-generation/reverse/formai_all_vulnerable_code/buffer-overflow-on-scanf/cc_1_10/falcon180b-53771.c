//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define PASSWORD_LENGTH 20

typedef struct {
    char password[PASSWORD_LENGTH];
    char username[20];
} Password;

void generatePassword(char *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int length = strlen(charset) - 1;
    int i;

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int randIndex = rand() % length;
        password[i] = charset[randIndex];
    }

    password[PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    char username[20];
    char password[PASSWORD_LENGTH];
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];

    printf("Enter your username: ");
    scanf("%s", username);

    while (numPasswords < MAX_PASSWORDS) {
        printf("Enter a password for %s: ", username);
        generatePassword(password);
        strcpy(passwords[numPasswords].password, password);
        strcpy(passwords[numPasswords].username, username);
        numPasswords++;
    }

    printf("\nPasswords generated for %s:\n", username);
    for (int i = 0; i < numPasswords; i++) {
        printf("%s\n", passwords[i].password);
    }

    return 0;
}