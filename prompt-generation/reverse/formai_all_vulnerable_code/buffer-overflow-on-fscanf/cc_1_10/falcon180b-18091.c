//Falcon-180B DATASET v1.0 Category: Password management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 64
#define MAX_USERNAME_LENGTH 64

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(Password *password) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int length = strlen(charset);
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        password->password[i] = charset[rand() % length];
    }
    password->password[MAX_PASSWORD_LENGTH - 1] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No passwords found.\n");
    } else {
        while (fscanf(file, "%s %s\n", passwords[numPasswords].username, passwords[numPasswords].password) == 2) {
            numPasswords++;
        }
        fclose(file);
    }

    printf("Enter the number of passwords you want to generate: ");
    int numNewPasswords;
    scanf("%d", &numNewPasswords);

    for (int i = 0; i < numNewPasswords; i++) {
        generatePassword(&passwords[numPasswords]);
        printf("Username: ");
        scanf("%s", passwords[numPasswords].username);
        numPasswords++;
    }

    file = fopen("passwords.txt", "w");
    for (int i = 0; i < numPasswords; i++) {
        fprintf(file, "%s %s\n", passwords[i].username, passwords[i].password);
    }
    fclose(file);

    printf("Passwords saved to passwords.txt.\n");

    return 0;
}