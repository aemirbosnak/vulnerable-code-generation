//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void toLowerCase(char *str);
void removeNonAlphanumeric(char *str);
int isPalindrome(char *str);

int main() {
    char input[256]; // Buffer to hold user input
    char cleanedInput[256]; // Buffer to hold cleaned input for palindrome check
    char playAgain;

    printf("Welcome to the Palindrome Checker!\n");

    do {
        // Get user input
        printf("Please enter a phrase or word to check if it is a palindrome: ");
        fgets(input, sizeof(input), stdin);

        // Remove trailing newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // Processing the string: convert to lower case and remove non-alphanumeric characters
        strcpy(cleanedInput, input); // Copy original input to cleanedInput
        toLowerCase(cleanedInput); // Convert to lower case
        removeNonAlphanumeric(cleanedInput); // Remove non-alphanumeric characters

        // Check if the cleaned string is a palindrome
        if (isPalindrome(cleanedInput)) {
            printf("\"%s\" is a palindrome!\n", input);
        } else {
            printf("\"%s\" is not a palindrome.\n", input);
        }

        // Prompt to check another phrase
        printf("Do you want to check another phrase? (y/n): ");
        scanf(" %c", &playAgain);
        getchar(); // Consume the newline character left by scanf

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for using the Palindrome Checker. Goodbye!\n");
    return 0;
}

// Function to convert string to lowercase
void toLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char) *str);
        str++;
    }
}

// Function to remove non-alphanumeric characters from the string
void removeNonAlphanumeric(char *str) {
    char temp[256];
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char) str[i])) {
            temp[index++] = str[i]; // Store the alphanumeric character
        }
    }
    temp[index] = '\0'; // Null-terminate the cleaned string
    strcpy(str, temp); // Copy cleaned data back to the original string
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Is a palindrome
}