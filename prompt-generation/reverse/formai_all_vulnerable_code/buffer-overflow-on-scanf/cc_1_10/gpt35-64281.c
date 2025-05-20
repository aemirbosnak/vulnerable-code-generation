//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool has_uppercase(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (password[i] >= 65 && password[i] <= 90) {
            return true;
        }
    }
    return false;
}

bool has_lowercase(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (password[i] >= 97 && password[i] <= 122) {
            return true;
        }
    }
    return false;
}

bool has_digit(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (password[i] >= 48 && password[i] <= 57) {
            return true;
        }
    }
    return false;
}

bool has_special(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (!(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 97 && password[i] <= 122)) {
            return true;
        }
    }
    return false;
}

int main() {
    char password[100];
    printf("Enter password to check its strength: ");
    scanf("%s", password);
    bool is_strong = has_uppercase(password) && has_lowercase(password) && has_digit(password) && has_special(password);
    if (is_strong) {
        printf("The password is strong!\n");
    } else {
        printf("The password is not strong!\n");
        printf("Hints to make a strong password:\n");
        printf("- Use at least 8 characters\n");
        printf("- Use a combination of uppercase and lowercase letters\n");
        printf("- Use at least one digit and one special character\n");
    }
    return 0;
}