//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASE_COUNT 1
#define MIN_UPPER_CASE_COUNT 1
#define MIN_NUMBER_COUNT 1
#define MIN_SPECIAL_CHAR_COUNT 1

int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int lower_case_count = 0;
    int upper_case_count = 0;
    int number_count = 0;
    int special_char_count = 0;
    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lower_case_count++;
            } else if (isupper(password[i])) {
                upper_case_count++;
            }
        } else if (isdigit(password[i])) {
            number_count++;
        } else if (ispunct(password[i])) {
            special_char_count++;
        }
    }
    if (lower_case_count < MIN_LOWER_CASE_COUNT ||
        upper_case_count < MIN_UPPER_CASE_COUNT ||
        number_count < MIN_NUMBER_COUNT ||
        special_char_count < MIN_SPECIAL_CHAR_COUNT) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    if (is_valid_password(password)) {
        printf("Your password is strong enough.\n");
    } else {
        printf("Your password is not strong enough.\n");
    }
    return 0;
}