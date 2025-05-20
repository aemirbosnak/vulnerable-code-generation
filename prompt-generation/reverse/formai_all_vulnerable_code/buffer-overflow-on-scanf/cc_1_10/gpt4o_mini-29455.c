//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declarations
int checkLength(char *password);
int checkUppercase(char *password);
int checkLowercase(char *password);
int checkDigit(char *password);
int checkSpecialChar(char *password);
void evaluatePassword(char *password);

int main() {
    char password[100];
    
    printf("🎉 Welcome to the Ultimate Password Strength Checker! 🎉\n\n");
    printf("Please enter your password (up to 99 characters): ");
    scanf("%s", password);
    
    evaluatePassword(password);
    
    return 0;
}

// Function to check password length
int checkLength(char *password) {
    return strlen(password) >= 8;
}

// Function to check for uppercase letters
int checkUppercase(char *password) {
    while (*password) {
        if (isupper(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check for lowercase letters
int checkLowercase(char *password) {
    while (*password) {
        if (islower(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check for digits
int checkDigit(char *password) {
    while (*password) {
        if (isdigit(*password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to check for special characters
int checkSpecialChar(char *password) {
    const char *specialChars = "!@#$%^&*()_+-=[]{}|;':\",.<>?/";
    while (*password) {
        if (strchr(specialChars, *password)) {
            return 1;
        }
        password++;
    }
    return 0;
}

// Function to evaluate password strength
void evaluatePassword(char *password) {
    int length = checkLength(password);
    int upper = checkUppercase(password);
    int lower = checkLowercase(password);
    int digit = checkDigit(password);
    int special = checkSpecialChar(password);

    printf("\n🛡️ Password Strength Evaluation 🛡️\n");
    printf("-------------------------------------------------\n");
    
    if (length) {
        printf("✅ Length: Good (8 or more characters)\n");
    } else {
        printf("❌ Length: Too short! (Minimum 8 characters required)\n");
    }

    if (upper) {
        printf("✅ Uppercase: Present 👍\n");
    } else {
        printf("❌ Uppercase: Missing! (Use at least one uppercase letter)\n");
    }

    if (lower) {
        printf("✅ Lowercase: Present 👍\n");
    } else {
        printf("❌ Lowercase: Missing! (Use at least one lowercase letter)\n");
    }

    if (digit) {
        printf("✅ Digit: Present 👍\n");
    } else {
        printf("❌ Digit: Missing! (Use at least one digit)\n");
    }

    if (special) {
        printf("✅ Special Character: Present 👍\n");
    } else {
        printf("❌ Special Character: Missing! (Use at least one special character)\n");
    }

    printf("-------------------------------------------------\n");
    
    int strengthScore = length + upper + lower + digit + special;
    if (strengthScore == 5) {
        printf("🌟 Your password is: STRONG! 🌟\n");
    } else if (strengthScore >= 3) {
        printf("👍 Your password is: MODERATE 👍\n");
    } else {
        printf("🚨 Your password is: WEAK! 🚨\n");
    }
    
    printf("\nThank you for using the Ultimate Password Strength Checker! Stay secure! 🔒✨\n");
}