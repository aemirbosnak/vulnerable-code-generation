//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check strength of password
bool check_password_strength(char password[])
{
    int len = strlen(password);
    
    // Check for minimum length
    if (len < 8) {
        printf("Error: Password should be at least 8 characters long\n");
        return false;
    }

    // Check for uppercase letters
    bool has_uppercase = false;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = true;
            break;
        }
    }
    if (!has_uppercase) {
        printf("Error: Password should contain at least 1 uppercase letter\n");
        return false;
    }

    // Check for lowercase letters
    bool has_lowercase = false;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = true;
            break;
        }
    }
    if (!has_lowercase) {
        printf("Error: Password should contain at least 1 lowercase letter\n");
        return false;
    }

    // Check for digits
    bool has_digit = false;
    for (int i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = true;
            break;
        }
    }
    if (!has_digit) {
        printf("Error: Password should contain at least 1 digit\n");
        return false;
    }
    
    return true;
}

int main()
{
    char password[100];
    printf("Enter password: ");
    scanf("%s", password);
    if (check_password_strength(password)) {
        printf("Password is strong\n");
    }
    
    return 0;
}