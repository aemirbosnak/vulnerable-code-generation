//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if a character is a letter or a digit
int is_valid_character(char c) {
    return (isalpha(c) || isdigit(c));
}

// Function to count the number of valid characters in a password
int count_valid_characters(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_valid_character(password[i])) {
            count++;
        }
    }
    return count;
}

// Function to check the strength of a password
int check_password_strength(char* password) {
    int length = strlen(password);
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int special_character_count = 0;

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lowercase_count++;
            } else if (isupper(password[i])) {
                uppercase_count++;
            }
        } else if (isdigit(password[i])) {
            digit_count++;
        } else {
            special_character_count++;
        }
    }

    int valid_characters_count = count_valid_characters(password);

    if (length < 8) {
        return 1; // Password is too short
    } else if (valid_characters_count < 3) {
        return 2; // Password needs at least one lowercase letter, one uppercase letter, and one digit
    } else if (valid_characters_count < 5) {
        return 3; // Password needs at least one lowercase letter, one uppercase letter, one digit, and one special character
    } else {
        return 4; // Password is strong
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch (strength) {
        case 1:
            printf("Password is too short.\n");
            break;
        case 2:
            printf("Password needs at least one lowercase letter, one uppercase letter, and one digit.\n");
            break;
        case 3:
            printf("Password needs at least one lowercase letter, one uppercase letter, one digit, and one special character.\n");
            break;
        case 4:
            printf("Password is strong.\n");
            break;
    }

    return 0;
}