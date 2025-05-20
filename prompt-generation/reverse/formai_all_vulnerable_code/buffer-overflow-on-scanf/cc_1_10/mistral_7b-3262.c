//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

void generate_random_string(char *str, int length) {
    int i;
    for (i = 0; i < length; i++) {
        str[i] = rand() % 94 + 'A' - 10; // Generate random characters excluding spaces and special characters
    }
    str[length] = '\0';
}

void transform_password(char *password, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        for (j = i + 1; j < length; j++) {
            if (abs(password[i] - password[j]) == 1) {
                char temp = password[i];
                password[i] = password[j];
                password[j] = temp;
            }
        }
    }
    for (i = 0; i < length; i++) {
        password[i] = toupper(password[i]);
    }
}

void check_password_strength(char *password, int length) {
    int has_digit = 0, has_upper = 0, has_lower = 0, has_special = 0;

    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        }
        if (isupper(password[i])) {
            has_upper = 1;
        }
        if (islower(password[i])) {
            has_lower = 1;
        }
        if (isdigit(password[i]) || isalpha(password[i]) || strchr("!@#$%^&*()_+-=[]{}|;:,.<>?", password[i])) {
            has_special = 1;
        }
    }

    printf("Password strength:\n");
    if (!has_digit || !has_upper || !has_lower || !has_special) {
        printf("Weak\n");
    } else if (length < MIN_LENGTH) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }
}

int main() {
    srand(time(NULL));

    char user_input[10];
    int length;

    printf("Enter a base password (minimum %d characters, maximum %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%s", user_input);
    length = strlen(user_input);

    if (length < MIN_LENGTH) {
        printf("Error: password must be at least %d characters long.\n", MIN_LENGTH);
        return 1;
    }

    char password[MAX_LENGTH];
    generate_random_string(password, length);
    strcpy(password, user_input);

    transform_password(password, length);

    check_password_strength(password, length);

    printf("Generated password: %s\n", password);

    return 0;
}