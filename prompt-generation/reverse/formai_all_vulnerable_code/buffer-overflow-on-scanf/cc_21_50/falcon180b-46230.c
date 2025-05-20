//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char password[50];
    int length, complexity = 0, uppercase = 0, lowercase = 0, numbers = 0, symbols = 0;
    float entropy = 0;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short. It should be at least 8 characters long.\n");
        return 0;
    }
    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                uppercase = 1;
            } else {
                lowercase = 1;
            }
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else {
            symbols = 1;
        }
    }
    if (uppercase && lowercase && numbers && symbols) {
        complexity += 4;
    } else if (uppercase && lowercase && numbers) {
        complexity += 3;
    } else if (uppercase && lowercase && symbols) {
        complexity += 3;
    } else if (uppercase && numbers && symbols) {
        complexity += 3;
    } else if (lowercase && numbers && symbols) {
        complexity += 3;
    } else if (uppercase && lowercase) {
        complexity += 2;
    } else if (uppercase && numbers) {
        complexity += 2;
    } else if (lowercase && numbers) {
        complexity += 2;
    } else if (uppercase && symbols) {
        complexity += 2;
    } else if (lowercase && symbols) {
        complexity += 2;
    } else if (numbers && symbols) {
        complexity += 2;
    } else {
        complexity = 1;
    }
    entropy = (float)log2(26 * 26 * 10 * (26 + 10)) / length;
    printf("Password strength: ");
    if (entropy >= 4.7) {
        printf("Very Strong\n");
    } else if (entropy >= 3.7) {
        printf("Strong\n");
    } else if (entropy >= 2.7) {
        printf("Moderate\n");
    } else if (entropy >= 1.7) {
        printf("Weak\n");
    } else {
        printf("Very Weak\n");
    }
    return 0;
}