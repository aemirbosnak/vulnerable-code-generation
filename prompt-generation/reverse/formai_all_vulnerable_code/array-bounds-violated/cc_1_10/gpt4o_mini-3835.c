//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to remove spaces and convert to lowercase
void sanitizeString(char *str, char *sanitized) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            sanitized[j++] = tolower(str[i]);
        }
    }
    sanitized[j] = '\0'; // Null-terminate the sanitized string
}

// Function to check if the string is a palindrome
int isPalindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main() {
    char input[256];
    char sanitized[256];

    printf("Enter a string to check if it's a palindrome:\n");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from fgets if present
    size_t ln = strlen(input) - 1;
    if (input[ln] == '\n') {
        input[ln] = '\0';
    }

    // Sanitize the input string
    sanitizeString(input, sanitized);

    printf("Sanitized string: \"%s\"\n", sanitized);

    // Check if it's a palindrome
    if (isPalindrome(sanitized)) {
        printf("The input string is a palindrome.\n");
    } else {
        printf("The input string is not a palindrome.\n");
    }

    return 0;
}