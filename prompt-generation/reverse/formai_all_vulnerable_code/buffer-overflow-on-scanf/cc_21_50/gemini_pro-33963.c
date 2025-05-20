//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWD_LEN 256

int main() {
    char passwd[PASSWD_LEN];
    int strength = 0;
    int i;

    printf("Greetings, traveler! Welcome to the Galactic Password Strength Analyzer.\n");
    printf("Please enter your password: ");
    scanf("%s", passwd);

    // Check password length
    if (strlen(passwd) < 10) {
        printf("Your password is too short. It must be at least 10 characters long.\n");
    } else {
        strength++;
    }

    // Check for uppercase letters
    for (i = 0; i < strlen(passwd); i++) {
        if (passwd[i] >= 'A' && passwd[i] <= 'Z') {
            strength++;
            break;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < strlen(passwd); i++) {
        if (passwd[i] >= 'a' && passwd[i] <= 'z') {
            strength++;
            break;
        }
    }

    // Check for digits
    for (i = 0; i < strlen(passwd); i++) {
        if (passwd[i] >= '0' && passwd[i] <= '9') {
            strength++;
            break;
        }
    }

    // Check for special characters
    for (i = 0; i < strlen(passwd); i++) {
        if (passwd[i] == '!' || passwd[i] == '@' || passwd[i] == '#' || passwd[i] == '$' || passwd[i] == '%') {
            strength++;
            break;
        }
    }

    // Check for repeated characters
    for (i = 0; i < strlen(passwd); i++) {
        for (int j = i + 1; j < strlen(passwd); j++) {
            if (passwd[i] == passwd[j]) {
                strength--;
                break;
            }
        }
    }

    // Calculate the final password strength
    if (strength <= 2) {
        printf("Your password is weak. Please choose a stronger password.\n");
    } else if (strength == 3) {
        printf("Your password is moderate. It could be stronger.\n");
    } else if (strength == 4) {
        printf("Your password is strong. Good job!\n");
    } else if (strength == 5) {
        printf("Your password is excellent. You are a cyber security master!\n");
    }

    return 0;
}