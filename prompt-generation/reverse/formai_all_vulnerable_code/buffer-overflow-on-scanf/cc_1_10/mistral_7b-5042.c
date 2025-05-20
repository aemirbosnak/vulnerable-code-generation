//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHAR_COUNT 26
#define NUM_DIGITS 10
#define SYMBOL_COUNT 32
#define MIN_LENGTH 8
#define MAX_LENGTH 20

const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";
const char symbols[] = "!@#$%^&*()_+-=[]{}|\\:;\"<>,.?/~`";

int main() {
    int length, use_lowercase, use_uppercase, use_digits, use_symbols;
    char password[MAX_LENGTH + 1];
    char password_chars[CHAR_COUNT + NUM_DIGITS + SYMBOL_COUNT];

    printf("Welcome to the Grateful Password Generator!\n");
    printf("This program will generate a secure password for you.\n");
    printf("How long would you like your password to be? (minimum %d, maximum %d)\n", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);

    printf("Would you like to include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &use_lowercase);
    if (use_lowercase) {
        strcat(password_chars, lowercase);
    }

    printf("Would you like to include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &use_uppercase);
    if (use_uppercase) {
        strcat(password_chars, uppercase);
    }

    printf("Would you like to include digits? (1 for yes, 0 for no): ");
    scanf("%d", &use_digits);
    if (use_digits) {
        strcat(password_chars, digits);
    }

    printf("Would you like to include symbols? (1 for yes, 0 for no): ");
    scanf("%d", &use_symbols);
    if (use_symbols) {
        strcat(password_chars, symbols);
    }

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int random_index = rand() % (strlen(password_chars) - 1);
        password[i] = password_chars[random_index];
    }

    password[length] = '\0';

    printf("Your new password is: %s\n", password);

    return 0;
}