//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void get_random_chars(char* password, int num_chars) {
    char* char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+={}[]\\|;:'\",.<>/?`~";
    int set_size = strlen(char_set);
    for (int i = 0; i < num_chars; i++) {
        int index = rand() % set_size;
        password[i] = char_set[index];
    }
}

int main() {
    int password_length = 0;
    while (password_length < 8) {
        printf("Enter desired password length (must be at least 8 characters): ");
        scanf("%d", &password_length);
    }

    char password[password_length + 1];
    password[password_length] = '\0';

    srand(time(NULL));

    // Generate random letters and numbers
    int num_chars = password_length / 2;
    get_random_chars(password, num_chars);

    // Generate random symbols
    int num_symbols = password_length - num_chars;
    get_random_chars(password + num_chars, num_symbols);

    // Shuffle the password
    for (int i = password_length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Ensure at least one uppercase letter and one digit
    int has_uppercase = 0;
    int has_digit = 0;
    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (isupper(password[i])) {
            has_uppercase = 1;
        }
    }

    if (!has_uppercase) {
        // Replace a random lowercase letter with an uppercase letter
        int index = rand() % num_chars;
        while (!islower(password[index])) {
            index = rand() % num_chars;
        }
        password[index] = toupper(password[index]);
    }

    if (!has_digit) {
        // Replace a random symbol with a digit
        int index = num_chars + rand() % num_symbols;
        while (!isdigit(password[index])) {
            index = num_chars + rand() % num_symbols;
        }
        password[index] = rand() % 10 + '0';
    }

    printf("Your password is: %s\n", password);

    return 0;
}