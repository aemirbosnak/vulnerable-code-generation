//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {

    char password[30];
    int length, digit = 0, lowercase = 0, uppercase = 0, symbol = 0, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Calculating password strength based on length
    if (length < 5) {
        printf("Password is too short! Minimum 5 characters needed.\n");
    } else if (length >= 5 && length <= 7) {
        printf("Weak password!\n");
        score += 10;
    } else if (length >= 8 && length <= 10) {
        printf("Medium strength password.\n");
        score += 20;
    } else if (length > 10) {
        printf("Strong password!\n");
        score += 30;
    }

    // Checking for digits, lowercase, uppercase, and symbol characters
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit++;
        } else if (islower(password[i])) {
            lowercase++;
        } else if (isupper(password[i])) {
            uppercase++;
        } else {
            symbol++;
        }
    }

    // Updating password score based on characters present
    if (digit > 0) {
        score += 10;
    } 
    
    if (lowercase > 0) {
        score += 10;
    }
    
    if (uppercase > 0) {
        score += 10;
    }

    if (symbol > 0) {
        score += 10;
    }

    // Final password score and recommendation
    printf("\nPassword score: %d\n", score);

    if (score < 20) {
        printf("Your password is very weak! Please select a stronger password.\n");
    } else if (score >= 20 && score < 30) {
        printf("Your password is weak! Consider a stronger password.\n");
    } else if (score >= 30 && score < 40) {
        printf("Your password is good! Keep it up.\n");
    } else if (score >= 40 && score < 50) {
        printf("Your password is very good! Well done.\n");
    } else {
        printf("Your password is excellent! Keep up the good work.\n");
    }

    return 0;
}