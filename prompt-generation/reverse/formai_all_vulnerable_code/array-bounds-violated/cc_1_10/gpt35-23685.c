//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

int check_char_types(char* password) {
    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_special = 1;
        }
    }
    return has_uppercase + has_lowercase + has_digit + has_special;
}

int check_length(char* password) {
    int length = strlen(password);
    return (length >= MIN_LENGTH && length <= MAX_LENGTH);
}

int check_substring(char* password) {
    int length = strlen(password), is_valid = 1;
    for (int i = 0; i < length-3; i++) {
        char substr[4];
        memcpy(substr, password+i, 4);
        substr[4] = '\0';
        if (strstr(password+i+1, substr) != NULL) {
            is_valid = 0;
            break;
        }
    }
    return is_valid;
}

int main() {
    char password[MAX_LENGTH+1];
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH+1, stdin);
    password[strcspn(password, "\n")] = '\0'; // remove trailing newline
    
    int char_types = check_char_types(password);
    int length_valid = check_length(password);
    int substring_valid = check_substring(password);
    
    if (char_types < 4 || !length_valid || !substring_valid) {
        printf("Invalid password.\n");
        if (char_types < 4) printf("Your password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        if (!length_valid) printf("Your password must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        if (!substring_valid) printf("Your password must not contain any consecutive substrings of length 4 or more.\n");
    } else {
        printf("Valid password.\n");
    }
    
    return 0;
}