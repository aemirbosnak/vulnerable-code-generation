//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char password[100];
    int length, score = 0;
    bool uppercase = false, lowercase = false, numeric = false, special = false;

    printf("Enter the password:\n");
    scanf("%s", password);

    length = strlen(password);

    if (length <= 6) {
        printf("Password is too short\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase = true;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase = true;
        } else if (password[i] >= '0' && password[i] <= '9') {
            numeric = true;
        } else {
            special = true;
        }
    }

    if (uppercase) {
        score++;
    }
    if (lowercase) {
        score++;
    }
    if (numeric) {
        score++;
    }
    if (special) {
        score++;
    }

    printf("Password strength: ");

    switch (score) {
        case 0: printf("Weak\n"); break;
        case 1: printf("Moderate\n"); break;
        case 2: printf("Good\n"); break;
        case 3: printf("Strong\n"); break;
        case 4: printf("Very Strong\n"); break;
        default: printf("Error: Invalid Score\n"); break;
    }

    return 0;
}