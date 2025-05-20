//Falcon-180B DATASET v1.0 Category: Password management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char *username;
    char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void addPassword(char *username, char *password) {
    if (numPasswords >= MAX_PASSWORDS) {
        printf("Error: maximum number of passwords reached.\n");
        return;
    }

    Password *newPassword = &passwords[numPasswords];
    newPassword->username = strdup(username);
    newPassword->password = strdup(password);

    numPasswords++;
}

int findPassword(char *username) {
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            return i;
        }
    }

    return -1;
}

void deletePassword(int index) {
    if (index < 0 || index >= numPasswords) {
        printf("Error: invalid password index.\n");
        return;
    }

    free(passwords[index].username);
    free(passwords[index].password);

    for (int i = index; i < numPasswords - 1; i++) {
        Password *temp = &passwords[i];
        passwords[i] = passwords[i + 1];
        passwords[i + 1] = *temp;
    }

    numPasswords--;
}

void printPasswords() {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%s: %s\n", passwords[i].username, passwords[i].password);
    }
}

int main() {
    addPassword("example@gmail.com", "password123");
    addPassword("test@gmail.com", "test456");

    printPasswords();

    int index = findPassword("example@gmail.com");
    if (index!= -1) {
        deletePassword(index);
    }

    printPasswords();

    return 0;
}