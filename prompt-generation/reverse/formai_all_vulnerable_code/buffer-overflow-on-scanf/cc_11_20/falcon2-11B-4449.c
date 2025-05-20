//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: authentic
#include<stdio.h>
#include<string.h>

// Function to check the password strength
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    
    // Check for length
    if(length < 6) {
        printf("Password length is too short\n");
        return 0;
    }
    
    // Check for uppercase letter
    int hasUppercase = 0;
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }
    if(!hasUppercase) {
        printf("Password must contain at least one uppercase letter\n");
        return 0;
    }
    
    // Check for lowercase letter
    int hasLowercase = 0;
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }
    if(!hasLowercase) {
        printf("Password must contain at least one lowercase letter\n");
        return 0;
    }
    
    // Check for digit
    int hasDigit = 0;
    for(int i = 0; i < length; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }
    if(!hasDigit) {
        printf("Password must contain at least one digit\n");
        return 0;
    }
    
    // Check for special character
    int hasSpecialChar = 0;
    for(int i = 0; i < length; i++) {
        if((password[i] >= '!' && password[i] <= '@') ||
           (password[i] >= '#' && password[i] <= '^') ||
           (password[i] >= '$' && password[i] <= '`') ||
           (password[i] >= '{' && password[i] <= '~')) {
            hasSpecialChar = 1;
            break;
        }
    }
    if(!hasSpecialChar) {
        printf("Password must contain at least one special character\n");
        return 0;
    }
    
    return 1;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    if(checkPasswordStrength(password)) {
        printf("Your password is strong\n");
    } else {
        printf("Your password is weak\n");
    }
    return 0;
}