//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

void print_password_strength(char *password) {
    int length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    if (length < 8) {
        printf("Weak\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                uppercase_count++;
            } else {
                lowercase_count++;
            }
        } else if (isdigit(c)) {
            digit_count++;
        } else if (!isalpha(c) &&!isdigit(c)) {
            special_count++;
        }
    }

    int total_count = uppercase_count + lowercase_count + digit_count + special_count;
    int strength_level = (total_count * 100) / (4 * length);

    if (strength_level < 25) {
        printf("Weak\n");
    } else if (strength_level < 50) {
        printf("Moderate\n");
    } else if (strength_level < 75) {
        printf("Strong\n");
    } else {
        printf("Very Strong\n");
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    print_password_strength(password);

    return 0;
}