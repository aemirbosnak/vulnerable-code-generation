//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void toLowercase(char *str);
int isPalindrome(char *str);
void removeNonAlphanumeric(char *source, char *dest);

int main() {
    char input[256];  // Input string
    char cleanedInput[256];  // Store the cleaned input string
    char again;  // Variable to ask user if they want to check again

    // Welcome message
    printf("🎉🎉 Welcome to the C Palindrome Checker! 🎉🎉\n");
    
    do {
        printf("\n🌟 Please enter a string (up to 256 characters): ");
        fgets(input, sizeof(input), stdin);  // Safely get string input
        input[strcspn(input, "\n")] = '\0';  // Remove the newline character

        // Clean the input string
        removeNonAlphanumeric(input, cleanedInput);

        // Displaying the cleaned input
        printf("🪄 Cleaned Input: \"%s\"\n", cleanedInput);

        // Check if the cleaned input is a palindrome
        if (isPalindrome(cleanedInput)) {
            printf("🎊 Hooray! \"%s\" is a palindrome! 🎊\n", cleanedInput);
        } else {
            printf("💔 Oops! \"%s\" is not a palindrome. 💔\n", cleanedInput);
        }

        // Prompt to check another string
        printf("🤔 Would you like to check another string? (y/n): ");
        scanf(" %c", &again);  // Read user response
        getchar();  // To clear the newline character from input buffer

    } while (tolower(again) == 'y');  // Continue if user says 'y'

    // Goodbye message
    printf("👋 Thank you for using the C Palindrome Checker! Goodbye! 👋\n");
    return 0;
}

// Function to convert a string to lowercase
void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
    int left = 0; // Start from the left
    int right = strlen(str) - 1; // Start from the right

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

// Function to remove non-alphanumeric characters from a string
void removeNonAlphanumeric(char *source, char *dest) {
    int index = 0; // Index for dest
    for (int i = 0; source[i]; i++) {
        if (isalnum(source[i])) { // Check if character is alphanumeric
            dest[index++] = tolower(source[i]); // Append to dest
        }
    }
    dest[index] = '\0'; // Null-terminate cleaned string
}