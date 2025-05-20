//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    printf("> Enter Password: ");
    
    char password[50];
    fgets(password, sizeof(password), stdin);
    password[strlen(password) - 1] = '\0'; // replace trailing newline with null
    
    int length = strlen(password);
    int score = 0;
    
    // check length
    if (length < 5) {
        printf("Password too short! Please use at least 5 characters.\n");
        exit(0);
    } else if (length > 20) {
        printf("Password too long! Please use no more than 20 characters.\n");
        exit(0);
    } else {
        score += length * 4;
    }
    
    // check lowercase letters
    int lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase++;
        }
    }
    if (lowercase > 0) {
        score += (length - lowercase) * 2;
    } else {
        printf("Password must contain at least one lowercase letter.\n");
        exit(0);
    }
    
    // check uppercase letters
    int uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase++;
        }
    }
    if (uppercase > 0) {
        score += (length - uppercase) * 2;
    } else {
        printf("Password must contain at least one uppercase letter.\n");
        exit(0);
    }
    
    // check digits
    int digits = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digits++;
        }
    }
    if (digits > 0) {
        score += digits * 4;
    } else {
        printf("Password must contain at least one digit.\n");
        exit(0);
    }
    
    // check special characters
    int special = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special++;
        }
    }
    if (special > 0) {
        score += special * 6;
    } else {
        printf("Password must contain at least one special character.\n");
        exit(0);
    }
    
    // check repeated characters
    int sequence = 0;
    for (int i = 0; i < length; i++) {
        int j = i + 1, count = 1;
        while (j < length && password[i] == password[j]) {
            count++;
            j++;
        }
        if (count > 1) {
            sequence += count;
            i = j - 1;
        }
    }
    score -= sequence * 2;
    
    // print results
    printf("Password strength score: %d\n", score);
    
    if (score >= 80) {
        printf("Strong password!\n");
    } else if (score >= 50) {
        printf("Moderate password.\n");
    } else {
        printf("Weak password! Please choose a stronger password.\n");
    }
    
    return 0;
}