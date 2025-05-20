//Falcon-180B DATASET v1.0 Category: Password management ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;
} Password;

Password passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generatePassword(Password *password) {
    int length = rand() % MAX_PASSWORD_LENGTH + 1;
    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % 3;
        if (randomIndex == 0) {
            password->password[i] = 'A' + rand() % 26;
        } else if (randomIndex == 1) {
            password->password[i] = 'a' + rand() % 26;
        } else {
            password->password[i] = '0' + rand() % 10;
        }
    }
    password->length = length;
}

void printPasswords() {
    printf("Passwords:\n");
    for (int i = 0; i < numPasswords; i++) {
        printf("%d. %s\n", i + 1, passwords[i].password);
    }
}

int main() {
    printf("Welcome to the password manager!\n");
    printf("In this post-apocalyptic world, it's important to keep your passwords safe.\n");
    printf("How many passwords would you like to generate? ");
    int numPasswordsToGenerate;
    scanf("%d", &numPasswordsToGenerate);
    for (int i = 0; i < numPasswordsToGenerate; i++) {
        generatePassword(&passwords[i]);
        numPasswords++;
    }
    printf("Your passwords have been generated:\n");
    printPasswords();
    return 0;
}