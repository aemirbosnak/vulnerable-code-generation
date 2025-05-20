//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Romeo and Juliet
/**
 *  Forsooth! Behold the Password Strength Checker!
 * 
 *  A program of great import designed to check
 *  the hardiness of a password entered by ye.
 * 
 *  Refer to yond password tips below for best results.
 * 
 *  Happy coding fair users!
 * 
 *  Written by thy humble servant,
 *  The Password Strength Checker
 */

#include <stdio.h>
#include <string.h>

// Length constants
#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Score constants
#define WEAK_SCORE 10
#define MODERATE_SCORE 25
#define STRONG_SCORE 40

// Character types constants
#define LOWERCASE_CHAR 1
#define UPPERCASE_CHAR 2
#define NUMBER_CHAR 4
#define SPECIAL_CHAR 8

// Password tips
const char* tips[] = {
    " - Passwords should be at least 8 characters long.",
    " - Passwords should not exceed 64 characters in length.",
    " - Passwords should contain a mix of uppercase and lowercase letters.",
    " - Passwords should contain at least one number.",
    " - Passwords should contain at least one special character such as @, #, $."
};

// Password strength function
int check_password_strength(char* password) {
    int score = 0;
    int length = strlen(password);
    int char_types = 0;
    int i;
    
    // Check length is within range
    if (length < MIN_LENGTH) {
        score += WEAK_SCORE;
    } else if (length > MAX_LENGTH) {
        score += STRONG_SCORE;
    } else {
        score += MODERATE_SCORE;
    }
    
    // Check character types are present
    for (i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            char_types |= LOWERCASE_CHAR;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            char_types |= UPPERCASE_CHAR;
        } else if (password[i] >= '0' && password[i] <= '9') {
            char_types |= NUMBER_CHAR;
        } else {
            char_types |= SPECIAL_CHAR;
        }
    }
    if ((char_types & LOWERCASE_CHAR) && (char_types & UPPERCASE_CHAR)) {
        score += MODERATE_SCORE;
    }
    if (char_types & NUMBER_CHAR) {
        score += MODERATE_SCORE;
    }
    if (char_types & SPECIAL_CHAR) {
        score += MODERATE_SCORE;
    }
    
    return score;
}

// Main function
int main() {
    char password[MAX_LENGTH];
    int score;
    int i;
    
    // Prompt user for password
    printf("Good morrow! What ho! Enter thy password: ");
    scanf("%s", password);
    printf("\n");
    
    // Check password strength and print results
    score = check_password_strength(password);
    printf("Password tips for thee:\n");
    for (i = 0; i < 5; i++) {
        printf("%s\n", tips[i]);
    }
    printf("\n");
    printf("Thy password score is: %d\n", score);
    printf("\n");
    printf("Fare thee well!\n");
    
    return 0;
}