//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define ALPHABET_SIZE 26
#define LOG_2_E 1.44269504088896340736

int get_letter_probability(char c, const char *password) {
    int count = 0;
    int length = strlen(password);

    for (int i = 0; i < length; ++i) {
        if (password[i] == c) {
            ++count;
        }
    }

    return (double) count / length;
}

int password_entropy(const char *password) {
    int entropy = 0;
    int length = strlen(password);

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        double probability = get_letter_probability((char) ('a' + i), password);
        entropy += probability * log2(probability);
    }

    for (int i = 0; i < length; ++i) {
        char c = password[i];
        if (isalpha(c)) {
            double probability = get_letter_probability(c, password);
            entropy += probability * log2(probability);
        }
    }

    return entropy * LOG_2_E;
}

int main() {
    char password[MIN_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);

    if (length < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return 1;
    }

    int entropy = password_entropy(password);
    double strength = (double) entropy / (MIN_LENGTH * log2(ALPHABET_SIZE));

    printf("Password strength: %.2f%%\n", strength * 100.0);

    return 0;
}