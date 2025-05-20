//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length, score = 0;

    printf("Enter the password: ");
    fgets(password, MAX_LENGTH, stdin);

    // remove newline character
    length = strlen(password);
    if (password[length - 1] == '\n') {
        password[--length] = '\0';
    }

    length = strlen(password);

    // check length
    if (length < 8) {
        printf("Password is too short\n");
        return 1;
    }

    // check for special characters
    int special_chars = 0;
    char special_chars_str[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (int i = 0; i < length; i++) {
        if (strchr(special_chars_str, tolower(password[i]))) {
            special_chars++;
        }
    }

    if (special_chars == 0) {
        printf("Password must contain at least one special character\n");
        return 1;
    }

    // check for uppercase and lowercase letters
    int has_upper = 0;
    int has_lower = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_upper = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        }
    }

    if (!has_upper ||!has_lower) {
        printf("Password must contain at least one uppercase and one lowercase letter\n");
        return 1;
    }

    // check for numbers
    int has_numbers = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_numbers = 1;
            break;
        }
    }

    if (!has_numbers) {
        printf("Password must contain at least one number\n");
        return 1;
    }

    // calculate score
    int num_special_chars = length - special_chars;
    int num_lower_case = length - has_lower;
    int num_upper_case = length - has_upper;
    int num_numbers = length - has_numbers;

    score = (num_special_chars * 3) + (num_lower_case * 2) + (num_upper_case * 2) + (num_numbers * 2);

    // print score
    if (score < 10) {
        printf("Password is very weak\n");
    } else if (score < 20) {
        printf("Password is weak\n");
    } else if (score < 30) {
        printf("Password is moderate\n");
    } else if (score < 40) {
        printf("Password is strong\n");
    } else {
        printf("Password is very strong\n");
    }

    return 0;
}