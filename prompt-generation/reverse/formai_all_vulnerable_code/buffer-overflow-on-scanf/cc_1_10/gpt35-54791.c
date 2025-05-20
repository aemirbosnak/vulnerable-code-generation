//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password strength
int password_strength(char* password)
{
    int len = strlen(password);
    int score = 0;

    // Weak passwords
    if (len < 8) {
        printf("Strength: WEAK!\n");
        return 1;
    }

    // Calculate password strength
    for (int i = 0; i < len; i++) {
        // Check for upper case letters
        if (isupper(password[i])) {
            score += 2;
        }
        // Check for lower case letters
        if (islower(password[i])) {
            score += 2;
        }
        // Check for digits
        if (isdigit(password[i])) {
            score += 3;
        }
        // Check for special characters
        if (ispunct(password[i])) {
            score += 5;
        }
    }

    // Strength based on score
    if (score <= 10) {
        printf("Strength: WEAK!\n");
        return 1;
    }
    else if (score > 10 && score <= 20) {
        printf("Strength: MEDIUM!\n");
        return 2;
    }
    else if (score > 20 && score <= 30) {
        printf("Strength: STRONG!\n");
        return 3;
    }
    else {
        printf("Strength: SUPER STRONG!\n");
        return 4;
    }
}

int main()
{
    char password[20];
    printf("Enter password: ");
    scanf("%s", password);
    password_strength(password);
    return 0;
}