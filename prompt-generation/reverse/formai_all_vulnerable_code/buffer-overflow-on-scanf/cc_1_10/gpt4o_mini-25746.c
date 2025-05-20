//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to clean and prepare the input string
void cleanString(char *input, char *cleaned) {
    int j = 0;
    for (int i = 0; input[i]; i++) {
        if (isalnum(input[i])) { // Only take alphanumeric characters
            cleaned[j++] = tolower(input[i]); // Convert to lowercase
        }
    }
    cleaned[j] = '\0'; // Null terminate the cleaned string
}

// Recursive function to check for palindrome
int isPalindromeRecursive(char *str, int start, int end) {
    if (start >= end) {
        return 1; // base case: when the pointers meet or cross
    }
    if (str[start] != str[end]) {
        return 0; // not a palindrome
    }
    return isPalindromeRecursive(str, start + 1, end - 1);
}

// Function to check if the input string is a palindrome
int isPalindrome(char *str) {
    int length = strlen(str);
    return isPalindromeRecursive(str, 0, length - 1);
}

// Function to display the result in a dramatic way
void displayResult(char *str, int result) {
    printf("\nYour input: \"%s\"\n", str);
    printf("After deep reflection and digital contemplation...\n");
    if (result) {
        printf("🎉 Surprise! It's a palindrome! 🎉\n");
    } else {
        printf("😱 Oh snap! It's not a palindrome! 😱\n");
    }
}

int main() {
    char input[256], cleaned[256];
    int again;

    printf("Welcome to the Surprising Palindrome Checker! 🎭\n");

    do {
        printf("\nPlease enter a phrase (up to 255 characters): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline character

        // Clean the input
        cleanString(input, cleaned);

        // Check for palindrome
        int result = isPalindrome(cleaned);
        
        // Display the result
        displayResult(input, result);

        printf("\nWould you like to check another phrase? (1 for Yes, 0 for No): ");
        scanf("%d", &again);
        getchar(); // To consume leftover newline

        if (again) {
            printf("\nLet's go again! 🌟\n");
        } else {
            printf("\nThank you for using the Surprising Palindrome Checker! Goodbye! 👋\n");
        }
    } while (again);

    return 0;
}