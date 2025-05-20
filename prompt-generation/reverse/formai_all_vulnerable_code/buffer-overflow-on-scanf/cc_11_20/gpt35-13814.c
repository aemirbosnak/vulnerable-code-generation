//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: surrealist
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Set up the surreal environment
    printf("Welcome to the Password Strength Checker!\n");
    printf("Please enter your desired password and let the surrealism begin...\n\n");

    char password[50];
    int i, len;
    bool has_upper = false, has_lower = false, has_digit = false, has_special = false;
    float score = 0;
    
    // Get user input
    scanf("%s", &password);
    len = strlen(password);

    // Check for password strength
    for (i = 0; i < len; i++) {
        char c = password[i];
        
        // Analyze each character
        if (isupper(c)) {
            has_upper = true;
            score += 2.5;
            printf("*A floating uppercase letter joins the flow*\n");
        } else if (islower(c)) {
            has_lower = true;
            score += 2.5;
            printf("*A creeping lowercase letter sneaks in*\n");
        } else if (isdigit(c)) {
            has_digit = true;
            score += 2.5;
            printf("*A digital number pokes through the void*\n");
        } else {
            has_special = true;
            score += 5;
            printf("*A mystical special character appears out of nowhere*\n");
        }
    }

    // Generate output based on password strength
    if (len <= 8 || score < 15 || (!has_upper && !has_lower && !has_digit && !has_special)) {
        printf("\n*The password didn't make it through the surreal strength test*\n");
        printf("*The password couldn't stand the strangeness of the surreal world*\n");
        printf("*The password disappears into the void, never to be seen again*\n");
    } else if (score >= 20 && has_upper && has_lower && has_digit && has_special) {
        printf("\n*The password is strong and eccentric*\n");
        printf("*The password survived the chaotic surreal environment*\n");
        printf("*The password is accepted and allowed into the surreal world*\n");
    } else {
        printf("\n*The password is somewhat surreal*\n");
        printf("*The password blends in with the absurdity of the surrealism*\n");
        printf("*The password is accepted, but must navigate its way through the surreal world*\n");
    }

    return 0;
}