//Falcon-180B DATASET v1.0 Category: Palindrome Checker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
    // Convert string to lowercase and remove non-alphabetic characters
    char *cleaned_str = (char *)malloc(strlen(str) + 1);
    int i = 0;
    for (int j = 0; j < strlen(str); j++) {
        if (isalpha(str[j])) {
            cleaned_str[i] = tolower(str[j]);
            i++;
        }
    }
    cleaned_str[i] = '\0';

    // Compare cleaned string with its reverse
    int is_pal = 1;
    for (int j = 0; j < strlen(cleaned_str) / 2; j++) {
        if (cleaned_str[j]!= cleaned_str[strlen(cleaned_str) - j - 1]) {
            is_pal = 0;
            break;
        }
    }

    // Free memory and return result
    free(cleaned_str);
    return is_pal;
}

int main() {
    // Prompt user for input
    printf("Enter a string to check if it's a palindrome: ");
    char input[1000];
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Check if input is a palindrome
    int is_palindrome_result = is_palindrome(input);

    // Print result
    if (is_palindrome_result) {
        printf("'%s' is a palindrome.\n", input);
    } else {
        printf("'%s' is not a palindrome.\n", input);
    }

    return 0;
}