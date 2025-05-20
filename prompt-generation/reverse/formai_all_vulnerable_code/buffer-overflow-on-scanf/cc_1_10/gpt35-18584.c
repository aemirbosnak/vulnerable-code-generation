//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

// Configuration variables
int min_password_length = 8; // minimum length of password
int max_password_length = 20; // maximum length of password
int min_num_digits = 1; // minimum number of digits required in password
int min_num_uppercase = 1; // minimum number of uppercase letters required in password
int min_num_lowercase = 1; // minimum number of lowercase letters required in password

// function to check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// function to check if a character is an uppercase letter
int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// function to check if a character is a lowercase letter
int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// function to check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);
    int num_digits = 0;
    int num_uppercase = 0;
    int num_lowercase = 0;

    // count the number of digits, uppercase letters, and lowercase letters in the password
    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            num_digits++;
        } else if (is_uppercase(password[i])) {
            num_uppercase++;
        } else if (is_lowercase(password[i])) {
            num_lowercase++;
        }
    }

    // check if the password meets the minimum requirements
    if (length < min_password_length) {
        return -1; // password too short
    } else if (length > max_password_length) {
        return -2; // password too long
    } else if (num_digits < min_num_digits) {
        return -3; // not enough digits
    } else if (num_uppercase < min_num_uppercase) {
        return -4; // not enough uppercase letters
    } else if (num_lowercase < min_num_lowercase) {
        return -5; // not enough lowercase letters
    } else {
        return 0; // password meets minimum requirements
    }
}

int main() {
    char password[100];
    printf("Enter the password to check: ");
    scanf("%s", password);

    int result = check_password_strength(password);

    switch (result) {
        case -1:
            printf("Error: Password is too short.\n");
            break;
        case -2:
            printf("Error: Password is too long.\n");
            break;
        case -3:
            printf("Error: Password does not have enough digits.\n");
            break;
        case -4:
            printf("Error: Password does not have enough uppercase letters.\n");
            break;
        case -5:
            printf("Error: Password does not have enough lowercase letters.\n");
            break;
        case 0:
            printf("Password meets minimum requirements.\n");
            break;
    }

    return 0;
}