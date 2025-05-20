//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length, has_uppercase, has_lowercase, has_digit, has_special_char, strength;
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);
    has_uppercase = has_lowercase = has_digit = has_special_char = 0;
    
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        }
        else {
            has_special_char = 1;
        }
    }
    
    if (length < 8) {
        printf("Password must be at least 8 characters long\n");
        strength = 0;
    }
    else if (!has_uppercase) {
        printf("Password must contain at least one uppercase letter\n");
        strength = 1;
    }
    else if (!has_lowercase) {
        printf("Password must contain at least one lowercase letter\n");
        strength = 1;
    }
    else if (!has_digit) {
        printf("Password must contain at least one digit\n");
        strength = 1;
    }
    else if (!has_special_char) {
        printf("Password must contain at least one special character\n");
        strength = 1;
    }
    else {
        strength = 2;
    }
    
    switch (strength) {
        case 0:
            printf("Password strength: Weak\n");
            break;
        case 1:
            printf("Password strength: Medium\n");
            break;
        case 2:
            printf("Password strength: Strong\n");
            break;
    }
    
    return 0;
}