//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int count_chars(const char *str, char c) {
    int count = 0;
    for (size_t i = 0; str[i]; i++) {
        if (tolower(str[i]) == tolower(c)) {
            count++;
        }
    }
    return count;
}

double entropy(const char *str, size_t length) {
    double entropy = 0.0;
    int total_count = 0;

    for (char c = 'a'; c <= 'z'; c++) {
        int count = count_chars(str, c);
        if (count > 0) {
            double prob = (double)count / length;
            entropy += prob * log2(prob);
            total_count += count;
        }
    }

    // Account for non-alphabetic characters
    for (size_t i = 0; str[i]; i++) {
        if (!isalpha(tolower(str[i]))) {
            int count = 1;
            entropy += log2((double)length / total_count) * count;
        }
    }

    return entropy;
}

int main() {
    char password[1024];
    size_t length;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    length = strlen(password);

    // Remove newline character
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
        length--;
    }

    double entropy_score = entropy(password, length);
    double strength_score = pow(2.0, entropy_score);

    printf("Password Strength Score: %.2f\n", strength_score);

    if (strength_score < 10000.0) {
        printf("Weak password\n");
    } else if (strength_score < 100000.0) {
        printf("Moderate password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}