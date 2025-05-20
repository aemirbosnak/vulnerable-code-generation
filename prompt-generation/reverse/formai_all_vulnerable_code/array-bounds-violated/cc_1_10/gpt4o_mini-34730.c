//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int check_length(const char* password) {
    return strlen(password) >= 8;
}

int check_special_chars(const char* password) {
    const char* special_chars = "!@#$%^&*()-_+=<>?,.";
    for (const char* p = password; *p != '\0'; p++) {
        if (strchr(special_chars, *p) != NULL) {
            return 1;
        }
    }
    return 0;
}

int check_uppercase(const char* password) {
    for (const char* p = password; *p != '\0'; p++) {
        if (isupper((unsigned char)*p)) {
            return 1;
        }
    }
    return 0;
}

int check_lowercase(const char* password) {
    for (const char* p = password; *p != '\0'; p++) {
        if (islower((unsigned char)*p)) {
            return 1;
        }
    }
    return 0;
}

int check_numeric(const char* password) {
    for (const char* p = password; *p != '\0'; p++) {
        if (isdigit((unsigned char)*p)) {
            return 1;
        }
    }
    return 0;
}

void evaluate_password_strength(const char* password) {
    int length_ok = check_length(password);
    int special_ok = check_special_chars(password);
    int upper_ok = check_uppercase(password);
    int lower_ok = check_lowercase(password);
    int numeric_ok = check_numeric(password);

    int strength_score = length_ok + special_ok + upper_ok + lower_ok + numeric_ok;

    printf("Password Strength Evaluation:\n");
    printf("-------------------------------\n");
    printf("Length (>=8): %s\n", length_ok ? "OK" : "Too Short!");
    printf("Special Characters: %s\n", special_ok ? "Present" : "Missing!");
    printf("Uppercase Letters: %s\n", upper_ok ? "Present" : "Missing!");
    printf("Lowercase Letters: %s\n", lower_ok ? "Present" : "Missing!");
    printf("Numeric Digits: %s\n", numeric_ok ? "Present" : "Missing!");
    
    switch (strength_score) {
        case 0:
        case 1:
            printf("Password Strength: Very Weak\n");
            break;
        case 2:
            printf("Password Strength: Weak\n");
            break;
        case 3:
            printf("Password Strength: Medium\n");
            break;
        case 4:
            printf("Password Strength: Strong\n");
            break;
        case 5:
            printf("Password Strength: Very Strong\n");
            break;
        default:
            printf("Password Strength: Undefined\n");
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password for strength evaluation: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    
    // Remove newline character from input if present
    size_t len = strlen(password);
    if (password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }

    evaluate_password_strength(password);
    
    return 0;
}