//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length, i;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for minimum length
    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for special characters
    int has_special = 0;
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }
    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // Check for uppercase and lowercase letters
    int has_uppercase = 0;
    int has_lowercase = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        }
    }
    if (!has_uppercase ||!has_lowercase) {
        printf("Password must contain at least one uppercase and one lowercase letter.\n");
        return 0;
    }

    // Check for numbers
    int has_number = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }
    if (!has_number) {
        printf("Password must contain at least one number.\n");
        return 0;
    }

    // Check for consecutive characters
    int has_consecutive = 0;
    for (i = 0; i < length - 1; i++) {
        if (password[i] == password[i + 1]) {
            has_consecutive = 1;
            break;
        }
    }
    if (has_consecutive) {
        printf("Password must not contain consecutive characters.\n");
        return 0;
    }

    // Check for common words
    char *common_words[] = {"password", "admin", "123456", "qwerty", "letmein"};
    int num_common_words = sizeof(common_words) / sizeof(common_words[0]);
    for (i = 0; i < num_common_words; i++) {
        if (strcmp(password, common_words[i]) == 0) {
            printf("Password must not be a common word or phrase.\n");
            return 0;
        }
    }

    printf("Password is strong.\n");
    return 0;
}