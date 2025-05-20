//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

int is_valid_password(char *password);
int check_password_strength(char *password);

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        int strength = check_password_strength(password);
        printf("Password strength: %d\n", strength);
    } else {
        printf("Invalid password.\n");
    }

    return 0;
}

int is_valid_password(char *password) {
    int length = strlen(password);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            return 0;
        }
    }

    return 1;
}

int check_password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (!isalnum(password[i])) {
            has_special_char = 1;
        }
    }

    int strength = 0;

    if (length >= 12) {
        strength++;
    }

    if (has_uppercase && has_lowercase) {
        strength++;
    }

    if (has_number && has_special_char) {
        strength++;
    }

    if (has_uppercase && has_lowercase && has_number && has_special_char) {
        strength++;
    }

    return strength;
}