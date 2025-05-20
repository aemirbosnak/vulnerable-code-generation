//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_ATTEMPTS 5

struct PasswordCheckData {
    char password[MIN_LENGTH + 1];
    int strength;
    int attempts;
};

void initPasswordCheckData(struct PasswordCheckData *data) {
    memset(data, 0, sizeof(struct PasswordCheckData));
    strcpy(data->password, "");
}

void checkPasswordStrength(struct PasswordCheckData *data) {
    int lower = 0, upper = 0, digits = 0, special = 0;
    int length = strlen(data->password);

    for (int i = 0; i < length; i++) {
        char c = tolower(data->password[i]);
        if (isalpha(c)) lower++;
        else if (isdigit(c)) digits++;
        else if (strchr("!@#$%^&*()_+-={[}]:;\"<>,.?/| \t\n", c)) special++;
    }

    data->strength = (lower > 2 ? 1 : 0) +
                     (upper > 1 ? 1 : 0) +
                     (digits > 2 ? 1 : 0) +
                     (special > 1 ? 1 : 0);
}

bool isValidPassword(struct PasswordCheckData *data) {
    initPasswordCheckData(data);
    checkPasswordStrength(data);
    return data->strength > 0 && data->attempts < MAX_ATTEMPTS;
}

int main() {
    struct PasswordCheckData data;
    char guess[MIN_LENGTH + 1];
    srand(time(NULL));

    printf("Welcome to the Password Strength Checker!\n"
           "Please enter your password: ");

    fgets(data.password, sizeof(data.password), stdin);
    data.password[strlen(data.password) - 1] = '\0';

    int attempts = 0;
    while (attempts < MAX_ATTEMPTS && !isValidPassword(&data)) {
        checkPasswordStrength(&data);
        printf("Invalid password! Try again.\n"
               "Attempts remaining: %d\n"
               "Password length: %d\n"
               "Strength: %d\n", MAX_ATTEMPTS - attempts, strlen(data.password), data.strength);
        printf("Enter your new password: ");
        fgets(guess, sizeof(guess), stdin);
        guess[strlen(guess) - 1] = '\0';
        strcpy(data.password, guess);
        attempts++;
    }

    if (isValidPassword(&data)) {
        printf("Congratulations! Your password is strong.\n");
    } else {
        printf("Sorry, you have reached the maximum number of attempts.\n"
               "Your password will be discarded.\n");
    }

    return 0;
}