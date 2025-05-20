//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8    // Minimum password length
#define MAX_LENGTH 20   // Maximum password length

// Function to check password strength and return a score
int password_strength(char *password) {
    // Initialize variables
    int length = strlen(password);
    int score = 0;
    int uppercase = 0;
    int lowercase = 0;
    int digits = 0;
    int symbols = 0;
    int i;
    
    // Check password length
    if (length < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return 0;
    }
    
    if (length > MAX_LENGTH) {
        printf("Password cannot be longer than %d characters.\n", MAX_LENGTH);
        return 0;
    }
    
    // Count number of uppercase letters, lowercase letters, digits, and symbols
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        }
        else if (islower(password[i])) {
            lowercase++;
        }
        else if (isdigit(password[i])) {
            digits++;
        }
        else {
            symbols++;
        }
    }
    
    // Score password based on number of characters and character types
    if (length >= MIN_LENGTH && length <= 10) {
        score += length * 6;
    }
    else if (length > 10) {
        score += 60;
    }
    
    score += uppercase * 2;
    score += lowercase * 2;
    score += digits * 3;
    score += symbols * 4;
    
    return score;
}

int main(void) {
    // Initialize variables
    char password[MAX_LENGTH + 1];
    int score;
    
    // Get password from user input
    printf("Enter password: ");
    scanf("%s", password);
    
    // Check password strength
    score = password_strength(password);
    if (score == 0) {
        return 0;
    }
    
    // Display password score
    printf("Password strength score: %d\n", score);
    
    return 0;
}