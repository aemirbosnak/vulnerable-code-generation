//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASS_LENGTH 32
#define MIN_PASS_LENGTH 8

char* generate_random_string(int length) {
    char* result = (char*)malloc(length * sizeof(char));
    if (!result) {
        printf("Memory error\n");
        exit(1);
    }
    const char* charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?/";
    for (int i = 0; i < length; ++i) {
        result[i] = charset[rand() % strlen(charset)];
    }
    result[length] = '\0';
    return result;
}

int main() {
    srand(time(NULL));
    char* password = generate_random_string(MAX_PASS_LENGTH);
    printf("Password: %s\n", password);

    int score = 0;
    int length = strlen(password);
    if (length < MIN_PASS_LENGTH) {
        printf("Password is too short\n");
        return 1;
    }

    bool contains_uppercase = false;
    bool contains_lowercase = false;
    bool contains_digit = false;
    bool contains_special = false;

    for (int i = 0; i < length; ++i) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            contains_lowercase = true;
        } else if (isdigit(c)) {
            contains_digit = true;
        } else if (isspace(c) || ispunct(c)) {
            contains_special = true;
        }
    }

    if (contains_uppercase) {
        score += 1;
    }
    if (contains_lowercase) {
        score += 1;
    }
    if (contains_digit) {
        score += 1;
    }
    if (contains_special) {
        score += 1;
    }

    printf("Password strength: %d\n", score);

    free(password);
    return 0;
}