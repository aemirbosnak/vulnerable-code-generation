//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define WEAK 0
#define MODERATE 1
#define STRONG 2
#define VERY_STRONG 3

typedef struct {
    int length;
    int has_digit;
    int has_uppercase;
    int has_lowercase;
    int has_special_char;
} password_strength;

char *special_chars = "!@#$%^&*()_+-=[]{}|;:,.<>/?`~";

void print_strength(password_strength pwd) {
    switch (pwd.length) {
        case MIN_LENGTH:
            printf("Weak\n");
            break;
        case MIN_LENGTH + 1:
            if (pwd.has_digit && pwd.has_lowercase && pwd.has_uppercase) {
                printf("Moderate\n");
            } else {
                printf("Week\n");
            }
            break;
        default:
            if (pwd.has_digit && pwd.has_lowercase && pwd.has_uppercase && pwd.has_special_char) {
                printf("Very Strong\n");
            } else {
                printf("Strong\n");
            }
            break;
    }
}

password_strength check_password(char *password) {
    password_strength pwd;
    pwd.length = strlen(password);

    for (int i = 0; i < pwd.length; i++) {
        if (isdigit(password[i])) {
            pwd.has_digit = 1;
        }

        if (isupper(password[i])) {
            pwd.has_uppercase = 1;
        }

        if (islower(password[i])) {
            pwd.has_lowercase = 1;
        }

        if (strchr(special_chars, password[i])) {
            pwd.has_special_char = 1;
        }
    }

    return pwd;
}

int main() {
    char password[MIN_LENGTH];
    srand(time(NULL));

    printf("Enter a password or leave it empty to generate a random one: ");
    fgets(password, sizeof(password), stdin);

    if (strlen(password) == 0) {
        for (int i = 0; i < MIN_LENGTH; i++) {
            password[i] = special_chars[rand() % strlen(special_chars)];
        }
        password[MIN_LENGTH] = '\0';
    }

    password_strength checked_password = check_password(password);

    printf("Your password is %d strength:\n", checked_password.length > MIN_LENGTH ? checked_password.length - MIN_LENGTH + WEAK : WEAK);
    print_strength(checked_password);

    return 0;
}