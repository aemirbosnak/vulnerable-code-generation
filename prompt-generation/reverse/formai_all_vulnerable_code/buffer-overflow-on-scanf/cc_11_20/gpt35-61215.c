//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 16

int main(void) {
    char password[PASSWORD_LENGTH];
    int lowercase = 0, uppercase = 0, digits = 0, special_chars = 0;
    int strength_score = 0;
    
    printf("Enter your password: ");
    scanf("%s", password);
    
    if (strlen(password) < 8) {
        printf("Your password is too short. It must be at least 8 characters long.\n");
        exit(0);
    }
    
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];
        
        if (islower(c))
            lowercase++;
        else if (isupper(c))
            uppercase++;
        else if (isdigit(c))
            digits++;
        else
            special_chars++;
    }
    
    if (lowercase > 0)
        strength_score++;
    if (uppercase > 0)
        strength_score++;
    if (digits > 0)
        strength_score++;
    if (special_chars > 0)
        strength_score++;
    
    if (strength_score <= 2) {
        printf("Your password is weak. It must contain at least three of the following: lowercase letters, uppercase letters, digits, and special characters.\n");
    } else if (strength_score <= 3) {
        printf("Your password is moderate. Consider using a mix of uppercase and lowercase letters, digits, and special characters.\n");
    } else {
        printf("Your password is strong! Great job!\n");
    }
    
    return 0;
}