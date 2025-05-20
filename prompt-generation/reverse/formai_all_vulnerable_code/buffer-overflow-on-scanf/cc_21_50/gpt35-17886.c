//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>

// Function to check password strength
int checkPasswordStrength(char* password)
{
    int len = strlen(password);

    // Password length check
    if (len < 8) {
        return 0; // Weak Password
    } 

    int lowerCase = 0, upperCase = 0, digits = 0, specialCharacters = 0;

    for(int i = 0; i < len; i++) {
        char ch = password[i];

        if((ch >= 'a' && ch <= 'z')) {
            lowerCase++;
        }
        else if((ch >= 'A' && ch <= 'Z')) {
            upperCase++;
        }
        else if(ch >= '0' && ch <= '9') {
            digits++;
        }
        else {
            specialCharacters++;
        }
    }

    // Password strength check
    if (lowerCase && upperCase && digits && specialCharacters) {
        return 3; // Strong Password (Lowercase, Uppercase, Digits, Special Characters)
    } else if ((lowerCase && upperCase && digits) || (lowerCase && upperCase && specialCharacters) || (upperCase && digits && specialCharacters) || (lowerCase && digits && specialCharacters)) {
        return 2; // Moderate Password (Three of Combination of - Lowecase, Uppercase, Digits, Special Characters)
    } else if ((lowerCase && upperCase) || (lowerCase && digits) || (lowerCase && specialCharacters) || (upperCase && digits) || (upperCase && specialCharacters) || (digits && specialCharacters)) {
        return 1; // Weak Password (Two of Combination of - Lowecase, Uppercase, Digits, Special Characters)
    } else {
        return 0; // Very Weak Password (Only one or none of Combination of - Lowecase, Uppercase, Digits, Special Characters)
    }
}

int main() {
    char password[50];
    printf("Enter password to check strength: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    // Output the Strength of Password
    switch(strength) {
        case 0:
            printf("Very Weak Password");
            break;
        case 1:
            printf("Weak Password");
            break;
        case 2:
            printf("Moderate Password");
            break;
        case 3:
            printf("Strong Password");
            break;
        default:
            printf("Invalid Input");
    }

    return 0;
}