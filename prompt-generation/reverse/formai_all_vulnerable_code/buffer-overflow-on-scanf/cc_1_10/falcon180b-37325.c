//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORDS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 100

struct Password {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

void generatePassword(char* password) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < strlen(password); i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[strlen(password)] = '\0';
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int numPasswords;
    printf("Enter the number of passwords you want to generate: ");
    scanf("%d", &numPasswords);
    if (numPasswords <= 0 || numPasswords > MAX_PASSWORDS) {
        printf("Invalid number of passwords.\n");
        return 1;
    }
    printf("Enter your username: ");
    scanf("%s", username);
    for (int i = 0; i < numPasswords; i++) {
        printf("Generating password %d...\n", i+1);
        generatePassword(password);
        printf("Password %d: %s\n", i+1, password);
        struct Password pwd = {.username = username,.password = password};
        FILE* fp = fopen("passwords.txt", "a");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
        fprintf(fp, "Username: %s\nPassword: %s\n\n", pwd.username, pwd.password);
        fclose(fp);
    }
    printf("Passwords generated and saved to passwords.txt\n");
    return 0;
}