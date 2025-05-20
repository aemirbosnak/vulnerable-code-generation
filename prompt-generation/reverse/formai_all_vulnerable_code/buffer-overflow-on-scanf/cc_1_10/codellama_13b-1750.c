//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store password details
struct Password {
    char password[20];
    int length;
    int uppercase;
    int lowercase;
    int numbers;
    int symbols;
};

// Function to check password strength
int check_password_strength(struct Password p) {
    int score = 0;
    if (p.length >= 8) {
        score += 1;
    }
    if (p.uppercase >= 1) {
        score += 1;
    }
    if (p.lowercase >= 1) {
        score += 1;
    }
    if (p.numbers >= 1) {
        score += 1;
    }
    if (p.symbols >= 1) {
        score += 1;
    }
    return score;
}

// Main function
int main() {
    struct Password p;
    printf("Enter a password: ");
    scanf("%s", p.password);
    p.length = strlen(p.password);
    p.uppercase = 0;
    p.lowercase = 0;
    p.numbers = 0;
    p.symbols = 0;
    for (int i = 0; i < p.length; i++) {
        if (p.password[i] >= 'A' && p.password[i] <= 'Z') {
            p.uppercase += 1;
        } else if (p.password[i] >= 'a' && p.password[i] <= 'z') {
            p.lowercase += 1;
        } else if (p.password[i] >= '0' && p.password[i] <= '9') {
            p.numbers += 1;
        } else {
            p.symbols += 1;
        }
    }
    printf("Password Strength: %d\n", check_password_strength(p));
    return 0;
}