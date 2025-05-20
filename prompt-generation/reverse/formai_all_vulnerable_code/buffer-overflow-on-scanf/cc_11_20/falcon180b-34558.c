//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    char password[100];
    int length, i, j, score = 0;
    float entropy = 0.0;
    time_t now = time(NULL);
    srand(now);

    // Prompt user for password
    printf("Enter password: ");
    scanf("%s", password);

    // Check length of password
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short. Must be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            score++;
        }
    }

    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            score++;
        }
    }

    // Check for numbers
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            score++;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            score++;
        }
    }

    // Calculate entropy
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            if (password[i] == password[j]) {
                entropy += log2(entropy + 1.0);
            }
        }
    }

    printf("Password strength: ");
    if (score < 4) {
        printf("Weak\n");
    } else if (score < 8) {
        printf("Moderate\n");
    } else {
        printf("Strong\n");
    }

    printf("Entropy: %f\n", entropy);

    return 0;
}