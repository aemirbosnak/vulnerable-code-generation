//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    int length, score = 0;
    printf("Enter password: ");
    scanf("%s", password);

    // Minimum length check
    length = strlen(password);
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check if password contains uppercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            score += 5;
            break;
        }
    }

    // Check if password contains lowercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            score += 5;
            break;
        }
    }

    // Check if password contains numbers
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            score += 5;
            break;
        }
    }

    // Check if password contains special characters
    for (int i = 0; i < length; i++) {
        if (!((password[i] >= '0' && password[i] <= '9') || 
              (password[i] >= 'A' && password[i] <= 'Z') || 
              (password[i] >= 'a' && password[i] <= 'z'))) {
            score += 5;
            break;
        }
    }

    // Print Password strength and score
    if (score < 20) {
        printf("Weak password\n");
    } else if (score < 30) {
        printf("Moderate password\n");
    } else if (score < 40) {
        printf("Strong password\n");
    } else {
        printf("Very strong password\n");
    }
    printf("Password score: %d\n", score);
    return 0;
}