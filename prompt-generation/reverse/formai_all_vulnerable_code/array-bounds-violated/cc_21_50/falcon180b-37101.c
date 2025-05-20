//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Prompt user for password
    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    length = strlen(password);

    // Remove newline character
    password[--length] = '\0';

    // Check password strength
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            has_uppercase |= isupper(c);
            has_lowercase |= islower(c);
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '"' || c == '\'' || c == ',' || c == '.' || c == '/' || c == '? ') {
            has_special_char = 1;
        }
    }

    // Print password strength
    printf("Password strength: ");
    if (length < 8) {
        printf("Weak\n");
    } else if (length >= 8 && length < 12) {
        if (has_uppercase && has_lowercase && has_number) {
            printf("Moderate\n");
        } else {
            printf("Weak\n");
        }
    } else if (length >= 12 && (has_uppercase || has_lowercase || has_number || has_special_char)) {
        printf("Strong\n");
    } else {
        printf("Very strong\n");
    }

    return 0;
}