//Falcon-180B DATASET v1.0 Category: Password management ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} Password;

void generatePassword(char* password, int length) {
    const char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[];:,.<>?/|";
    int i;
    for (i = 0; i < length; i++) {
        password[i] = chars[rand() % strlen(chars)];
    }
    password[length] = '\0';
}

int main() {
    int numPasswords = 0;
    Password passwords[MAX_PASSWORDS];
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Welcome to the Password Manager!\n");
    printf("Please enter your username: ");
    scanf("%s", username);

    FILE* file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("No passwords found.\n");
        fclose(file);
    } else {
        while (fscanf(file, "%s %s\n", username, password)!= EOF) {
            if (strcmp(username, username) == 0) {
                printf("Password found for %s:\n%s\n", username, password);
            }
        }
        fclose(file);
    }

    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        printf("Enter the username for password %d: ", i+1);
        scanf("%s", username);
        generatePassword(password, MAX_PASSWORD_LENGTH);
        printf("Password generated for %s: %s\n", username, password);
        strcpy(passwords[i].username, username);
        strcpy(passwords[i].password, password);
    }

    FILE* newFile = fopen("passwords.txt", "w");
    if (newFile == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    for (int i = 0; i < numPasswords; i++) {
        fprintf(newFile, "%s %s\n", passwords[i].username, passwords[i].password);
    }

    fclose(newFile);

    printf("Passwords generated and saved to passwords.txt.\n");

    return 0;
}