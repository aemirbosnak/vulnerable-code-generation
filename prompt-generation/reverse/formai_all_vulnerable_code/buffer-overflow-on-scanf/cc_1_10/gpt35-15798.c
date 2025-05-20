//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool validate_age(char *age_input) {
    int age = atoi(age_input);
    if (age < 0 || age > 120) {
        return false;
    }
    return true;
}

bool validate_email(char *email_input) {
    char *at_position = strchr(email_input, '@');
    char *dot_position = strchr(email_input, '.');
    if (at_position == NULL || dot_position == NULL) {
        return false;
    }
    if (dot_position < at_position) {
        return false;
    }
    return true;
}

bool validate_password(char *password_input) {
    int length = strlen(password_input);
    if (length < 8) {
        return false;
    }
    bool contains_upper = false;
    bool contains_lower = false;
    bool contains_digit = false;
    for (int i = 0; i < length; i++) {
        if (isupper(password_input[i])) {
            contains_upper = true;
        } else if (islower(password_input[i])) {
            contains_lower = true;
        } else if (isdigit(password_input[i])) {
            contains_digit = true;
        } else {
            return false;
        }
    }
    if (!contains_upper || !contains_lower || !contains_digit) {
        return false;
    }
    return true;
}

int main() {
    char age_input[10];
    char email_input[100];
    char password_input[100];
    printf("Enter your age: ");
    scanf("%s", age_input);
    if (validate_age(age_input)) {
        printf("Age is valid\n");
    } else {
        printf("Age is not valid\n");
    }
    printf("Enter your email: ");
    scanf("%s", email_input);
    if (validate_email(email_input)) {
        printf("Email is valid\n");
    } else {
        printf("Email is not valid\n");
    }
    printf("Enter your password: ");
    scanf("%s", password_input);
    if (validate_password(password_input)) {
        printf("Password is valid\n");
    } else {
        printf("Password is not valid\n");
    }
    return 0;
}