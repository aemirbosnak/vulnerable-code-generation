//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, i;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);
    
    // Check for minimum length
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    
    // Check for uppercase letters
    int has_uppercase = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    
    // Check for lowercase letters
    int has_lowercase = 0;
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    
    // Check for digits
    int has_digits = 0;
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digits = 1;
            break;
        }
    }
    if (!has_digits) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    
    // Check for special characters
    int has_special = 0;
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }
    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }
    
    // Check for common words
    char common_words[][20] = {"password", "123456", "qwerty", "iloveyou", "admin", "welcome", "monkey", "letmein", "dragon", "sunshine"};
    int num_words = sizeof(common_words)/sizeof(common_words[0]);
    for (i = 0; i < num_words; i++) {
        if (strstr(password, common_words[i])) {
            printf("Password contains a common word. Please choose a stronger password.\n");
            return 0;
        }
    }
    
    printf("Password is strong.\n");
    return 0;
}