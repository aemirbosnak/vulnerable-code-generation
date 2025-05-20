//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH_MIN 8
#define PASSWORD_LENGTH_MAX 20
#define PASSWORD_DIGIT_MIN 1
#define PASSWORD_UPPER_MIN 1
#define PASSWORD_LOWER_MIN 1
#define PASSWORD_SPECIAL_MIN 1
#define PASSWORD_SPECIAL_CHARS "!@#$%^&*"

/**
 * Function to check if a password meets the minimum requirements.
 * Returns 1 if the password is valid, 0 if it is invalid.
 */
int is_password_valid(char* password) {
    int length = strlen(password);
    int digit_count = 0;
    int upper_count = 0;
    int lower_count = 0;
    int special_count = 0;
    
    if (length < PASSWORD_LENGTH_MIN || length > PASSWORD_LENGTH_MAX) {
        return 0;
    }
    
    for (int i=0; i<length; i++) {
        char c = password[i];
        
        if (isdigit(c)) {
            digit_count++;
        } else if (isupper(c)) {
            upper_count++;
        } else if (islower(c)) {
            lower_count++;
        } else if (strchr(PASSWORD_SPECIAL_CHARS, c) != NULL) {
            special_count++;
        }
    }
    
    if (digit_count < PASSWORD_DIGIT_MIN 
        || upper_count < PASSWORD_UPPER_MIN 
        || lower_count < PASSWORD_LOWER_MIN 
        || special_count < PASSWORD_SPECIAL_MIN) {
        return 0;
    }
    
    return 1;
}

/**
 * Main function that reads in a password and checks its strength.
 */
int main() {
    char password[100];
    printf("Enter a password (between %d and %d characters) containing at least %d digit, %d uppercase letter, %d lowercase letter, and %d special character\n", PASSWORD_LENGTH_MIN, PASSWORD_LENGTH_MAX, PASSWORD_DIGIT_MIN, PASSWORD_UPPER_MIN, PASSWORD_LOWER_MIN, PASSWORD_SPECIAL_MIN);
    scanf("%s", password);
    
    if (is_password_valid(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak. Please try again.\n");
    }
    
    return 0;
}