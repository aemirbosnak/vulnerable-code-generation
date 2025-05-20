//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 10
#define MAX_ATTEMPTS 3

struct Password {
    char password[PASSWORD_LENGTH + 1];
    int attempts;
};

void generatePassword(char *password) {
    srand((unsigned int)time(NULL));
    int i;

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        int random = rand() % 3;

        if (random == 0) {
            password[i] = (char)(rand() % 10 + 48); // Numbers
        } else if (random == 1) {
            password[i] = (char)(rand() % 26 + 65); // Uppercase letters
        } else if (random == 2) {
            password[i] = (char)(rand() % 26 + 97); // Lowercase letters
        }
    }
    password[i] = '\0';
}

void savePassword(const char *password) {
    FILE *file = fopen("passwords.txt", "w");

    if (file == NULL) {
        printf("Error: Unable to save password\n");
        return;
    }

    fprintf(file, "%s\n", password);
    fclose(file);
}

void getPassword(char *password) {
    FILE *file = fopen("passwords.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to retrieve password\n");
        generatePassword(password);
        savePassword(password);
        return;
    }

    fgets(password, PASSWORD_LENGTH + 1, file);
    fclose(file);
}

void validatePassword(const char *userPassword, struct Password *password) {
    if (strcmp(userPassword, password->password) == 0) {
        password->attempts = 0;
        printf("Success! You have logged in.\n");
    } else {
        password->attempts++;
        if (password->attempts > MAX_ATTEMPTS) {
            printf("Too many incorrect attempts. Account locked.\n");
            exit(0);
        } else {
            printf("Incorrect password. Please try again.\n");
        }
    }
}

int main() {
    struct Password passwordStruct;
    getPassword(passwordStruct.password);
    passwordStruct.attempts = 0;

    char userPassword[PASSWORD_LENGTH + 1];
    int i;

    printf("Welcome! Please enter your password.\n");
    for (i = 0; i < MAX_ATTEMPTS; i++) {
        printf("Password attempt %d: ", i + 1);
        scanf("%s", userPassword);
        validatePassword(userPassword, &passwordStruct);
        if (passwordStruct.attempts == 0) {
            break;
        }
    }

    return 0;
}