//Falcon-180B DATASET v1.0 Category: Password management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    char username[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char* password, char* username) {
    if(numPasswords >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }

    strcpy(passwords[numPasswords].password, password);
    strcpy(passwords[numPasswords].username, username);

    numPasswords++;
}

void printPasswords() {
    printf("Passwords:\n");
    for(int i = 0; i < numPasswords; i++) {
        printf("%s - %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a username: ");
    scanf("%s", username);

    printf("Enter a password: ");
    scanf("%s", password);

    addPassword(password, username);
    printPasswords();

    return 0;
}