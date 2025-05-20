//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_special_char(char c) {
    return !is_upper(c) && !is_lower(c) && !is_digit(c);
}

int calculate_entropy(char* password, int length) {
    int num_upper = 0, num_lower = 0, num_digit = 0, num_special = 0;

    for (int i = 0; i < length; i++) {
        if (is_upper(password[i])) {
            num_upper++;
        } else if (is_lower(password[i])) {
            num_lower++;
        } else if (is_digit(password[i])) {
            num_digit++;
        } else if (is_special_char(password[i])) {
            num_special++;
        }
    }

    int entropy = 0;

    // count number of unique characters
    char used_chars[length];
    int num_used_chars = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];
        int is_used = 0;

        for (int j = 0; j < num_used_chars; j++) {
            if (used_chars[j] == c) {
                is_used = 1;
                break;
            }
        }

        if (!is_used) {
            used_chars[num_used_chars] = c;
            num_used_chars++;
        }
    }

    entropy += num_used_chars;

    // add entropy for each character category
    if (num_upper > 0) {
        entropy += 26;
    }

    if (num_lower > 0) {
        entropy += 26;
    }

    if (num_digit > 0) {
        entropy += 10;
    }

    if (num_special > 0) {
        entropy += 32;
    }

    return entropy;
}

int main() {
    char password[100];

    // read password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // check password strength
    int length = strlen(password);
    int entropy = calculate_entropy(password, length);

    if (length < 8) {
        printf("Password is too short!\n");
    } else if (entropy < 64) {
        printf("Password is too weak!\n");
    } else {
        printf("Password is strong enough!\n");
    }

    return 0;
}