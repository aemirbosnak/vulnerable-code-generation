//GPT-4o-mini DATASET v1.0 Category: Palindrome Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to clean the string: remove non-alphanumeric characters and convert to lowercase
void cleanString(const char *input, char *cleaned) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        // Check if character is alphanumeric
        if (isalnum(input[i])) {
            cleaned[j++] = tolower(input[i]); // Convert and store
        }
    }
    cleaned[j] = '\0'; // Null-terminate the cleaned string
}

// Function to check if the string is a palindrome
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

// Main function to drive the palindrome checker
int main() {
    char input[256]; // To hold the user input
    char cleaned[256]; // To hold the cleaned string

    printf("Welcome to the Palindrome Checker!\n");
    printf("Please enter a string to check if it's a palindrome:\n");
    fgets(input, sizeof(input), stdin); // Read user input

    // Clean the input string
    cleanString(input, cleaned);
    
    // Check for palindrome and respond accordingly
    if (isPalindrome(cleaned)) {
        printf("Congratulations! '%s' is a palindrome.\n", cleaned);
    } else {
        printf("Oops! '%s' is not a palindrome.\n", cleaned);
    }

    // Bonus: Provide an option for another check
    char choice;
    printf("Do you want to check another string? (y/n): ");
    scanf(" %c", &choice); // Note the space before %c to consume any leftover newline

    while (choice == 'y' || choice == 'Y') {
        printf("Please enter another string to check:\n");
        getchar(); // Consume the newline left by scanf
        fgets(input, sizeof(input), stdin); // Read user input
        cleanString(input, cleaned);
        
        if (isPalindrome(cleaned)) {
            printf("Congratulations! '%s' is a palindrome.\n", cleaned);
        } else {
            printf("Oops! '%s' is not a palindrome.\n", cleaned);
        }
        
        printf("Do you want to check another string? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Palindrome Checker! Have a great day!\n");
    return 0;
}