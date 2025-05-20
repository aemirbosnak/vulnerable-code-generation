//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Function to generate a random uppercase letter */
char random_uppercase_letter() {
    return (char) (rand() % 26 + 65);
}

/* Function to generate a random lowercase letter */
char random_lowercase_letter() {
    return (char) (rand() % 26 + 97);
}

/* Function to generate a random digit */
char random_digit() {
    return (char) (rand() % 10 + 48);
}

/* Function to generate a random special character */
char random_special_character() {
    int random_special = rand() % 4;
    switch (random_special) {
        case 0:
            return '!';
        case 1:
            return '@';
        case 2:
            return '#';
        case 3:
            return '$';
        default:
            return '!';
    }
}

/* Function to generate a random password */
char* generate_password(int length) {
    static char password[100];
    int password_length = 0;
    int letters_count = 0, digits_count = 0, special_chars_count = 0;
    srand(time(NULL));
    while (password_length < length) {
        int type_of_char = rand() % 4;
        if (type_of_char == 0 && letters_count < 2) {
            password[password_length] = random_uppercase_letter();
            password_length++;
            letters_count++;
        }
        else if (type_of_char == 1 && letters_count < 2) {
            password[password_length] = random_lowercase_letter();
            password_length++;
            letters_count++;
        }
        else if (type_of_char == 2 && digits_count < 2) {
            password[password_length] = random_digit();
            password_length++;
            digits_count++;
        }
        else if (type_of_char == 3 && special_chars_count < 2) {
            password[password_length] = random_special_character();
            password_length++;
            special_chars_count++;
        }
        else {
            password[password_length] = random_uppercase_letter();
            password_length++;
            letters_count++;
        }
    }
    password[password_length] = '\0';
    return password;
}

/* Main program */
int main() {
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    while (length < 8 || length > 20) {
        printf("Password length should be between 8 and 20. Please try again.\n");
        printf("Enter the length of the password: ");
        scanf("%d", &length);
    }
    char* password = generate_password(length);
    printf("Your password is: %s\n", password);
    return 0;
}