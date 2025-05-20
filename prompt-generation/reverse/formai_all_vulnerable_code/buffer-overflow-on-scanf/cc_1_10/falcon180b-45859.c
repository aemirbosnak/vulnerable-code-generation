//Falcon-180B DATASET v1.0 Category: Password management ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 100

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(char* username, int length) {
    char password[MAX_PASSWORD_LENGTH];
    int i;

    for (i = 0; i < length; i++) {
        password[i] = toupper(rand() % 26 + 'A');
    }

    strcpy(passwords[numPasswords].username, username);
    strcpy(passwords[numPasswords].password, password);
    passwords[numPasswords].length = length;

    numPasswords++;
}

void printPasswords() {
    int i;

    for (i = 0; i < numPasswords; i++) {
        printf("Username: %s\n", passwords[i].username);
        printf("Password: %s\n", passwords[i].password);
        printf("Length: %d\n\n", passwords[i].length);
    }
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password length: ");
    scanf("%d", &length);

    generatePassword(username, length);
    printPasswords();

    return 0;
}