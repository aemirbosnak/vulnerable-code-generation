//Falcon-180B DATASET v1.0 Category: Password management ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int length;
} Password;

void generatePassword(Password *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]|\:;\"'<>,.?/";
    int charsetLength = strlen(charset);
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        char randomChar = charset[rand() % charsetLength];
        password->password[i] = randomChar;
        password->length++;
    }
    password->password[password->length] = '\0';
}

void printPasswords(Password passwords[], int numPasswords) {
    for (int i = 0; i < numPasswords; i++) {
        printf("Password %d: %s\n", i+1, passwords[i].password);
    }
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    while (numPasswords < MAX_PASSWORDS) {
        char choice;
        printf("Enter 'g' to generate a new password or 'q' to quit: ");
        scanf("%c", &choice);

        if (choice == 'g') {
            generatePassword(&passwords[numPasswords]);
            numPasswords++;
            printf("Password generated successfully!\n");
        } else if (choice == 'q') {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Your passwords:\n");
    printPasswords(passwords, numPasswords);

    return 0;
}