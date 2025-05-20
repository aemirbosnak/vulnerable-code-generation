//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STRONG 3
#define MEDIUM 2
#define WEAK 1

int get_password_strength(char *password) {
    int password_length = strlen(password), score = 0;
    if (password_length < 8) { // Weak Password
        return WEAK;
    }
    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            score++;
            break;
        }
    }
    for (int i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            score++;
            break;
        }
    }
    for (int i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            score++;
            break;
        }
    }
    for (int i = 0; i < password_length; i++) {
        if (ispunct(password[i]) || isspace(password[i])) {
            score++;
            break;
        }
    }
    if (score == 4) { // Strong Password
        return STRONG;
    }
    if (score == 3) { // Medium Password
        return MEDIUM;
    }
    return WEAK; // Weak Password
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = get_password_strength(password);
    if (strength == STRONG) {
        printf("Your password is strong!\n");
    } else if (strength == MEDIUM) {
        printf("Your password is medium!\n");
    } else {
        printf("Your password is weak!\n");
    }
    return 0;
}