//Falcon-180B DATASET v1.0 Category: Password management ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

struct Password {
    char name[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generatePassword(char* password, int length) {
    const char* characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]|\\:;\"'<>,.?/";
    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }
    password[length] = '\0';
}

int main() {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your master password: ");
    scanf("%s", password);

    FILE* passwordsFile = fopen("passwords.txt", "rb");
    if (passwordsFile == NULL) {
        printf("Passwords file not found. Creating a new one.\n");
        passwordsFile = fopen("passwords.txt", "wb");
        fclose(passwordsFile);
    }

    passwordsFile = fopen("passwords.txt", "rb+");

    char buffer[MAX_PASSWORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), passwordsFile)!= NULL) {
        struct Password passwordEntry;
        sscanf(buffer, "%s %s", passwordEntry.name, passwordEntry.password);

        if (strcmp(username, passwordEntry.name) == 0) {
            if (strcmp(password, passwordEntry.password) == 0) {
                printf("Login successful!\n");
                return 0;
            } else {
                printf("Incorrect master password.\n");
                return 1;
            }
        }
    }

    printf("User not found. Creating a new account.\n");

    generatePassword(password, strlen(password));

    rewind(passwordsFile);

    fprintf(passwordsFile, "%s %s\n", username, password);

    fclose(passwordsFile);

    return 0;
}