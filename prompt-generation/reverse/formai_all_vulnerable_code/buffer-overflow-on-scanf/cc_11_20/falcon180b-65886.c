//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length, i, score = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    // Check for special characters
    if (strpbrk(password, "!@#$%^&*()_+-=[]{}|;:,.<>?")) {
        score += 1;
    }

    // Check for uppercase letters
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        score += 1;
    }

    // Check for lowercase letters
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
        score += 1;
    }

    // Check for numbers
    if (strpbrk(password, "0123456789")) {
        score += 1;
    }

    // Check for length
    if (length >= 8) {
        score += 1;
    }

    switch (score) {
        case 0:
            printf("My dear Watson, your password is extremely weak.\n");
            break;
        case 1:
            printf("A singularly weak password, Watson.\n");
            break;
        case 2:
            printf("Somewhat better, but still quite weak, Watson.\n");
            break;
        case 3:
            printf("A fair effort, Watson, but there's room for improvement.\n");
            break;
        case 4:
            printf("Well done, Watson! Your password is reasonably strong.\n");
            break;
        case 5:
            printf("Excellent work, Watson! Your password is very strong indeed.\n");
            break;
    }

    return 0;
}