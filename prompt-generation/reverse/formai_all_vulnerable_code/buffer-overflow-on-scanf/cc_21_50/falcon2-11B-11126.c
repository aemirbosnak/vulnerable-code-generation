//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: irregular
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int len = strlen(password);
    if (len < 6) {
        printf("Password too short.\n");
        return 0;
    }

    int upper_count = 0;
    int lower_count = 0;
    int digit_count = 0;
    int special_count = 0;

    for (int i = 0; i < len; i++) {
        char c = password[i];

        if (isupper(c)) {
            upper_count++;
        } else if (islower(c)) {
            lower_count++;
        } else if (isdigit(c)) {
            digit_count++;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '=' || c == '+' || c == '{' || c == '}' || c == '[' || c == ']') {
            special_count++;
        }
    }

    if (upper_count < 1) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    if (lower_count < 1) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    if (digit_count < 1) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    if (special_count < 1) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Password strength: %d/%d/%d/%d.\n", upper_count, lower_count, digit_count, special_count);

    return 0;
}