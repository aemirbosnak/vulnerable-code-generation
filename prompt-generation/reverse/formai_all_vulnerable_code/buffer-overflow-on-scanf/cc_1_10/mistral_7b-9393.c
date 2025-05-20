//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 32
#define MIN_LENGTH 8

const char *special_chars = "!@#$%^&*()_+-={}[]|\\:\"<>,.?/~`";
const char *lowercase_letters = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *digits = "0123456789";

void random_password(char *password, size_t length) {
    size_t i;
    for (i = 0; i < length; i++) {
        if (i % 4 == 0) {
            // Add a random character from each group with given probabilities
            int random = rand() % 100;
            if (random < 33) {
                password[i] = special_chars[rand() % strlen(special_chars)];
            } else if (random < 67) {
                password[i] = lowercase_letters[rand() % strlen(lowercase_letters)];
                random %= strlen(lowercase_letters);
            } else if (random < 91) {
                password[i] = uppercase_letters[rand() % strlen(uppercase_letters)];
                random %= strlen(uppercase_letters);
            } else {
                password[i] = digits[rand() % strlen(digits)];
                random %= strlen(digits);
            }
        } else {
            // Add a random character from any group
            int random = rand() % 131; // Total length of all strings
            if (random < strlen(special_chars)) {
                password[i] = special_chars[random];
            } else if (random < strlen(special_chars) + strlen(lowercase_letters)) {
                password[i] = lowercase_letters[random % strlen(lowercase_letters)];
            } else if (random < strlen(special_chars) + strlen(lowercase_letters) + strlen(uppercase_letters)) {
                password[i] = uppercase_letters[random % strlen(uppercase_letters)];
            } else {
                password[i] = digits[random % strlen(digits)];
            }
        }
    }

    password[length] = '\0'; // Null terminate the password
}

int main(void) {
    srand(time(NULL));

    size_t length;
    printf("Enter password length (between %d and %d): ", MIN_LENGTH, LENGTH);
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > LENGTH) {
        printf("Invalid length! Exiting...\n");
        return EXIT_FAILURE;
    }

    char password[LENGTH + 1];
    random_password(password, length);

    printf("Generated password: %s\n", password);

    return EXIT_SUCCESS;
}