//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MIN_LEN 12
#define MAX_LEN 20

void generate_password(char *password, int len) {
    int i;
    char ch;
    if (len < MIN_LEN || len > MAX_LEN) {
        printf("Invalid length. Password length must be between %d and %d.\n", MIN_LEN, MAX_LEN);
        return;
    }

    srand(time(NULL));
    for (i = 0; i < len; i++) {
        ch = rand() % 33 + '!'; // Generate random character from ! to ~
        if (i < len / 2)
            password[i] = ch; // First half of password is random
        else {
            switch (rand() % 3) {
                case 0:
                    password[i] = getchar(); // Get a character from keyboard
                    if (isalnum(password[i]))
                        continue; // Reject non-alphanumeric keyboard input
                    putchar('\b'); // Backspace to hide character from user
                    break;
                case 1:
                    password[i] = rand() % 26 + 'a'; // Generate random lowercase letter
                    break;
                case 2:
                    password[i] = rand() % 26 + 'A'; // Generate random uppercase letter
                    break;
            }
        }
    }
    password[len] = '\0';
}

int check_password_strength(const char *password, int len) {
    int i, count_digits = 0, count_lower = 0, count_upper = 0, count_special = 0;

    for (i = 0; i < len; i++) {
        if (isdigit(password[i]))
            count_digits++;
        else if (islower(password[i]))
            count_lower++;
        else if (isupper(password[i]))
            count_upper++;
        else if (strchr("!@#$%^&*()-_+={}[]|\\:;\"'<>,.?/~`", password[i]))
            count_special++;
    }

    if (len < MIN_LEN)
        return 0; // Too short
    if (count_digits > 2)
        return 1; // Good
    if (count_lower > 2 && count_upper > 2 && count_special > 2)
        return 2; // Excellent
    return -1; // Unknown
}

int main() {
    char password[MAX_LEN + 1];
    int len, strength;

    printf("Enter password length (min %d, max %d): ", MIN_LEN, MAX_LEN);
    scanf("%d", &len);

    generate_password(password, len);
    printf("Generated password: %s\n", password);

    strength = check_password_strength(password, len);
    switch (strength) {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Good\n");
            break;
        case 2:
            printf("Excellent\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    return 0;
}