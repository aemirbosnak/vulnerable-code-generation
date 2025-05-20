//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[101];
    int strength;

    printf("Enter a password: ");
    scanf("%s", password);

    strength = check_strength(password);

    printf("Password strength: ");
    switch (strength) {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Fair\n");
            break;
        case 2:
            printf("Good\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very strong\n");
            break;
    }

    return 0;
}

int check_strength(char *password) {
    int length, upper, lower, number, symbol;

    length = strlen(password);
    upper = lower = number = symbol = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            upper++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            number++;
        } else {
            symbol++;
        }
    }

    if (length < 8 || upper == 0 || lower == 0 || number == 0 || symbol == 0) {
        return 0;
    } else if (length < 12 || upper < 2 || lower < 2 || number < 2 || symbol < 2) {
        return 1;
    } else if (length < 16 || upper < 3 || lower < 3 || number < 3 || symbol < 3) {
        return 2;
    } else if (length < 20 || upper < 4 || lower < 4 || number < 4 || symbol < 4) {
        return 3;
    } else {
        return 4;
    }
}