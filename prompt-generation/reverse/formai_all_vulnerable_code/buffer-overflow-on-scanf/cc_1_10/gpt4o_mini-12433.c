//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

void to_lowercase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void clean_string(const char *input, char *output) {
    while (*input) {
        if (isalnum(*input)) {
            *output = *input;
            output++;
        }
        input++;
    }
    *output = '\0';  // Null-terminate the cleaned string
}

int is_palindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}

int main() {
    char input[MAX_LEN];
    char cleaned_input[MAX_LEN];

    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a phrase (max %d characters): ", MAX_LEN - 1);
    fgets(input, sizeof(input), stdin);

    // Remove the newline character that fgets adds
    input[strcspn(input, "\n")] = '\0';

    // Clean the input string
    clean_string(input, cleaned_input);
    to_lowercase(cleaned_input);

    printf("You entered: \"%s\"\n", input);
    printf("Cleaned and lowercased: \"%s\"\n", cleaned_input);

    if (is_palindrome(cleaned_input)) {
        printf("Congratulations! The given phrase is a palindrome.\n");
    } else {
        printf("Alas! The given phrase is not a palindrome.\n");
    }

    // Offer to check another phrase
    char choice;
    do {
        printf("Would you like to check another phrase? (y/n): ");
        scanf(" %c", &choice);
        choice = tolower(choice);

        if (choice == 'y') {
            // Repeat the input and checking process
            printf("Please enter a new phrase: ");
            getchar(); // To consume the newline from previous input
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0'; // Remove newline
            
            clean_string(input, cleaned_input);
            to_lowercase(cleaned_input);

            printf("You entered: \"%s\"\n", input);
            printf("Cleaned and lowercased: \"%s\"\n", cleaned_input);

            if (is_palindrome(cleaned_input)) {
                printf("Congratulations! The given phrase is a palindrome.\n");
            } else {
                printf("Alas! The given phrase is not a palindrome.\n");
            }
        }
    } while (choice == 'y');

    printf("Thank you for using the Palindrome Checker! Goodbye!\n");

    return 0;
}