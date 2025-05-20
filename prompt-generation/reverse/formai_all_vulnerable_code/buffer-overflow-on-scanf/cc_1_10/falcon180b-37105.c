//Falcon-180B DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 100
#define MAX_USERNAME_LEN 50

typedef struct {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
} Password;

void generatePassword(char* password, int length) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+{}|:<>?,./;'[]\\-=";
    int charsetLength = strlen(charset);
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetLength];
    }
    password[length] = '\0';
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int numPasswords = 0;

    char username[MAX_USERNAME_LEN];
    printf("Enter your username: ");
    scanf("%s", username);

    if (numPasswords == MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return 1;
    }

    char password[MAX_PASSWORD_LEN];
    generatePassword(password, rand() % 16 + 8);
    strcpy(passwords[numPasswords].password, password);
    strcpy(passwords[numPasswords].username, username);
    numPasswords++;

    FILE* file = fopen("passwords.txt", "a+");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    for (int i = 0; i < numPasswords; i++) {
        fprintf(file, "Username: %s\nPassword: %s\n\n", passwords[i].username, passwords[i].password);
    }

    fclose(file);

    printf("Password generated and saved to file.\n");
    return 0;
}