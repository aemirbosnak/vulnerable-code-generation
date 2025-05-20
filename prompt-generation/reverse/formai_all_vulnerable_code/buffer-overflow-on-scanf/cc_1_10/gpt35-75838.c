//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 50

bool has_lowercase(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return true;
        }
    }
    return false;
}

bool has_uppercase(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

bool has_number(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return true;
        }
    }
    return false;
}

bool has_specialchar(const char *password) {
    const char *special_chars = "!@#$%^&*()_+`-={}|[]\\:\";'<>,.?/";
    for (int i = 0; i < strlen(special_chars); i++) {
        for (int j = 0; j < strlen(password); j++) {
            if (password[j] == special_chars[i]) {
                return true;
            }
        }
    }
    return false;
}

char *generate_random_password(int length) {
    const char *lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *number_chars = "0123456789";
    const char *special_chars = "!@#$%^&*()_+`-={}|[]\\:\";'<>,.?/";

    char *password = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++) {
        int category = rand() % 4;
        switch (category) {
            case 0:
                password[i] = lowercase_chars[rand() % strlen(lowercase_chars)];
                break;
            case 1:
                password[i] = uppercase_chars[rand() % strlen(uppercase_chars)];
                break;
            case 2:
                password[i] = number_chars[rand() % strlen(number_chars)];
                break;
            case 3:
                password[i] = special_chars[rand() % strlen(special_chars)];
                break;
        }
    }

    password[length] = '\0';

    if (!has_lowercase(password)) {
        int index = rand() % length;
        password[index] = lowercase_chars[rand() % strlen(lowercase_chars)];
    }

    if (!has_uppercase(password)) {
        int index = rand() % length;
        password[index] = uppercase_chars[rand() % strlen(uppercase_chars)];
    }

    if (!has_number(password)) {
        int index = rand() % length;
        password[index] = number_chars[rand() % strlen(number_chars)];
    }

    if (!has_specialchar(password)) {
        int index = rand() % length;
        password[index] = special_chars[rand() % strlen(special_chars)];
    }

    return password;
}

int main() {
    srand(time(NULL));
    int password_length;
    char *password;

    printf("Enter password length: ");
    scanf("%d", &password_length);

    do {
        password = generate_random_password(password_length);
    } while (strlen(password) != password_length);

    printf("Secure password generated: %s\n", password);

    free(password);
    return 0;
}