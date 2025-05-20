//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

int has_uppercase(const char *password) {
    while (*password) {
        if (isupper(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

int has_lowercase(const char *password) {
    while (*password) {
        if (islower(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

int has_digit(const char *password) {
    while (*password) {
        if (isdigit(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

int has_special_character(const char *password) {
    const char *special_chars = "!@#$%^&*()-_=+[]{}|;:'\",.<>?/`~";
    while (*password) {
        if (strchr(special_chars, *password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

int is_valid_length(const char *password) {
    int length = strlen(password);
    return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

void check_password_strength(const char *password) {
    if (!is_valid_length(password)) {
        printf("Password must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        return;
    }
    
    int upper = has_uppercase(password);
    int lower = has_lowercase(password);
    int digit = has_digit(password);
    int special = has_special_character(password);

    int strength_score = upper + lower + digit + special;

    printf("Password strength evaluation:\n");
    if (strength_score == 4) {
        printf("Your password is strong.\n");
    } else if (strength_score == 3) {
        printf("Your password is medium.\n");
    } else {
        printf("Your password is weak.\n");
    }
}

void prompt_for_password() {
    char password[256];
    
    printf("Please enter your password (8-20 characters): ");
    
    if (fgets(password, sizeof(password), stdin) != NULL) {
        // Remove newline character if present
        password[strcspn(password, "\n")] = 0;
        
        check_password_strength(password);
    } else {
        printf("Input error, please try again.\n");
    }
}

int main() {
    printf("Welcome to the Password Strength Checker program!\n");
    while (1) {
        prompt_for_password();
        char choice;
        printf("Do you want to evaluate another password? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // clear newline character from buffer
        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }
    printf("Thank you for using the Password Strength Checker. Goodbye!\n");
    return 0;
}