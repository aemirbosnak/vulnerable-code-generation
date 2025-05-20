//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: configurable
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void) {
    char password[100];
    bool has_lowercase = false;
    bool has_uppercase = false;
    bool has_digit = false;
    bool has_special_char = false;
    int length;
    bool is_strong = false;
    
    // Ask user to input password
    printf("Enter a password: ");
    fgets(password, 100, stdin);
    
    // Remove newline character if it's included
    length = strlen(password);
    if (password[length-1] == '\n') {
        password[length-1] = '\0';
        length--;
    }
    
    // Check password strength
    for (int i = 0; i < length; i++) {
        char current_char = password[i];
        
        if (islower(current_char)) {
            has_lowercase = true;
        } else if (isupper(current_char)) {
            has_uppercase = true;
        } else if (isdigit(current_char)) {
            has_digit = true;
        } else if (ispunct(current_char)) {
            has_special_char = true;
        }
    }
    
    // Determine password strength
    if (length >= 8 && has_lowercase && has_uppercase && has_digit && has_special_char) {
        is_strong = true;
    }
    
    // Output password strength
    if (is_strong) {
        printf("The password is strong.\n");
    } else {
        printf("The password is weak.\n");
        printf("It must be at least 8 characters long and contain at least one lowercase letter, one uppercase letter, one digit, and one special character.\n");
    }
    
    return 0;
}