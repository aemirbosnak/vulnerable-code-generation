//FormAI DATASET v1.0 Category: Text processing ; Style: secure
#include <stdio.h>
#include <string.h>

// function to check if a password is strong
int is_password_strong(char password[]) {
    // length of the password must be at least 8 characters
    int length = strlen(password);
    if (length < 8) {
        return 0;
    }
    
    // the password must contain a lowercase letter, an uppercase letter and a digit
    int has_lowercase = 0, has_uppercase = 0, has_digit = 0;
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (c >= 'a' && c <= 'z') {
            has_lowercase = 1;
        } else if (c >= 'A' && c <= 'Z') {
            has_uppercase = 1;
        } else if (c >= '0' && c <= '9') {
            has_digit = 1;
        }
    }
    if (!(has_lowercase && has_uppercase && has_digit)) {
        return 0;
    }
    
    // the password must not contain common words or patterns
    char common_patterns[5][10] = {"123", "password", "qwerty", "admin", "letmein"};
    for (int i = 0; i < 5; i++) {
        if (strstr(password, common_patterns[i]) != NULL) {
            return 0;
        }
    }
    
    // if the password passes all the tests, it is considered strong
    return 1;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);
    if (is_password_strong(password)) {
        printf("The password is strong!\n");
    } else {
        printf("The password is weak.\n");
    }
    return 0;
}