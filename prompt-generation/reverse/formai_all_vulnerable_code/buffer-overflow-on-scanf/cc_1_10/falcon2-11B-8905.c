//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>

void checkPasswordStrength(char password[], int len) {
    // Check if password is at least 8 characters long
    if (len < 8) {
        printf("Weak: Password must be at least 8 characters long.\n");
        return;
    }

    // Check if password contains at least one uppercase letter
    char uppercase = 'A';
    for (int i = 0; i < len; i++) {
        if (uppercase == password[i] && uppercase >= 'A' && uppercase <= 'Z') {
            printf("Strong: Password contains at least one uppercase letter.\n");
            return;
        }
    }
    printf("Weak: Password must contain at least one uppercase letter.\n");
    return;

    // Check if password contains at least one lowercase letter
    char lowercase = 'a';
    for (int i = 0; i < len; i++) {
        if (lowercase == password[i] && lowercase >= 'a' && lowercase <= 'z') {
            printf("Strong: Password contains at least one lowercase letter.\n");
            return;
        }
    }
    printf("Weak: Password must contain at least one lowercase letter.\n");
    return;

    // Check if password contains at least one number
    for (int i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            printf("Strong: Password contains at least one number.\n");
            return;
        }
    }
    printf("Weak: Password must contain at least one number.\n");
    return;

    // Check if password contains at least one special character
    char special = '!';
    for (int i = 0; i < len; i++) {
        if (special == password[i] && special >= '!' && special <= '~') {
            printf("Strong: Password contains at least one special character.\n");
            return;
        }
    }
    printf("Weak: Password must contain at least one special character.\n");
    return;
}

int main() {
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);
    int len = strlen(password);

    checkPasswordStrength(password, len);

    return 0;
}