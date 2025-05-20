//MISTRAL-7B DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define NUM_RULES 10

// Rules for romantic spam detection
const char *romantic_rules[NUM_RULES] = {
    "love you",
    "i miss you",
    "be mine",
    "forever and always",
    "my sweet",
    "my darling",
    "i need you",
    "i want you",
    "you are mine",
    "i will always love you"
};

// Function to check if a given string is a palindrome
int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return 0;
        }
    }
    return 1;
}

// Function to detect romantic spam
int detect_romantic_spam(const char *message) {
    int num_romantic_terms = 0;
    for (int i = 0; i < NUM_RULES; ++i) {
        size_t rule_len = strlen(romantic_rules[i]);
        size_t pos = strstr(message, romantic_rules[i]) - message;
        if (pos > 0 && (message[pos - 1] == ' ' || message[pos - 1] == '\n')) {
            ++num_romantic_terms;
        }
    }

    // Check for palindrome message
    if (is_palindrome(message)) {
        ++num_romantic_terms;
    }

    return num_romantic_terms > 3;
}

int main() {
    char line[MAX_LINE_LEN];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        if (detect_romantic_spam(line)) {
            printf("This message is a romantic spam!\n");
            puts(line);
        }
    }

    return 0;
}