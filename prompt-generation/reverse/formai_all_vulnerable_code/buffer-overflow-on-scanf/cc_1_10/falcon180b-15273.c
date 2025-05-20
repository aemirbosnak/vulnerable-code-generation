//Falcon-180B DATASET v1.0 Category: Password management ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 50
#define MAX_USERNAME_LENGTH 50

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} PasswordEntry;

PasswordEntry passwords[MAX_PASSWORDS];
int numPasswords = 0;

void generateRandomPassword(char *password, int length) {
    const char *characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = characters[rand() % strlen(characters)];
    }
    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    char username[MAX_USERNAME_LENGTH];
    printf("Enter your username: ");
    scanf("%s", username);

    int found = 0;
    for (int i = 0; i < numPasswords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            printf("Welcome back, %s!\n", username);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Welcome, %s! Please choose a password:\n", username);
        char password[MAX_PASSWORD_LENGTH];
        while (1) {
            generateRandomPassword(password, rand() % MAX_PASSWORD_LENGTH + 8);
            int duplicate = 0;
            for (int i = 0; i < numPasswords; i++) {
                if (strcmp(passwords[i].password, password) == 0) {
                    duplicate = 1;
                    break;
                }
            }
            if (!duplicate) {
                strcpy(passwords[numPasswords].password, password);
                strcpy(passwords[numPasswords].username, username);
                numPasswords++;
                printf("Your new password is: %s\n", password);
                break;
            }
        }
    }

    return 0;
}