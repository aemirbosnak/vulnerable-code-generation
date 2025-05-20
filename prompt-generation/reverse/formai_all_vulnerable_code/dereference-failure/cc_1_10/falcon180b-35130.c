//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;
} Password;

Password *generatePassword(int length) {
    Password *password = (Password*)malloc(sizeof(Password));
    password->length = length;
    for (int i = 0; i < length; i++) {
        password->password[i] = 'a' + rand() % 26;
    }
    password->password[length] = '\0';
    return password;
}

Password *copyPassword(Password *password) {
    Password *newPassword = (Password*)malloc(sizeof(Password));
    newPassword->length = password->length;
    strcpy(newPassword->password, password->password);
    return newPassword;
}

void printPassword(Password *password) {
    printf("Password: %s\n", password->password);
}

Password *recursivePasswordGenerator(int length) {
    if (length == 0) {
        return NULL;
    }

    Password *password = generatePassword(length);
    if (length == 1) {
        return password;
    }

    Password *newPassword = recursivePasswordGenerator(length - 1);
    copyPassword(newPassword);
    printf("Generated password: %s\n", newPassword->password);
    return password;
}

int main() {
    int length;
    printf("Enter password length: ");
    scanf("%d", &length);

    Password *password = recursivePasswordGenerator(length);
    printPassword(password);

    return 0;
}